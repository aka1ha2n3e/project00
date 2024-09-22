#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP
namespace textEditor
{
    class TextBuffer{
     public:
        auto AddData(String Data) -> void;
        auto TakeData() -> String;
     private:
        std::vector<String> data; /**< 文字データの保管場所 */
    } 
};
#endif