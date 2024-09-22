#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include "type.hpp"
namespace inputHandler
{
    using namespace textEditor;

    class UsrInput
    {
        auto HandleKey() -> Key;
    };
    /*
     * コマンド経由で入力を受け取るクラス
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
           auto InputParser() -> InputFormat
           {};
    };

    class KeyInputHandler: public InputAdapter<String>
    {
       public:
        private:
            UsrInput keyInput;
    };
} //namespace inputHandler

#endif // INPUTHANDLER_HPP
