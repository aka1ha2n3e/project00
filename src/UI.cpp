
#include "UI.hpp"

namespace UI
{
  // NcursesUIの定義
  auto NcursesUI::InitializeUI() -> void
  {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    refresh();
  }

  auto NcursesUI::FinalizeUI() -> void
  {
    endwin();
  }

  auto NcursesUI::DisplayText(const String& text, Coordinate xCoord, Coordinate yCoord) -> void
  {
    mvprintw(yCoord, xCoord, text.c_str());
    refresh();
  }

  auto NcursesUI::GetInput() -> int
  {
    return getch();
  }

}; // namespace UI
