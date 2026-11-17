// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#pragma once

#include <string>

#if __has_include(<optional>)
#include <optional>
namespace clubhub {
    template<typename T> using optional = std::optional<T>;
    using std::nullopt;
}
#else
namespace clubhub {
    template<typename T>
    class optional {
        bool has_val_ = false;
        T val_;
    public:
        optional() = default;
        optional(const T& v) : has_val_(true), val_(v) {}
        bool has_value() const { return has_val_; }
        explicit operator bool() const { return has_val_; }
        const T& value() const { return val_; }
        T& value() { return val_; }
        void reset() { has_val_ = false; }
    };
    struct nullopt_t {};
    const nullopt_t nullopt{};
}
#endif

namespace clubhub {

class Student {
public:
    Student(std::string id, std::string name, std::string email);
    
    const std::string& id() const noexcept { return id_; }
    const std::string& name() const noexcept { return name_; }
    const std::string& email() const noexcept { return email_; }
    
    void giveSmsConsent(std::string phone);
    void withdrawSmsConsent() noexcept;
    bool hasSmsConsent() const noexcept;
    const std::string& smsPhone() const noexcept;
    
    std::string redacted() const;

private:
    std::string id_;
    std::string name_;
    std::string email_;
    optional<std::string> phone_;
};

} // namespace clubhub
