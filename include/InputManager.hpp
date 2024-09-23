#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "inputHandler.hpp"
#include "inputData.hpp"

namespace inputManager
{

    class InputManager{
        public:
        //検索機能の呼び出し enter 確定
        //ファイルの編集 enter 改行
        private:
        inputHandler::KeyInput inputer;
        textEditor::TextBuffer txtData; /**<文字データの保管場所 */
    };
}

#endif