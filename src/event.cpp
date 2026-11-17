// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#include "clubhub/event.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <ctime>
#include <cstdio>

namespace clubhub {

Event::Event(std::string id, std::string title, TimePoint start,
             std::string location, int capacity)
    : id_{std::move(id)}, title_{std::move(title)}, start_{start},
      location_{std::move(location)}, capacity_{capacity} {
    if (id_.empty() || title_.empty()) {
        throw std::invalid_argument("ID and title cannot be empty");
    }
    if (capacity_ <= 0) {
        throw std::invalid_argument("capacity must be positive");
    }
}

TimePoint parseTimePoint(const std::string& text) {
    std::istringstream in{text};
    int y{}, mo{}, d{}, h{}, mi{};
    char dash1{}, dash2{}, colon{};
    in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi;
    
    if (!in || dash1 != '-' || dash2 != '-' || colon != ':' ||
        mo < 1 || mo > 12 || d < 1 || d > 31 || h < 0 || h > 23 || mi < 0 || mi > 59) {
        throw std::invalid_argument{"bad date-time '" + text + "'"};
    }
    
    std::tm tm_data = {};
    tm_data.tm_year = y - 1900;
    tm_data.tm_mon = mo - 1;
    tm_data.tm_mday = d;
    tm_data.tm_hour = h;
    tm_data.tm_min = mi;
    tm_data.tm_sec = 0;
    tm_data.tm_isdst = -1;
    
    std::time_t tt = std::mktime(&tm_data);
    if (tt == (std::time_t)-1) {
        throw std::invalid_argument{"bad date-time '" + text + "'"};
    }
    
    return std::chrono::system_clock::from_time_t(tt);
}

std::string formatTimePoint(TimePoint t) {
    std::time_t tt = std::chrono::system_clock::to_time_t(t);
    std::tm* tm_ptr = std::localtime(&tt);
    if (!tm_ptr) {
        return "";
    }
    char buf[32];
    std::sprintf(buf, "%04d-%02d-%02d %02d:%02d",
                 tm_ptr->tm_year + 1900,
                 tm_ptr->tm_mon + 1,
                 tm_ptr->tm_mday,
                 tm_ptr->tm_hour,
                 tm_ptr->tm_min);
    return std::string(buf);
}

} // namespace clubhub