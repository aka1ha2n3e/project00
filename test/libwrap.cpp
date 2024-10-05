#include <gtest/gtest.h>
#include "libwrap/StackWrapper.hpp"
#include <string>

class StackTest : public ::testing::Test {
protected:
    util::Stack<int> intStack;
    util::Stack<std::string> stringStack;
};

TEST_F(StackTest, PushAndTop) {
    intStack.Push(5);
    EXPECT_EQ(intStack.Top(), 5);

    stringStack.Push("{テスト}");
    EXPECT_EQ(stringStack.Top(), "{テスト}");
}

TEST_F(StackTest, PushAndPop) {
    intStack.Push(10);
    intStack.Push(20);
    EXPECT_TRUE(intStack.Pop());
    EXPECT_EQ(intStack.Top(), 10);
}

TEST_F(StackTest, EmptyAndSize) {
    EXPECT_TRUE(intStack.Empty());
    EXPECT_EQ(intStack.Size(), 0);

    intStack.Push(1);
    intStack.Push(2);
    EXPECT_FALSE(intStack.Empty());
    EXPECT_EQ(intStack.Size(), 2);
}

TEST_F(StackTest, Clear) {
    intStack.Push(1);
    intStack.Push(2);
    intStack.Clear();
    EXPECT_TRUE(intStack.Empty());
}

TEST_F(StackTest, PopEmptyStack) {
    EXPECT_FALSE(intStack.Pop());
}

TEST_F(StackTest, TopEmptyStack) {
    EXPECT_THROW(intStack.Top(), std::runtime_error);
}

TEST_F(StackTest, ErrorCallback) {
    bool errorCalled = false;
    intStack.SetErrorCallback([&errorCalled](const std::string& message) {
        errorCalled = true;
        EXPECT_EQ(message, "スタックが空です");
    });

    EXPECT_THROW(intStack.Top(), std::runtime_error);
    EXPECT_TRUE(errorCalled);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}