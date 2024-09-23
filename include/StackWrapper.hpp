#ifndef STACKWRAPPER_HPP
#define STACKWRAPPER_HPP

#include <stack>
#include "LogData.hpp"

namespace typeName
{
    template <typename T>
    class Stack
    {

    public:
        Stack() = default;

        void Push(const T& value)
        {
            stack_.push(value);
        }

        void Push(T&& value)
        {
            stack_.push(std::move(value));
        }

        void Pop()
        {
            if (stack_.empty())
            {
                loging::Error::UnderflowError("Stack is empty");
            }
            stack_.pop();
        }

        T& Top()
        {
            if (stack_.empty())
            {
                loging::Error::UnderflowError("Stack is empty");
            }
            return stack_.top();
        }

        const T& Top() const
        {
            if (stack_.empty())
            {
                loging::Error errorLog;
                errorLog.AppendData("Stack is empty");
                throw std::underflow_error("Stack is empty");
            }
            return stack_.top();
        }

        bool Empty() const
        {
            return stack_.empty();
        }

        std::size_t Size() const
        {
            return stack_.size();
        }

    private:
        std::stack<T> stack_;
    };
}

#endif // STACKWRAPPER_HPP