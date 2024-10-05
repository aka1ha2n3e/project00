#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "core/Command.hpp"

using ::testing::_;
using ::testing::Return;

std::uint32_t const EXE = 100;

class MockCommand : public command::Command {
public:
    MOCK_METHOD(void, Execute, (), (override));
    MOCK_METHOD(void, Reset, (), (override));
    MOCK_METHOD(void, Undo, (), (override));
    MOCK_METHOD(void, Redo, (), (override));
};

class TestCommand : public command::Command {
public:
    auto Execute() -> void override { stage = EXE; }
    auto Reset() -> void override { stage = 0; }
    auto Redo() -> void override { stage++; }
    auto Undo() -> void override { stage--; }

    auto GetStage() -> std::uint32_t { return stage; }

private:
    std::uint32_t stage = 0;
};

TEST(commandTest, ExecuteTest) {
    TestCommand command;
    command.Execute();
    EXPECT_EQ(command.GetStage(), EXE);
}

TEST(commandTest, ResetTest) {
    TestCommand command;
    command.Execute();
    command.Reset();
    EXPECT_EQ(command.GetStage(), 0);
}

TEST(commandTest, RedoTest) {
    TestCommand command;
    command.Execute();
    command.Redo();
    EXPECT_EQ(command.GetStage(), EXE + 1);
}

TEST(commandTest, UndoTest) {
    TestCommand command;
    command.Execute();
    command.Redo();
    command.Undo();
    EXPECT_EQ(command.GetStage(), EXE);
}

TEST(MockCommandTest, MethodCallTest) {
    MockCommand command;
    EXPECT_CALL(command, Execute()).Times(1);
    EXPECT_CALL(command, Undo()).Times(1);
    EXPECT_CALL(command, Redo()).Times(1);
    EXPECT_CALL(command, Reset()).Times(1);
    command.Execute();
    command.Undo();
    command.Redo(); 
    command.Reset();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
