#include <gtest/gtest.h>
#include "common/generalType.hpp"
#include <vector>


class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void setNum(int num) {
        this->num = num;
    }   
    virtual void execute() = 0;
    int num = 0;
};

class IncrementStrategy : public Strategy {
public:
    void execute() override {
        this->num++;
    }
};

class DoubleStrategy : public Strategy {
public:
    void execute() override {
        this->num *= 2;
    }
};

class StrategyContext : public ContextPtr<Strategy> {
public:
    StrategyContext(std::unique_ptr<Strategy> ptr) : ContextPtr<Strategy>(std::move(ptr)) {}
};


TEST(ContextPtrTest, StrategyExecution) {
    Test contxt(std::make_unique<IncrementStrategy>());
    
    contxt->setNum(5);
    contxt->execute();
    EXPECT_EQ(contxt->num, 6);

    contxt.SetPtr(std::make_unique<DoubleStrategy>());
    contxt->setNum(5); 
    contxt->execute();
    EXPECT_EQ(contxt->num, 10);

    contxt.SetPtr(std::make_unique<IncrementStrategy>());
    contxt->setNum(6); 
    contxt->execute();
    EXPECT_EQ(contxt->num, 7);

    contxt.SetPtr(std::make_unique<DoubleStrategy>());
    contxt->setNum(7); 
    contxt->execute();
    EXPECT_EQ(contxt->num, 14);
}

