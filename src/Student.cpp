// src/Student.cpp
// SPDX-License-Identifier: TODO (Task 3)
#include "clubhub/Student.h"

#include <cctype>
#include <stdexcept>
#include <utility>

namespace clubhub {

Student::Student(std::string id, std::string name, std::string email) {
    if (id.empty()) {
        throw std::invalid_argument("Student id cannot be empty");
    }
    if (name.empty()) {
        throw std::invalid_argument("Student name cannot be empty");
    }
    if (email.find('@') == std::string::npos) {
        throw std::invalid_argument("Student email must contain '@'");
    }
    id_ = std::move(id);
    name_ = std::move(name);
    email_ = std::move(email);
}

void Student::giveSmsConsent(std::string phone) {
    if (phone.empty()) {
        throw std::invalid_argument("Phone number cannot be empty");
    }
    for (unsigned char ch : phone) {
        if (!std::isdigit(ch) && ch != '+' && ch != ' ') {
            throw std::invalid_argument("Phone number may only contain digits, '+', or spaces");
        }
    }
    phone_ = std::move(phone);
}

void Student::withdrawSmsConsent() noexcept {
    phone_.reset();
}

std::string Student::redacted() const {
    if (id_.size() <= 3) {
        return "Student{id=" + std::string(id_.size(), '*') + "}";
    }
    std::string masked = id_.substr(0, 2)
                       + std::string(id_.size() - 3, '*')
                       + id_.substr(id_.size() - 1);
    return "Student{id=" + masked + "}";
}

} // namespace clubhub