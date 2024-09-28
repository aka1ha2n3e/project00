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
    explicit ContextPtr(T* ptr = nullptr) : curPtr(ptr) {}

    ContextPtr(const ContextPtr& other) = delete;

    ContextPtr(ContextPtr&& other) noexcept = default;

      template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    ContextPtr(ContextPtr<U>&& other) noexcept : curPtr(other.curPtr.release()) {}

  auto SetPtr(T* ptr) -> void
  {
    curPtr = std::make_unique<T>(*ptr);
    ptr    = nullptr;
  };

    ContextPtr& operator=(const ContextPtr& other) = delete;
    ContextPtr& operator=(ContextPtr&& other) noexcept = default;

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
    template <typename U>
    friend class ContextPtr;
};

template <typename T, typename... Args>
ContextPtr<T> makeContextPtr(Args&&... args) {
    return ContextPtr<T>(new T(std::forward<Args>(args)...));
};

#endif // GENERALTYPE_HPP
