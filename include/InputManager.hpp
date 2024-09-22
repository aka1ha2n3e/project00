#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "inputHandler.hpp"
#include "inputData.hpp"

namespace inputManager
{

    class InputManager{
        public:
        private:
        inputHandler::KeyInput keyInput;
        textEditor::TextBuffer keyBuf; /**<文字データの保管場所 */
    };
}

#endif