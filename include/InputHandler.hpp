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
            virtual auto CommandDispatcher() -> ResultCode = 0;
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
