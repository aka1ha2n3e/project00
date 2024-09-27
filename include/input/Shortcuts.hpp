#ifndef SHORTCUTS_HPP
#define SHORTCUTS_HPP

namespace shortcuts {

    enum class CommandType {
        WINDOWS,
        LINUX,
        NORMAL,
    };

    enum class Shortcut {
    };

    struct ShortcutMapping {
        CommandType type;
        Shortcut shortcut;
    };

}

#endif // SHORTCUTS_HPP