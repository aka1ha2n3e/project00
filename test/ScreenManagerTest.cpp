#include <gtest/gtest.h>
#include "sample.hpp"
#include "type.hpp"


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

TEST_F(ContextPtrTest, ConstructorNullptr) {
    ContextPtr<Sample> context;
}

TEST_F(ContextPtrTest, ConstructorWithInstance) {
    Sample sample(42);
    ContextPtr<Sample> context(&sample);
    EXPECT_EQ(context->getData(), 42);
}

TEST_F(ContextPtrTest, SetPtr) {
    Sample sample(42);
    ContextPtr<Sample> context;
    context.SetPtr(&sample);
    EXPECT_EQ(context->getData(), 42);
}

TEST_F(ContextPtrTest, OperatorArrow) {
    Sample sample(42);
    ContextPtr<Sample> context(&sample);
    context->display();
}

} // namespace ContextPtrTest

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}