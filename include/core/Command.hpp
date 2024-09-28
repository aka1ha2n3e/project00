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
        virtual auto Execute() -> void = 0;
        virtual auto Undo() -> void = 0;
        virtual auto Redo() -> void = 0;
    };

    class CommandManager
    {
    public:
        auto ExecuteCommand(ContextPtr<Command> command) -> void;
        auto Undo() -> void;
        auto Redo() -> void;

    private:
        util::Stack<ContextPtr<Command>> undoStack;
        util::Stack<ContextPtr<Command>> redoStack;
    };

    class MoveCursorCommand : public Command
    {
    public:
        MoveCursorCommand(textEditor::TextBuffer& buffer, textEditor::Coordinate newPosition);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        textEditor::Coordinate newPosition;
        textEditor::Coordinate oldPosition;
    };

    class InsertModeCommand : public Command
    {
    public:
        InsertModeCommand(textEditor::TextBuffer& buffer, input::EncodedKey key);

        auto Execute() -> void override;
        auto Undo() -> void override;
        auto Redo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        input::EncodedKey key;
    };

    class CommandBuilder
    {
    public:
        CommandBuilder& SetMode(EDIT_MODE mode) {
            this->mode = mode;
            return *this;
        }

        CommandBuilder& SetKey(input::EncodedKey key) {
            this->key = key;
            return *this;
        }

        CommandBuilder& SetBuffer(textEditor::TextBuffer& buffer) {
            this->buffer = &buffer;
            return *this;
        }

        CommandBuilder& SetSelectionStart(textEditor::Coordinate start) {
            this->selectionStart = start;
            return *this;
        }

        CommandBuilder& SetSelectionEnd(textEditor::Coordinate end) {
            this->selectionEnd = end;
            return *this;
        }

/**
*@todo オプショナルのラップ
*/
        auto build() -> ContextPtr<Command>;
        

    private:
        std::optional<EDIT_MODE> mode;
        std::optional<input::EncodedKey> key;
        std::optional<textEditor::Coordinate> selectionStart;
        std::optional<textEditor::Coordinate> selectionEnd;
        textEditor::TextBuffer* buffer = nullptr;
    };
  


}

#endif // COMMAND_HPP