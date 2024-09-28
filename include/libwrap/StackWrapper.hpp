#ifndef STACK_WRAPPER_HPP
#define STACK_WRAPPER_HPP

#include <stack>
#include <stdexcept>
#include <functional>

namespace util
{
    template <typename T>
    class Stack
    {
    public:
        using ErrorCallback = std::function<void(const std::string&)>;

        Stack() = default;

        void SetErrorCallback(ErrorCallback callback)
        {
            errorCallback_ = std::move(callback);
        }

        void Push(const T& value)
        {
            stack_.push(value);
        }

        void Push(T&& value)
        {
            stack_.push(std::move(value));
        }

        bool Pop()
        {
            if (stack_.empty())
            {
                ReportError("スタックが空です");
                return false;
            }
            stack_.pop();
            return true;
        }

/**  
* @todo チャットGPTが生成したのでロジックを確認する
*/
    const T& Top() const
        {
            if (stack_.empty())
            {
                ReportError("スタックが空です");
                throw std::runtime_error("スタックが空です");
            }
            return stack_.top();
    }
        bool Top(const T& value) const
        {
            if (stack_.empty())
            {
                    ReportError("スタックが空です");
                return false;
            }
            value = stack_.top();
            return true;
        }
    bool Top(T&& value)
    {
        if (stack_.empty())
        {
            ReportError("スタックが空です");
            return false;
        }
        value = std::move(stack_.top());
        return true;
    }

        bool Empty() const noexcept
        {
            return stack_.empty();
        }

        std::size_t Size() const noexcept
        {
            return stack_.size();
        }

        void Clear() noexcept
        {
            while (!stack_.empty())
            {
                stack_.pop();
            }
        }

    private:
        std::stack<T> stack_;
        ErrorCallback errorCallback_;

        void ReportError(const std::string& message) const
        {
            if (errorCallback_)
            {
                errorCallback_(message);
            }
        }
    };
}

#endif // STACK_WRAPPER_HPP