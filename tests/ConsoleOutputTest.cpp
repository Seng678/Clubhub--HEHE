// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team 3, ITC Club Hub contributors
#include "clubhub/ConsoleOutput.h"
#include <gtest/gtest.h>

using namespace clubhub;

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    EXPECT_EQ(formatStatus(RegistrationStatus::Registered, false), "[REGISTERED]");
    EXPECT_EQ(formatStatus(RegistrationStatus::Cancelled, false), "[CANCELLED]");
}

TEST(ConsoleOutput, ColourOnlyRepeatsTheWord) {
    std::string out = formatStatus(RegistrationStatus::Cancelled, true);
    EXPECT_NE(out.find("[CANCELLED]"), std::string::npos);
}

TEST(ConsoleOutput, ErrorSaysWhatWhyAndNextStep) {
    std::string err = formatError("cannot register for E-017", "the event is full (40 of 40 seats)", "clubhub waitlist E-017");
    EXPECT_NE(err.find("Error: cannot register for E-017"), std::string::npos);
    EXPECT_NE(err.find("Next step: clubhub waitlist E-017"), std::string::npos);
}