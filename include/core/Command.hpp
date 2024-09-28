#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "libwrap/StackWrapper.hpp"
#include "common/commonType.hpp"
#include "input/InputData.hpp"
#include "common/generalType.hpp"

namespace command
{
    enum class EDIT_MODE {
        NORMAL,
        LINUX,
        WINDOWS,
    };

    class Command
    {
    public:
        virtual ~Command() = default;
        virtual auto Execute() -> void = 0;
        virtual auto Undo() -> void = 0;
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

    class InsertTextCommand : public Command
    {
    public:
        InsertTextCommand(textEditor::TextBuffer& buffer, const std::string& text);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        textEditor::Line text;
    };

    class DeleteTextCommand : public Command
    {
    public:
        DeleteTextCommand(textEditor::TextBuffer& buffer, textEditor::Coordinate position);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        textEditor::Coordinate position;
        textEditor::Line deletedText;
    };


}

#endif // COMMAND_HPP