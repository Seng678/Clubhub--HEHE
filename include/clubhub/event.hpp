// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#pragma once
#include <chrono>
#include <string>

namespace clubhub {

using TimePoint = std::chrono::system_clock::time_point;

class Event {
public:
    Event(std::string id, std::string title, TimePoint start,
          std::string location, int capacity);

    const std::string& id() const noexcept { return id_; }
    const std::string& title() const noexcept { return title_; }
    TimePoint start() const noexcept { return start_; }
    const std::string& location() const noexcept { return location_; }
    int capacity() const noexcept { return capacity_; }

    bool hasStarted(TimePoint now) const noexcept { return start_ <= now; }

private:
    std::string id_;
    std::string title_;
    TimePoint start_;
    std::string location_;
    int capacity_;
};

TimePoint parseTimePoint(const std::string& text);
std::string formatTimePoint(TimePoint t);

} // namespace clubhub