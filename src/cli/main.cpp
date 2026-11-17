// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#include "clubhub/event_csv.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>

namespace {

bool compareEvents(const clubhub::Event& a, const clubhub::Event& b) {
    return a.start < b.start;
}

int listEvents(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }

    auto result = clubhub::loadEventsCsv(file);
    auto& events = result.events;
    auto& errors = result.errors;

    std::sort(events.begin(), events.end(), compareEvents);

    std::cout << "Successfully loaded " << events.size() << " events:\n";
    for (const auto& event : events) {
        std::cout << "- [" << event.id() << "] " << event.title() << " at " << event.location() << "\n";
    }

    if (!errors.empty()) {
        std::cerr << "Encountered " << errors.size() << " parsing errors:\n";
        for (const auto& err : errors) {
            std::cerr << "Line " << err.line << ": " << err.message << "\n";
        }
    }

    return errors.empty() ? 0 : 1;
}

} // namespace

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <events_csv_file>\n";
        return 1;
    }
    return listEvents(argv[1]);
}
