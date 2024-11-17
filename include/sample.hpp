
#ifndef SAMPLE_HPP
#define SAMPLE_HPP

#include <iostream>

class Sample {
public:
    Sample() : data_(0){};
    explicit Sample(int data) : data_(data) {}

    void display() const { std::cout << "Sample::display() called with data: " << data_ << std::endl; }

    int getData() const { return data_; }

private:
    int data_ = 0;
};

#endif // SAMPLE_HPP
