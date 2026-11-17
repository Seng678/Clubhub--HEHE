// tests/StudentPrivacyTest.cpp
#include <gtest/gtest.h>
#include <stdexcept>
#include "clubhub/Student.h"

using clubhub::Student;

TEST(StudentPrivacyTest, RedactedHidesPersonalDataAndMasksId) {
    Student s("e20261237", "Sokha Chan", "sokha@example.com");
    s.giveSmsConsent("+855 12 345 678");

    std::string summary = s.redacted();
    EXPECT_EQ(summary, "Student{id=e2******7}");
    EXPECT_EQ(summary.find("Sokha Chan"), std::string::npos);
    EXPECT_EQ(summary.find("sokha@example.com"), std::string::npos);
    EXPECT_EQ(summary.find("345"), std::string::npos);
}

TEST(StudentPrivacyTest, OptionalConsentsStartOff) {
    Student s("e20261237", "Sokha Chan", "sokha@example.com");
    EXPECT_FALSE(s.phone().has_value());
    EXPECT_FALSE(s.remindersByEmail());
}

TEST(StudentPrivacyTest, WithdrawSmsConsentErasesPhone) {
    Student s("e20261237", "Sokha Chan", "sokha@example.com");
    s.giveSmsConsent("+855 12 345 678");
    ASSERT_TRUE(s.phone().has_value());

    s.withdrawSmsConsent();
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacyTest, BadEmailThrowsInvalidArgument) {
    EXPECT_THROW(Student("e20261237", "Sokha Chan", "invalid-email"), std::invalid_argument);
}

TEST(StudentPrivacyTest, PhoneWithLettersRejected) {
    Student s("e20261237", "Sokha Chan", "sokha@example.com");
    EXPECT_THROW(s.giveSmsConsent("123-ABC-456"), std::invalid_argument);
    EXPECT_FALSE(s.phone().has_value());
}

TEST(StudentPrivacyTest, ShortIdIsFullyMasked) {
    Student s("abc", "Sokha Chan", "sokha@example.com");
    EXPECT_EQ(s.redacted(), "Student{id=***}");
}