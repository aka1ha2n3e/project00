#ifndef STATEEDITOR_HPP
#define STATEEDITOR_HPP

#include "core/Command.hpp"
#include "input/InputHandler.hpp"

namespace state
{
    class StateEditorManager
    {
    public:
        auto TranslateState(input::EncodedKey key) -> void;
    /** 
    * @brief 現在のエディターモードを取得する
    * @return 現在のエディターモード
    * @note 関数名募集中
    */  
        auto GetCurrentMode() const -> command::EDIT_MODE;
    private:
    /** 
    * @brief エディターモードを設定する
    * @param state 設定するエディターモード
    * @note 関数名募集中
    */
        auto SetEditorMode(command::EDIT_MODE state) -> void;
        command::EDIT_MODE CurrentMode;
    };
}

#endif // STATEEDITOR_HPP