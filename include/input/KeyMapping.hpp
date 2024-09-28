// include/KeyMapping.hpp

#ifndef KEY_MAPPING_HPP
#define KEY_MAPPING_HPP

#include <map>
#include "common/commonType.hpp"

namespace input {

enum class KeyAction {
    TAB,
    SHIFT,
    CTRL,
    ALT,

    SHIFT_TAB,
    CTRL_SHIFT,
    ALT_SHIFT,

    INSERT,
    DELETE,
    HOME,
    END,

    PAGE_UP,
    PAGE_DOWN,

    UP,
    DOWN,
    LEFT,
    RIGHT,

    BACKSPACE,
    ENTER,
    ESCAPE,

    SPACE,
    BACK_SLASH,
    FORWARD_SLASH,

    NORMAL,
};

class KeyMapping {
public:

protected:
};

class NcursesKeyMapping : public KeyMapping {
public:

protected:
};


} // namespace input

#endif // KEY_MAPPING_HPP