#include "input/InputData.hpp"

namespace input{

auto EncodedKey::MaskKey(textEditor::Key keyCode, bool isPressedCtrl, bool isPressedShift, bool isPressedAlt, bool isPressedMeta) const -> std::uint32_t{
    return (keyCode & KEY_CODE_BITS)
        | (isPressedCtrl  ? CTRL_BITS : 0)
        | (isPressedShift ? SHIFT_BITS : 0)
        | (isPressedAlt   ? ALT_BITS : 0)
        | (isPressedMeta  ? META_BITS : 0);
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
