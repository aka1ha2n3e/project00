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
namespace input{

    using RawKey = int;

    class EncodedKey {

    public:
        EncodedKey(unsigned int keyCode = 0) : value(keyCode & KEY_CODE_BITS){};

    void SetKeyCode(unsigned int keyCode) {
        value = (value & ~KEY_CODE_BITS) | (keyCode & KEY_CODE_BITS);
    }

    void SetCtrl(bool pressed) {
        if (pressed) value |= CTRL_BITS;
        else value &= ~CTRL_BITS;
    }

    void SetShift(bool pressed) {
        if (pressed) value |= SHIFT_BITS;
        else value &= ~SHIFT_BITS;
    }

    void SetAlt(bool pressed) {
        if (pressed) value |= ALT_BITS;
        else value &= ~ALT_BITS;
    }

    void SetMeta(bool pressed) {
        if (pressed) value |= META_BITS;
        else value &= ~META_BITS;
    }


        unsigned int GetCode() const { return value & 0xFFFFFF; }
        bool CtrlPressed() const { return value & 0x1000000; }
        bool ShiftPressed() const { return value & 0x2000000; }
        bool AltPressed() const { return value & 0x4000000; }
        bool MetaPressed() const { return value & 0x8000000; }

        bool operator==(const EncodedKey& other) const { return value == other.value; }
        bool operator!=(const EncodedKey& other) const { return value != other.value; }

    private:
        unsigned int value;
        static inline constexpr unsigned int KEY_CODE_BITS  = 0x00FFFFFF;
        static inline constexpr unsigned int CTRL_BITS  = 0x01000000;
        static inline constexpr unsigned int SHIFT_BITS = 0x02000000;
        static inline constexpr unsigned int ALT_BITS   = 0x04000000;
        static inline constexpr unsigned int META_BITS  = 0x08000000;

        unsigned int MaskKey(unsigned int keyCode, bool ctrlPressed, bool shiftPressed, bool altPressed, bool metaPressed) const;
    };
};
#endif