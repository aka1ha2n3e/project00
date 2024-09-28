#ifndef NCURSES_INPUT_ADAPTER_HPP
#define NCURSES_INPUT_ADAPTER_HPP

#include "input/InputHandler.hpp"
#include "libwrap/UI.hpp"

namespace inputHandler {

/*
* @brief NcursesUIのキー入力をシステム用に変換するクラス
* @note 単体テスト済み
*/

class NcursesInputAdapter : public InputAdapter {
public:
public:
    explicit NcursesInputAdapter(UI::NcursesUI& ui) : ncursesUI(ui) {}
    ~NcursesInputAdapter() override = default;

protected:
    auto ConvertToEncodedKey(input::RawKey CatchNum) -> input::EncodedKey override;
    auto FetchRawKey() -> input::RawKey override;

private:
    UI::NcursesUI& ncursesUI;
};

} // namespace inputHandler

#endif // NCURSES_INPUT_ADAPTER_HPP