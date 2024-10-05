#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "input/adapter/NcursesInputAdapter.hpp"
#include "libwrap/UI.hpp"
#include "input/InputData.hpp"

using ::testing::Return;
using ::testing::_;

class MockNcursesUI : public UI::NcursesUI {
public:
    MOCK_METHOD(textEditor::Key, GetInput, (), (override));
};

// テスト用のNcursesInputAdapterクラス
class TestNcursesInputAdapter : public inputHandler::NcursesInputAdapter {
public:
    TestNcursesInputAdapter(UI::NcursesUI& ui) : NcursesInputAdapter(ui) {}
    using NcursesInputAdapter::FetchRawKey;
    using NcursesInputAdapter::ConvertToEncodedKey;
};

class NcursesInputAdapterTest : public ::testing::Test {
protected:
    MockNcursesUI mockUI;
    TestNcursesInputAdapter adapter;

    NcursesInputAdapterTest() : adapter(mockUI) {}
};

/* キー入力を変換するテスト */
TEST_F(NcursesInputAdapterTest, ConvertToEncodedKeyTest) {
    /* アルファベットのテスト */
    auto encodedKey = adapter.ConvertToEncodedKey(UI::NcursesUI::FIRST_ALPHABET_KEY);
    EXPECT_EQ(encodedKey.GetCode(), 0);
    EXPECT_FALSE(encodedKey.CtrlPressed());
    EXPECT_FALSE(encodedKey.ShiftPressed());
    EXPECT_FALSE(encodedKey.AltPressed());
    EXPECT_FALSE(encodedKey.MetaPressed());

    /* Ctrlキーのテスト */
    encodedKey = adapter.ConvertToEncodedKey(UI::NcursesUI::FIRST_CTRL_KEY);
    EXPECT_EQ(encodedKey.GetCode(), 0);
    EXPECT_TRUE(encodedKey.CtrlPressed());
    EXPECT_FALSE(encodedKey.ShiftPressed());
    EXPECT_FALSE(encodedKey.AltPressed());
    EXPECT_FALSE(encodedKey.MetaPressed());

    /* Shiftキーのテスト */
    encodedKey = adapter.ConvertToEncodedKey(UI::NcursesUI::FIRST_SHIFT_KEY);
    EXPECT_EQ(encodedKey.GetCode(), 0);
    EXPECT_FALSE(encodedKey.CtrlPressed());
    EXPECT_TRUE(encodedKey.ShiftPressed());
    EXPECT_FALSE(encodedKey.AltPressed());
    EXPECT_FALSE(encodedKey.MetaPressed());
}


/* キー入力を取得するテスト */
TEST_F(NcursesInputAdapterTest, FetchRawKeyTest) {
    EXPECT_CALL(mockUI, GetInput())
        .WillOnce(Return(UI::NcursesUI::FIRST_ALPHABET_KEY))  // 'a'
        .WillOnce(Return(UI::NcursesUI::FIRST_CTRL_KEY))      // Ctrl+A
        .WillOnce(Return(UI::NcursesUI::FIRST_SHIFT_KEY));    // Shift+A

    auto encodedKey = adapter.FetchRawKey();
    EXPECT_EQ(encodedKey, UI::NcursesUI::FIRST_ALPHABET_KEY);

    encodedKey = adapter.FetchRawKey();
    EXPECT_EQ(encodedKey, UI::NcursesUI::FIRST_CTRL_KEY);

    encodedKey = adapter.FetchRawKey();
    EXPECT_EQ(encodedKey, UI::NcursesUI::FIRST_SHIFT_KEY);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}