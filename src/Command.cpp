#include "common/CommonType.hpp"
#include "core/Command.hpp"
#include "logging/Logger.hpp"
#include "logging/Logger.hpp"
#include <optional>

namespace command
{
    auto InsertModeCommandSingleton::getInstance() -> ContextPtr<Command>& {
        /* InsertModeCommand{}で初期化できなかったためInsertModeCommand()で初期化する*/
        static ContextPtr<Command> instance;
        return instance;
    };

    auto InsertModeCommand::Reset() -> void{
        this->buffer = std::move(buffer);
        this->key = std::move(key);
    };


    auto CommandBuilder::Build() -> ContextPtr<Command>&
    {


            switch (mode) {
                case EDIT_MODE::INSERT:
                    static ContextPtr<Command>& command = InsertModeCommandSingleton::getInstance();
                    command->Reset();
                    return command;
                default:
                    loging::Logger::logError("不正なモードです");
            }
    };

    auto InsertModeCommand::Execute() -> void {};
    auto InsertModeCommand::Undo() -> void {};
    auto InsertModeCommand::Redo() -> void {};

    auto CommandManager::ExecuteCommand(ContextPtr<Command> command) -> void
    {
        command->Execute();
        undoStack.Push(std::move(command));
        redoStack = util::Stack<ContextPtr<Command>>();  
    };

}