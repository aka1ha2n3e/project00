#ifndef GENERALTYPE_HPP
#define GENERALTYPE_HPP

#include <memory>
#include "common/commonType.hpp"

namespace data
{
  template <typename T>
  class DataList
  {
  public:
    auto AppendList(T data) -> void;
    auto GetLast() const -> T;

  private:
    int curIdx = 0;
  };
}; // namespace data

namespace fileSystem
{
  class TxtData;
  template <typename T>
  class FileContents
  {
    public:
      FileContents(T& data) : data(data) {};
      virtual ~FileContents();
      FileName name; /**< ファイル名 */
      Path    path;     /**< パス */
      T&     data;        /**< data */
  };
};

  /*
   * @tudo エラーハンドリングに関するログなどの修正が必要．
   */
template <typename T> 
class ElementPtr
{
public:
  explicit ElementPtr(T* instance = nullptr) : curPtr(instance) {};

  auto SetPtr(T* ptr) -> void
  {
    curPtr = std::make_unique<T>(*ptr);
    if (ptr() != nullptr)
    {
      ptr = nullptr;
    }
  };

  /**
   * @brief メソッドを呼び出す．
   */
  auto operator->() const -> T*
  {
    if (curPtr.GetPtr() != nullptr)
    {
      return curPtr.get();
    }
  };

  /**
   * @brief 次のポインタを返す.
   */
  auto GetNext() const -> T*
  {
    if ( (curPtr.curPtr.get() + 1) != nullptr)
    {
      return (curPtr.get() + 1);
    }
    else
    {
    return nullptr;
    }
  };

  /**
   * @brief  前のポインタを返す.
   */
  auto GetPrev() const -> T*
  {
    if ( (curPtr.get() - 1)(curPtr - 1) != nullptr)
    {
      return (curPtr.get() - 1);
    }
    else
    {
    return nullptr;
    }
  };
private:
  std::unique_ptr<T> curPtr;
};


template <typename T>
class ContextPtr {
public:
    virtual ~ContextPtr() = default;
        ContextPtr() : curPtr(nullptr) {};  
    explicit ContextPtr(const T& ref) : curPtr(std::make_unique<T>(ref)) {};
    explicit ContextPtr(std::unique_ptr<T> ptr) : curPtr(std::move(ptr)) {}

    ContextPtr(ContextPtr& other) = delete;

    ContextPtr(ContextPtr&& other) noexcept = default;
    
    auto SetPtr(std::unique_ptr<T> ptr) -> void {
        curPtr = std::move(ptr);
    }

    ContextPtr& operator=(const ContextPtr& other) = delete;
    ContextPtr& operator=(ContextPtr&& other) noexcept = default;
    ContextPtr& operator=(T&& other) {
        curPtr = std::make_unique<T>(std::move(other));
        return *this;
    }

    void reset(T* ptr = nullptr) {
        curPtr.reset(ptr);
    }


    T& operator*() const {
        return *curPtr;
    }

    T* operator->() const {
        return curPtr.get();
    }

    explicit operator bool() const {
        return curPtr != nullptr;
    }

private:
    std::unique_ptr<T> curPtr;

  /**
   * @brief ポインタを返す.
   */
    auto GetPtr() const -> T*
    {
      return curPtr.get();
    };
};

#endif // GENERALTYPE_HPP
