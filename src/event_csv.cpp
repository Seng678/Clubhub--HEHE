// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#include "clubhub/event_csv.hpp"
#include <sstream>
#include <iostream>

namespace clubhub {

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    
    // Skip header line
    if (!std::getline(in, line)) {
        return result;
    }

    size_t line_num = 1;
    while (std::getline(in, line)) {
        line_num++;
        if (line.empty()) continue;
        
        std::istringstream ss(line);
        std::string id, title, start_str, location, capacity_str;
        
        if (std::getline(ss, id, ',') &&
            std::getline(ss, title, ',') &&
            std::getline(ss, start_str, ',') &&
            std::getline(ss, location, ',') &&
            std::getline(ss, capacity_str, ',')) {
            try {
                int cap = std::stoi(capacity_str);
                TimePoint tp = parseTimePoint(start_str);
                result.events.emplace_back(id, title, tp, location, cap);
            } catch (...) {
                result.errors.push_back({(int)line_num, "Failed to parse row"});
            }
        } else {
            result.errors.push_back({(int)line_num, "Malformed CSV row"});
        }
    }
    return result;
}

} // namespace clubhub
