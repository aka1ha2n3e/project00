#include "Command.hpp"

namespace command
{
    auto CommandManager::ExecuteCommand(ContextPtr<Command> command) -> void
    {
        command->Execute();
        undoStack.Push(std::move(command));
        while (!redoStack.Empty())
        {
            redoStack.Pop();
        }
    }

    auto CommandManager::Undo() -> void
    {
        if (!undoStack.Empty())
        {
            auto command = std::move(undoStack.Top());
            undoStack.Pop();
            command->Undo();
            redoStack.Push(std::move(command));
        }
    }

    auto CommandManager::Redo() -> void
    {
        if (!redoStack.Empty())
        {
            auto command = std::move(redoStack.Top());
            redoStack.Pop();
            command->Execute();
            undoStack.Push(std::move(command));
        }
    }

    MoveCursorCommand::MoveCursorCommand(textEditor::TextBuffer& buffer, int newPosition)
        : buffer(buffer), newPosition(newPosition), oldPosition(buffer.GetCursorPosition()) {}

    auto MoveCursorCommand::Execute() -> void
    {
        buffer.MoveCursor(newPosition);
    }

    auto MoveCursorCommand::Undo() -> void
    {
        buffer.MoveCursor(oldPosition);
    }

    InsertTextCommand::InsertTextCommand(textEditor::TextBuffer& buffer, const std::string& text)
        : buffer(buffer), text(text) {}

    auto InsertTextCommand::Execute() -> void
    {
        buffer.InsertText(text);
    }

    auto InsertTextCommand::Undo() -> void
    {
        buffer.DeleteText(buffer.GetCursorPosition() - text.size());
    }

    DeleteTextCommand::DeleteTextCommand(textEditor::TextBuffer& buffer, int position)
        : buffer(buffer), position(position), deletedText(buffer.GetText(position, 1)) {}

    auto DeleteTextCommand::Execute() -> void
    {
        buffer.DeleteText(position);
    }

    auto DeleteTextCommand::Undo() -> void
    {
        buffer.InsertText(deletedText);
    }

}