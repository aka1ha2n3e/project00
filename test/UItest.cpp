// test/UItest.cpp

#include "../include/UI.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

int main() {
    UI::NcursesUI ui;

    try {
        // UI の初期化
        ui.InitializeUI();

        // テキスト表示のテスト
        ui.DisplayText("Press and hold a key to see it displayed", 10, 5);
        ui.DisplayText("Press 'q' to quit", 10, 7);

        int ch = 0;
        std::string displayText;
        auto lastKeyPressTime = std::chrono::steady_clock::now();

        while (true) {
            auto now = std::chrono::steady_clock::now();
            auto timeSinceLastKeyPress = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastKeyPressTime).count();

            int newCh = ui.GetInput();
            if (newCh != ERR) {  // 新しい入力がある場合
                ch = newCh;
                lastKeyPressTime = now;
                if (ch == 'q' || ch == 'Q') {
                    break;
                }
                displayText = "Key pressed: " + std::to_string(ch);
            } else if (timeSinceLastKeyPress > 200) {  // キーが200ms以上押されていない場合
                displayText = "";
            }

            // 画面をクリアして新しいテキストを表示
            ui.ClearScreen();
            ui.DisplayText("Press and hold a key to see it displayed", 10, 5);
            ui.DisplayText("Press 'q' to quit", 10, 7);
            if (!displayText.empty()) {
                ui.DisplayText(displayText, 10, 9);
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));  // 画面更新の頻度を制御
        }

        // UI の終了処理
        ui.FinalizeUI();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        ui.FinalizeUI();
        return 1;
    }

    return 0;
}