#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP
#include <vector>
#include "common/commonType.hpp"

namespace textEditor
{
    class Buffer{

    };
    class TextBuffer : public Buffer{
     public:
        auto AddData(String Data) -> void;
        auto TakeData() -> String;
        auto GetCursorPosition() const -> int;
        auto MoveCursor(int position) -> void;
        auto InsertText(const String& text) -> void;
        auto DeleteText(int position) -> void;
        auto GetText(int position, int length) const -> String;

     private:
        std::vector<String> data; /**< 文字データの保管場所 */
    }; 
};
#endif