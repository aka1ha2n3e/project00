#include "core/Command.hpp"

namespace command
{
    auto CommandManager::ExecuteCommand(ContextPtr<Command> command) -> void
    {
    }

    auto CommandManager::Undo() -> void
    {
    }

    auto CommandManager::Redo() -> void
    {
    }

    MoveCursorCommand::MoveCursorCommand(textEditor::TextBuffer& buffer, int newPosition)
        : buffer(buffer), newPosition(newPosition), oldPosition(buffer.GetCursorPosition()) {}

    auto MoveCursorCommand::Execute() -> void
    {
    }

    auto MoveCursorCommand::Undo() -> void
    {
    }

    InsertTextCommand::InsertTextCommand(textEditor::TextBuffer& buffer, const std::string& text)
        : buffer(buffer), text(text) {}

    auto InsertTextCommand::Execute() -> void
    {
    }

    auto InsertTextCommand::Undo() -> void
    {
    }

    DeleteTextCommand::DeleteTextCommand(textEditor::TextBuffer& buffer, int position)
        : buffer(buffer), position(position), deletedText(buffer.GetText(position, 1)) {}

    auto DeleteTextCommand::Execute() -> void
    {
    }

    auto DeleteTextCommand::Undo() -> void
    {
    }

}