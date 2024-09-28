#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "common/commonType.hpp"
#include "input/InputData.hpp"
#include "input/KeyMapping.hpp"

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
        auto InputKey() -> textEditor::Key;
    };

    /**
     * @class CommandInput
     * @brief コマンド経由で入力を受け取るクラス
     * @todo 実装
     */
    class CommandInput
    {
        // 未実装
    };

class InputAdapter
{
public:
    virtual ~InputAdapter() = default;

    /**
     * @brief 入力を解析するメソッド
     * @return 解析された入力
     */
    auto InputParser() -> input::EncodedKey;

protected:
    /**
     * @brief 入力を受け取る純粋仮想関数
     * @note ライブラリの入力を受け取る
     */
    virtual auto FetchRawKey() -> input::RawKey = 0;
    /**
     * @brief 入力を受け取る純粋仮想関数
     * @note 関数はFetchRawInput()を呼び出して入力を受け取る
     */
    virtual auto ConvertToEncodedKey(input::RawKey CatchNum) -> input::EncodedKey = 0;
};
} // namespace inputHandler

#endif // INPUTHANDLER_HPP