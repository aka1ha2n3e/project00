#include "input/InputData.hpp"
#include "input/adapter/InputAdapter.hpp"
#include "libwrap/UI.hpp"
#include "input/KeyMapping.hpp"
#include "input/adapter/NcursesInputAdapter.hpp"
#include "input/InputHandler.hpp"


namespace inputHandler
{
    auto NcursesInputAdapter::FetchRawKey() -> input::RawKey {
        input::RawKey pushedKey = ncursesUI.GetInput();
        return pushedKey;
    };
    /*
     * @brief キー入力を文字に変換．A-Z,a-z,ctrl+a-z,shift+a-zを変換する.
     * @param CatchNum 入力されたキーのコード
     * @return システム用に変換されたキーのコードクラス
     * @note キーマッピング:
     * * 0スタートのアルファベット順.例）aやA は 0が出力
     * * ctrlは戻り値のmember変数に格納
     * * shiftやctrl,alt,metaは戻り値のmember変数に格納
     * * 単体テスト済み
     * @todo alt,metaの実装
     */
    auto NcursesInputAdapter::ConvertToEncodedKey(input::RawKey CatchNum) -> input::EncodedKey{
        input::EncodedKey encodedKey;
        if(CatchNum >= UI::NcursesUI::FIRST_ALPHABET_KEY && CatchNum <= UI::NcursesUI::END_ALPHABET_KEY)
        {
            encodedKey.SetKeyCode(CatchNum - UI::NcursesUI::FIRST_ALPHABET_KEY);
            encodedKey.SetCtrl(false);
            encodedKey.SetShift(false);
            encodedKey.SetAlt(false);
            encodedKey.SetMeta(false);
        }
        else if(CatchNum >= UI::NcursesUI::FIRST_CTRL_KEY && CatchNum <= UI::NcursesUI::END_CTRL_KEY)
        {
            encodedKey.SetKeyCode(CatchNum - UI::NcursesUI::FIRST_CTRL_KEY);
            encodedKey.SetCtrl(true);
            encodedKey.SetShift(false);
            encodedKey.SetAlt(false);
            encodedKey.SetMeta(false);
        }
        else if(CatchNum >= UI::NcursesUI::FIRST_SHIFT_KEY && CatchNum <= UI::NcursesUI::END_SHIFT_KEY)
        {
            encodedKey.SetKeyCode(CatchNum - UI::NcursesUI::FIRST_SHIFT_KEY);
            encodedKey.SetCtrl(false);
            encodedKey.SetShift(true);
            encodedKey.SetAlt(false);
            encodedKey.SetMeta(false);
        }
        else
        {
            /* 後ほど実装 */
        }
        return encodedKey;
    };

    auto InputAdapter::InputParser() -> input::EncodedKey {
        input::RawKey rawKey = FetchRawKey();
        return ConvertToEncodedKey(rawKey);
    }
};