#include <gtest/gtest.h>
#include "sample.hpp"
#include "libwrap/UI.hpp"


namespace ContextPtrTest {

class ContextPtrTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};


/*
*UIのテスト
*/
TEST_F(ContextPtrTest, ConstructorWithInstance) {
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
            } 

            ui.ClearScreen();
            ui.DisplayText("Press and hold a key to see it displayed", 10, 5);
            ui.DisplayText("Press 'q' to quit", 10, 7);
            if (!displayText.empty()) {
                ui.DisplayText(displayText, 10, 9);
            }

        }

        // UI の終了処理
        ui.FinalizeUI();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        ui.FinalizeUI();
    }

}

} // namespace ContextPtrTest

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    UI::UI sample;
    sample.InitializeUI();
    while (true) {
    int ch = sample.GetInput();
        if (ch == 'q') break;
    }
    sample.FinalizeUI();
    return RUN_ALL_TESTS();
}