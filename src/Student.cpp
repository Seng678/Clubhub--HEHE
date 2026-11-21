// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team HEHE, ITC Club Hub contributors
#include "clubhub/Student.h"

#include <cctype>
#include <stdexcept>
#include <utility>

namespace clubhub {

Student::Student(std::string id, std::string name, std::string email)
    : id_{std::move(id)}, name_{std::move(name)}, email_{std::move(email)} {
    if (id_.empty()) throw std::invalid_argument("Student id cannot be empty");
    if (name_.empty()) throw std::invalid_argument("Student name cannot be empty");
    if (email_.find('@') == std::string::npos) {
        throw std::invalid_argument("Student email must contain '@'");
    }
}

void Student::giveSmsConsent(std::string phone) {
    if (phone.empty()) throw std::invalid_argument("Phone number cannot be empty");
    for (unsigned char ch : phone) {
        if (!std::isdigit(ch) && ch != '+' && ch != ' ') {
            throw std::invalid_argument("Phone number may only contain digits, '+' or spaces");
        }
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept { phone_.reset(); }

std::string maskId(std::string_view id) {
    if (id.size() <= 3) return std::string(id.size(), '*');
    return std::string(id.substr(0, 2)) + std::string(id.size() - 3, '*') +
           std::string(id.substr(id.size() - 1));
}

std::string Student::redacted() const { return "Student{id=" + maskId(id_) + "}"; }

}  // namespace clubhub
