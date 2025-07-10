#include <gtest/gtest.h>
#include <format.hpp>
#include <exceptions.hpp>

class FormatTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FormatTest, BasicFormatting) {
    auto result = vkedu::format("{0} {1}", "Hello", "World");
    EXPECT_EQ(result, "Hello World");
}

TEST_F(FormatTest, RepeatedArguments) {
    auto result = vkedu::format("{1}+{1} = {0}", 2, "one");
    EXPECT_EQ(result, "one+one = 2");
}

TEST_F(FormatTest, MultipleTypes) {
    auto result = vkedu::format("{0} is {1} years old", "Alice", 25);
    EXPECT_EQ(result, "Alice is 25 years old");
}

TEST_F(FormatTest, NoArguments) {
    auto result = vkedu::format("Hello World");
    EXPECT_EQ(result, "Hello World");
}

TEST_F(FormatTest, EmptyString) {
    auto result = vkedu::format("");
    EXPECT_EQ(result, "");
}

TEST_F(FormatTest, SingleArgument) {
    auto result = vkedu::format("Value: {0}", 42);
    EXPECT_EQ(result, "Value: 42");
}

TEST_F(FormatTest, OutOfRangeArgument) {
    EXPECT_THROW(
        auto result = vkedu::format("{0} {1} {2}", "Hello", "World"),
        vkedu::utility::FormatArgumentsException
    );
}

TEST_F(FormatTest, InvalidBracesArgument) {
    EXPECT_THROW(
        auto result = vkedu::format("{abc}", "test"),
        vkedu::utility::InvalidBracesArgumentException
    );
}

TEST_F(FormatTest, MissingClosingBrace) {
    auto result = vkedu::format("{0", "test");
    EXPECT_EQ(result, "test");
}

TEST_F(FormatTest, EmptyBraces) {
    EXPECT_THROW(
        auto result = vkedu::format("{}", "test"),
        vkedu::utility::InvalidBracesArgumentException
    );
}

TEST_F(FormatTest, FloatingPointNumbers) {
    auto result = vkedu::format("Pi is approximately {0}", 3.14159);
    EXPECT_EQ(result, "Pi is approximately 3.14159");
}

TEST_F(FormatTest, BooleanValues) {
    auto result = vkedu::format("True: {0}, False: {1}", true, false);
    EXPECT_EQ(result, "True: 1, False: 0");
}