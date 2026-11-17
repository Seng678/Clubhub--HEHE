// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#pragma once

#include <string>
#include <memory>

namespace clubhub {

class Student {
public:
    Student(std::string id, std::string name);
    const std::string& id() const noexcept { return id_; }
    const std::string& name() const noexcept { return name_; }
private:
    std::string id_;
    std::string name_;
};

} // namespace clubhub
