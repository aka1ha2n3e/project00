#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <optional>
#include "common/commonType.hpp"
#include "common/generalType.hpp"
#include "input/InputData.hpp"
#include "libwrap/StackWrapper.hpp"
#include "logging/Logger.hpp"

namespace command {
    enum class EDIT_MODE {
        NORMAL,
        INSERT,
        VISUAL,
        LINUX,
        WINDOWS,
    };

    class Command {
    public:
        virtual ~Command() = default;
        virtual auto Reset() -> void = 0;
        virtual auto Execute() -> void = 0;
        virtual auto Undo() -> void = 0;
        virtual auto Redo() -> void = 0;
    };

    class CommandManager {
    public:
        auto ExecuteCommand(ContextPtr<Command> command) -> void;

    private:
        util::Stack<ContextPtr<Command>> undoStack;
        util::Stack<ContextPtr<Command>> redoStack;
    };

    class MoveCursorCommand : public Command {
    public:
        auto Execute() -> void override;
        auto Undo() -> void override;
        auto Redo() -> void override;

    private:
        textEditor::TextBuffer &buffer;
        textEditor::Coordinate newPosition;
        textEditor::Coordinate oldPosition;
    };

    class InsertModeCommand : public Command {
    public:
        ~InsertModeCommand() = default;
        InsertModeCommand() :
            buffer(std::make_unique<textEditor::TextBuffer>()), key(std::make_unique<input::EncodedKey>()) {};
        auto Reset() -> void override;
        auto Execute() -> void override;
        auto Undo() -> void override;
        auto Redo() -> void override;

    private:
        auto Reset(textEditor::TextBuffer &buffer, input::EncodedKey key) -> void;
        std::unique_ptr<textEditor::TextBuffer> buffer;
        std::unique_ptr<input::EncodedKey> key;
    };

    class InsertModeCommandSingleton {
    public:
        static ContextPtr<Command> &getInstance();
    };

    class CommandBuilder {
    public:
        auto SetMode(command::EDIT_MODE mode) -> CommandBuilder &;
        auto SetKey(input::EncodedKey key) -> CommandBuilder &;
        auto SetBuffer(textEditor::TextBuffer &buffer) -> CommandBuilder &;
        auto Build() -> ContextPtr<Command> &;

    private:
        command::EDIT_MODE mode;
        input::EncodedKey key;
        textEditor::TextBuffer &buffer;
    };


    class CommandState : public ContextPtr<Command> {
    public:
        virtual ContextPtr<Command> CreateCommand(const CommandBuilder &builder);
    };

    class InsertModeCommandContext : public CommandState {
    public:
        auto CreateCommand(const CommandBuilder &builder) -> ContextPtr<Command> override;
    };



} // namespace command

#endif // COMMAND_HPP
