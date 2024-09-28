#include "state/StateEditor.hpp"

namespace state
{
    auto StateEditorManager::TranslateState(input::EncodedKey key) -> void
    {
        if(key.CtrlPressed() && key.ShiftPressed())
        {
            SetEditorMode(command::EDIT_MODE::WINDOWS);
        }
        else
        {
            SetEditorMode(command::EDIT_MODE::LINUX);
        }
    }   

    auto StateEditorManager::GetCurrentMode() const -> command::EDIT_MODE
    {
        return CurrentMode;
    }

    auto StateEditorManager::SetEditorMode(command::EDIT_MODE state) -> void
    {
        CurrentMode = state;
    }
    
}