#ifndef INPUT_ADAPTER_HPP
#define INPUT_ADAPTER_HPP

#include "input/InputData.hpp"

namespace inputHandler {
/**
 * @class InputAdapter
 * @brief 入力を受け取るクラス
 * @note 入力を受け取るクラス
 */
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
};
#endif