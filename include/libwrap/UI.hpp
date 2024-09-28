#ifndef UI_HPP_
#define UI_HPP_

#include <ncurses.h>
#include "common/commonType.hpp"
/**
 * @namespace UI
 * @brief UIのライブラリに関するラップ
 */
namespace UI
{


  /**
   * @class GeneralUI
   * @brief UIの抽象基底クラス
   */
  class GeneralUI
  {
  public:
    virtual ~GeneralUI() = default;

    /**
     * @brief UIの初期化を行う
     */
    virtual auto InitializeUI() -> void = 0;

    /**
     * @brief UIの終了処理を行う
     */
    virtual auto FinalizeUI() -> void = 0;

    /**
     * @brief 画面をクリアする
     */
    virtual auto ClearScreen() -> void = 0;

    /**
     * @brief 指定された位置にテキストを表示する
     * @param text 表示するテキスト
     * @param xCoord X座標
     * @param yCoord Y座標
     */
    virtual auto DisplayText(const String& text, Coordinate xCoord, Coordinate yCoord) -> void = 0;

    /**
     * @brief ユーザーからの入力を取得する
     * @return 入力されたキーのコード
     */
    virtual auto GetInput() -> textEditor::Key = 0;
  };


  /**
   * @class NcursesUI
   * @brief ncursesライブラリをラップしたUIクラス
   */
  class NcursesUI : public GeneralUI
  {
  public:
    auto InitializeUI() -> void override;
    auto FinalizeUI() -> void override;
    auto ClearScreen() -> void override;
    auto DisplayText(const String& text, Coordinate xCoord, Coordinate yCoord) -> void override;

    /**
     * @brief ユーザーからの入力を取得する
     * @return 入力されたキーのコード
     * 
     * @note キーマッピング:
     * * 英数 アルファベット順 + 96.例）a は 97が出力
     * * ctrl アルファベット順.例）ctrl + a は 1が出力
     * * shift アルファベット順 + 64.例）shift + a は 64が出力
     * @todo キーマッピングを変更する
     */
    auto GetInput() -> textEditor::Key override;

    static constexpr int RANGE_ALPHABET = 26;

    static constexpr int FIRST_ALPHABET_KEY = 97;
    static constexpr int END_ALPHABET_KEY = FIRST_ALPHABET_KEY + RANGE_ALPHABET;

    static constexpr int FIRST_CTRL_KEY = 1;
    static constexpr int END_CTRL_KEY = FIRST_CTRL_KEY + RANGE_ALPHABET;

    static constexpr int FIRST_SHIFT_KEY = 65;
    static constexpr int END_SHIFT_KEY = FIRST_SHIFT_KEY + RANGE_ALPHABET;
    private:
  };
  using UI = NcursesUI;
} // namespace UI

#endif // UI_HPP_