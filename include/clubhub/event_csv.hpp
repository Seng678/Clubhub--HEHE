// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#pragma once

#include "clubhub/event.hpp"
#include <istream>
#include <string>
#include <vector>

namespace clubhub {

struct CsvError {
    int line;
    std::string message;
};

struct EventLoadResult {
    std::vector<Event> events;
    std::vector<CsvError> errors;
};

EventLoadResult loadEventsCsv(std::istream& in);

} // namespace clubhub
