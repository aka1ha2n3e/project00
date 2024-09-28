#include "core/Command.hpp"
#include "logging/Logger.hpp"
#include "logging/Logger.hpp"

namespace command
{
    auto CommandBuilder::build() -> ContextPtr<Command>
    {

            switch (*mode) {
                case EDIT_MODE::INSERT:
                    return ContextPtr<InsertModeCommand>(new InsertModeCommand(*buffer, *key));
                default:
                    loging::Logger::logError("不正なモードです");
            }
        if (!mode.has_value() || !key.has_value() || !buffer) {
            loging::Logger::logError("必須パラメータが設定されていません");
        }
    }

    InsertModeCommand::InsertModeCommand(textEditor::TextBuffer& buffer, input::EncodedKey key)
        : buffer(buffer), key(key) {}
    auto InsertModeCommand::Execute() -> void {}
    auto InsertModeCommand::Undo() -> void {}
    auto InsertModeCommand::Redo() -> void {}

    auto CommandManager::ExecuteCommand(ContextPtr<Command> command) -> void
    {
        command->Execute();
        undoStack.Push(std::move(command));
        redoStack = util::Stack<ContextPtr<Command>>();  // Redoスタックをクリア
    }

/**
* @todo チャットGPTが生成したので設計通りか確認する
 */
    auto CommandManager::Undo() -> void
    {
        if (!undoStack.Empty()) {
            const auto& command = undoStack.Top();
            command->Undo();
            redoStack.Push(std::move(const_cast<ContextPtr<Command>&>(command)));
            undoStack.Pop();
        }
    }

    auto CommandManager::Redo() -> void
    {
        if (!redoStack.Empty()) {
            const auto& command = redoStack.Top();
            command->Execute();
            undoStack.Push(std::move(const_cast<ContextPtr<Command>&>(command)));
            redoStack.Pop();
        }
    }

    // MoveCursorCommand, InsertTextCommand, DeleteTextCommandの実装は変更なし
}