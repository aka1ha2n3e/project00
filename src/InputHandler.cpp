#include "input/InputHandler.hpp"
#include "libwrap/UI.hpp"


namespace inputHandler
{
    auto UsrInput::InputKey()->Key{
        UI::UI system;
        return system.GetInput();
    };

    /*
     * @todo 実装
     * @brief キー入力を文字に変換．やり方は要検討
     */
    auto KeyInput::Input() -> String{
        int PushedKey = keyInput.InputKey();
        return "実装されていません";
    };

};