#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "StackWrapper.hpp"
#include "TextBuffer.hpp"

namespace command
{
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
        typeName::Stack::StackWrapper<std::unique_ptr<Command>> undoStack;
        typeName::Stack::StackWrapper<std::unique_ptr<Command>> redoStack;
    };

    class MoveCursorCommand : public Command
    {
    public:
        MoveCursorCommand(textEditor::TextBuffer& buffer, int newPosition);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        int newPosition;
        int oldPosition;
    };

    class InsertTextCommand : public Command
    {
    public:
        InsertTextCommand(textEditor::TextBuffer& buffer, const std::string& text);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        std::string text;
    };

    class DeleteTextCommand : public Command
    {
    public:
        DeleteTextCommand(textEditor::TextBuffer& buffer, int position);

        auto Execute() -> void override;
        auto Undo() -> void override;

    private:
        textEditor::TextBuffer& buffer;
        int position;
        std::string deletedText;
    };

    // 他のコマンドも同様に宣言
}

#endif // COMMAND_HPP