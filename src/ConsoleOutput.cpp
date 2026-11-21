// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"
#include <cstdlib>

namespace clubhub {
std::string_view statusLabel(RegistrationStatus s) {
    switch (s) {
        case RegistrationStatus::Registered: return "REGISTERED";
        case RegistrationStatus::Cancelled: return "CANCELLED";
        case RegistrationStatus::CheckedIn: return "CHECKED IN";
        case RegistrationStatus::Waitlisted: return "WAITLISTED";
    }
    return "UNKNOWN";
}

bool colourEnabled(bool noColorFlag) {
    if (noColorFlag) return false;
    const char* env = std::getenv("NO_COLOR");
    if (env != nullptr && env[0] != '\0') return false;
    return true;
}

std::string formatStatus(RegistrationStatus s, bool colour) {
    std::string label(statusLabel(s));
    if (!colour) return "[" + label + "]";
    std::string code = "\033[32m";
    if (s == RegistrationStatus::Cancelled) code = "\033[31m";
    else if (s == RegistrationStatus::Waitlisted) code = "\033[33m";
    else if (s == RegistrationStatus::CheckedIn) code = "\033[36m";
    return code + "[" + label + "]\033[0m";
}

std::string formatError(std::string_view what, std::string_view why, std::string_view next) {
    return "Error: " + std::string(what) + ": " + std::string(why) + ".\nNext step: " + std::string(next);
}
} // namespace clubhub