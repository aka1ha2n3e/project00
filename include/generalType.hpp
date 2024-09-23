#ifndef GENERALTYPE_HPP
#define GENERALTYPE_HPP

#include <memory>
#include "commonType.hpp"
#include "FileData.hpp"
#include "type.hpp"

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
  template <typename T>
  class FileContents
  {
    public:
      virtual ~FileContents();
      FileName name; /**< ファイル名 */
      Path    path;     /**< パス */
      T     data;        /**< data */
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

  /*
   * @brief メソッドを呼び出す．
   */
  auto operator->() const -> T*
  {
    if (curPtr.GetPtr() != nullptr)
    {
      return curPtr.get();
    }
  };

  /*
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

  /*
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
class ContextPtr
{
public:
  explicit ContextPtr(T* instance = nullptr) : curPtr(instance) {};

  auto SetPtr(T* ptr) -> void
  {
    curPtr = std::make_unique<T>(*ptr);
    ptr    = nullptr;
  };

  /*
   * @brief メソッドを呼び出す．
   */
  auto operator->() const -> T*
  {
    if (GetPtr() != nullptr)
    {
      return curPtr.get();
    }
  };

private:

  /*
   * @brief ポインタを返す.
   */
  auto GetPtr() const -> T*
  {
    return curPtr.get();
  };
  std::unique_ptr<T> curPtr;
};

#endif // GENERALTYPE_HPP
