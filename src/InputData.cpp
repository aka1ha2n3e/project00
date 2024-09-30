#include "input/InputData.hpp"

namespace input{

auto EncodedKey::MaskKey(unsigned int keyCode, bool ctrlPressed, bool shiftPressed, bool altPressed, bool metaPressed) const -> std::uint32_t{
    return (keyCode & KEY_CODE_BITS)
        | (ctrlPressed()  ? CTRL_BITS : 0)
        | (shiftPressed() ? SHIFT_BITS : 0)
        | (altPressed()   ? ALT_BITS : 0)
        | (metaPressed()  ? META_BITS : 0);
};
auto EncodedKey::SetKeyCode(std::uint32_t keyCode) -> void {
    byteData = (byteData & ~KEY_CODE_BITS) | (keyCode & KEY_CODE_BITS);
};

auto EncodedKey::SetCtrl(bool pressed) -> void {
    if (pressed) byteData |= CTRL_BITS;
    else byteData &= ~CTRL_BITS;
};

auto EncodedKey::SetShift(bool pressed) -> void {
    if (pressed) byteData |= SHIFT_BITS;
    else byteData &= ~SHIFT_BITS;
};

auto EncodedKey::SetAlt(bool pressed) -> void {
    if (pressed) byteData |= ALT_BITS;
    else byteData &= ~ALT_BITS;
};

auto EncodedKey::SetMeta(bool pressed) -> void {
    if (pressed) byteData |= META_BITS;
    else byteData &= ~META_BITS;
};

auto EncodedKey::GetCode() const -> std::uint32_t {
    return byteData & KEY_CODE_BITS;
};

auto EncodedKey::CtrlPressed() const -> bool {
    return byteData & CTRL_BITS;
};

auto EncodedKey::ShiftPressed() const -> bool {
    return byteData & SHIFT_BITS;
};

auto EncodedKey::AltPressed() const -> bool {
    return byteData & ALT_BITS;
};

auto EncodedKey::MetaPressed() const -> bool {
    return byteData & META_BITS;
};

auto EncodedKey::operator==(const EncodedKey& other) const -> bool {
    return byteData == other.byteData;
};  

auto EncodedKey::operator!=(const EncodedKey& other) const -> bool {
    return byteData != other.byteData;
};


}
