#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "common/commonType.hpp"
#include "input/InputData.hpp"
#include "input/adapter/NcursesInputAdapter.hpp"
#include "input/KeyMapping.hpp"

  #define InputDriver  NcursesInputAdapter
/**
 * @namespace inputHandler
 * @brief 入力処理に関する機能を提供する名前空間
 */
namespace inputHandler
{

    /**
     * @class UsrInput
     * @brief ユーザー入力を処理するクラス
     */
    class UsrInput
    {
    public:
        /**
         * @brief キー入力を受け取るメソッド
         * @return 入力されたキー
         */
        auto InputText() -> textEditor::Key;
        NcursesInputAdapter Parse;
    };
} // namespace inputHandler

#endif // INPUTHANDLER_HPP