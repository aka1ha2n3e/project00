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

     private:
        std::vector<String> data; /**< 文字データの保管場所 */
    }; 
};
namespace input{

    using RawKey = int;

    class EncodedKey {

    public:
        EncodedKey(std::uint32_t keyCode = 0) : byteData(keyCode & KEY_CODE_BITS){};

    auto SetKeyCode(std::uint32_t keyCode) -> void;

    auto SetCtrl(bool pressed) -> void; 

    auto SetShift(bool pressed) -> void;

    auto SetAlt(bool pressed) -> void;

    auto SetMeta(bool pressed) -> void;


        auto GetCode() const -> std::uint32_t; 
        auto CtrlPressed() const -> bool;
        auto ShiftPressed() const -> bool;
        auto AltPressed() const -> bool;
        auto MetaPressed() const -> bool;

        auto operator==(const EncodedKey& other) const -> bool;
        auto operator!=(const EncodedKey& other) const -> bool;

    private:
        std::uint32_t byteData;
        static inline constexpr std::uint32_t KEY_CODE_BITS  = 0x00FFFFFF;
        static inline constexpr std::uint32_t CTRL_BITS  = 0x01000000;
        static inline constexpr std::uint32_t SHIFT_BITS = 0x02000000;
        static inline constexpr std::uint32_t ALT_BITS   = 0x04000000;
        static inline constexpr std::uint32_t META_BITS  = 0x08000000;

        auto MaskKey(textEditor::Key keyCode, bool isPressedCtrl, bool isPressedShift, bool isPressedAlt, bool isPressedMeta) const -> std::uint32_t;
    };
};
#endif