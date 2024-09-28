#include "input/InputData.hpp"

namespace input{

unsigned int EncodedKey::MaskKey(unsigned int keyCode, bool ctrlPressed, bool shiftPressed, bool altPressed, bool metaPressed) const{
    return (keyCode & KEY_CODE_BITS)
        | (ctrlPressed  ? CTRL_BITS : 0)
        | (shiftPressed ? SHIFT_BITS : 0)
        | (altPressed   ? ALT_BITS : 0)
        | (metaPressed  ? META_BITS : 0);
};
}