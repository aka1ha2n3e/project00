#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "libwrap/StackWrapper.hpp"
#include "common/commonType.hpp"
#include "input/InputData.hpp"
#include "common/generalType.hpp"
#include "logging/Logger.hpp"
#include <optional>

namespace command
{
    enum class EDIT_MODE {
        NORMAL,
        INSERT,
        VISUAL,
        LINUX,
        WINDOWS,
    };

    class Command
    {
    public:
        virtual ~Command() = default;
        virtual auto ResetCommand() -> void = 0;
        virtual auto Execute() -> void = 0;
        virtual auto Undo() -> void = 0;
        virtual auto Redo() -> void = 0;
    };

    class CommandManager
    {
    public:
        auto ExecuteCommand(ContextPtr<Command> command) -> void;

    private:
        util::Stack<ContextPtr<Command>> undoStack;
        util::Stack<ContextPtr<Command>> redoStack;
    };

    class MoveCursorCommand : public Command
    {
    public:
        auto Execute() -> void override;
        auto Undo() -> void override;
        auto Redo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        textEditor::Coordinate newPosition;
        textEditor::Coordinate oldPosition;
    };

    class InsertModeCommand : public Command
    {
    public:
        ~InsertModeCommand() = default;  
        InsertModeCommand(): buffer(std::make_unique<textEditor::TextBuffer>()), key(std::make_unique<input::EncodedKey>()) {};  
        auto ResetCommand() -> void override;
        auto Execute() -> void override;
        auto Undo() -> void override;
        auto Redo() -> void override;

    private:
        auto Reset(textEditor::TextBuffer& buffer, input::EncodedKey key) -> void;
        std::unique_ptr<textEditor::TextBuffer> buffer;
        std::unique_ptr<input::EncodedKey> key;
    };

class InsertModeCommandSingleton {
public:
    static ContextPtr<Command>& getInstance(); 
};

class CommandBuilder {
public:
    auto SetMode(command::EDIT_MODE mode) -> CommandBuilder&;
    auto SetKey(input::EncodedKey key) -> CommandBuilder&;
    auto SetBuffer(textEditor::TextBuffer& buffer) -> CommandBuilder&;
    auto Build() -> ContextPtr<Command>&;

private:
    command::EDIT_MODE mode;
    input::EncodedKey key;
    textEditor::TextBuffer& buffer;
};


class CommandContext {
public:
    virtual ContextPtr<Command> CreateCommand(const CommandBuilder& builder) = 0;
};

class InsertModeCommandContext : public CommandContext {
public:
    auto CreateCommand(const CommandBuilder& builder) -> ContextPtr<Command> override;
};


class CommandFactory {
public:
    static auto RegisterContext(command::EDIT_MODE mode, ContextPtr<CommandContext> strategy) -> void;

private:
        static std::map<command::EDIT_MODE, ContextPtr<CommandContext>> strategies;
    };
  

template<typename T>
class CommandWrapper : public Command {
public:
    CommandWrapper(T& command, textEditor::TextBuffer& buffer, input::EncodedKey key)
        : command(command), buffer(buffer), key(key) {}

    auto execute() -> void override {
        command.execute(buffer, key);
    }

private:
    T& command;
    textEditor::TextBuffer& buffer;
        input::EncodedKey key;
    };

}

#endif // COMMAND_HPP