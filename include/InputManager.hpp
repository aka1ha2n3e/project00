#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "inputHandler.hpp"
#include "inputData.hpp"

namespace inputManager
{

    class InputManager{
        public:

            InputManager(textEditor::TextBuffer& buffer);
            void processInput();
        private:
        inputHandler::KeyInput inputer;
        textEditor::TextBuffer txtData; /**<文字データの保管場所 */
        auto CommandDispatcher() -> ResultCode;
        std::unique_ptr<Command> interpretCommand(const String& input);
    };
}

#endif