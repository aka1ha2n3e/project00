#include <gtest/gtest.h>
#include "sample.hpp"
#include "UI.hpp"


namespace ContextPtrTest {

class ContextPtrTest : public ::testing::Test {
protected:
    void SetUp() override {
        // テスト用のセットアップコード（必要に応じて）
    }

    void TearDown() override {
        // テスト用のクリーンアップコード（必要に応じて）
    }
};


TEST_F(ContextPtrTest, ConstructorWithInstance) {
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