#ifndef UI_HPP_
#define UI_HPP_

#include <ncurses.h>
#include "type.hpp"

/*
 * UIのライブラリに関するラップ
*/
namespace UI
{

  /*
   * 抽象クラス
   */
  class GeneralUI
  {
  public:
    virtual ~GeneralUI() = default;
    virtual auto InitializeUI() -> void = 0;
    virtual auto FinalizeUI() -> void = 0;

    virtual auto DisplayText(const String& text, Coordinate xCoord, Coordinate yCoord) -> void = 0;
    virtual auto GetInput() -> int = 0;
  };

  /*
   * ラップ
   */
  class NcursesUI : public GeneralUI
  {
  public:
    auto InitializeUI() -> void override;
    auto FinalizeUI() -> void override;

    auto DisplayText(const String& text, Coordinate xCoord, Coordinate yCoord) -> void override;
    auto GetInput() -> int override;
  };
} // namespace UI
// namespace UI
#endif // UI_HPP_
