#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "input/InputHandler.hpp"
#include "input/InputData.hpp"
#include "input/KeyMapping.hpp"
#include "core/Command.hpp"

/**
 * @namespace inputManager
 * @brief 入力管理に関する機能を提供する名前空間
 */
namespace inputManager
{
    /**
     * @class InputManager
     * @brief 入力を管理するクラス
     */
    class InputManager {
    public:
        /**
         * @brief コンストラクタ
         * @param buffer テキストバッファへの参照
         */
        InputManager(textEditor::TextBuffer& buffer);

        /**
         * @brief 入力を処理するメソッド
         * @note いらねえんじゃね
         */
        void processInput();

    private:
        inputHandler::UsrInput inputer; /**< キー入力を処理するオブジェクト */
        textEditor::TextBuffer txtData; /**< 文字データの保管場所 */

        /**
         * @brief コマンドを処理するメソッド
         * @return 処理結果のコード
         */
        auto DispatchCommand(input::EncodedKey Command) -> input::ResultCode;
        auto TransitionState() -> void;

        command::EDIT_MODE state;


    };
}

#endif // INPUTMANAGER_HPP