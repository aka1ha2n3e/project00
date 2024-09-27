#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "common/commonType.hpp"

/**
 * @namespace inputHandler
 * @brief 入力処理に関する機能を提供する名前空間
 */
namespace inputHandler
{
    using namespace textEditor;

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
        auto InputKey() -> Key;
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

    /**
     * @class InputAdapter
     * @brief 入力を処理する抽象基底クラス
     * @tparam InputFormat 入力フォーマットの型
     */
    template <typename InputFormat>
    class InputAdapter
    {
    public:

        /**
         * @brief 入力を解析するメソッド
         * @return 解析された入力
         */
        auto InputParser() -> InputFormat {
            return Input();
        };

    protected:
        /**
         * @brief 入力を受け取る純粋仮想関数
         * @return 受け取った入力
         */
        virtual auto Input() -> InputFormat = 0;
    };

    /**
     * @class KeyInput
     * @brief キー入力を処理するクラス
     */
    class KeyInput: public InputAdapter<String>
    {
    public:

        /**
         * @brief 入力を受け取るメソッド
         * @return 受け取った入力文字列
         */
        auto Input() -> String override;

    private:
        UsrInput keyInput; /**< キー入力を処理するオブジェクト */
    };
} // namespace inputHandler

#endif // INPUTHANDLER_HPP
#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "type.hpp"
namespace inputHandler
{
    using namespace textEditor;

    class UsrInput
    {
        public:
        auto InputKey() -> Key;
    };
    /*
     * @todo 実装
     * @brief コマンド経由で入力を受け取るクラス
     */
    class CommandInput
    {
        //未実装
    };
    template <typename InputFormat>
    class InputAdapter
    {
        public:
            virtual ~InputAdapter();
           auto InputParser() -> InputFormat {
                return Input();
           };
        protected:
            virtual auto Input() -> InputFormat = 0;

    };

    class KeyInput: public InputAdapter<String>
    {
       public:
    /*
    * @todo 実装まだ
    * @brief なんのメソッドかわからん．
    */
            auto CommandDispatcher() -> ResultCode ;
            auto Input() -> String;
        private:
            UsrInput keyInput;
    };
} //namespace inputHandler

#endif // INPUTHANDLER_HPP
