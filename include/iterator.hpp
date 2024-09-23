#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "ElementPtr.hpp"

namespace iterator
{
  template <typename T> class Iterator
  {
  public:
    virtual ~Iterator() = default;
    Iterator(T* element) : curItem{element} {};
    virtual auto Advance() -> T& = 0;
    virtual auto Retreat() -> T& = 0;
    virtual auto CanAdvance() const -> bool = 0;
    virtual auto CanRetreat() const -> bool = 0;
    virtual auto CurrentItem() const -> T& = 0;
    virtual auto GetItem(int index) const -> T& = 0;
  protected:
    ElementPtr<T> curItem;
    int idx = 0;
  };

  template <typename T> class BrowseIterator : public Iterator<T>
  {
  public:
    BrowseIterator(T* element) : Iterator<T>(element) {}

    auto Advance() -> T& override
    {
      if (this->CanAdvance())
      {
        this->curItem.SetPtr(this->curItem.GetNext());
        ++this->idx;
      }
      return this->curItem.getPtr();
    }

    auto Retreat() -> T& override
    {
      if (this->CanRetreat())
      {
        this->curItem.SetPtr(this->curItem.GetPrev());
        --this->idx;
      }
      return this->curItem.getPtr();
    }

    auto CanAdvance() const -> bool override
    {
      return this->curItem.GetNext() != nullptr;
    }

    auto CanRetreat() const -> bool override
    {
      return this->curItem.GetPrev() != nullptr;
    }

    auto CurrentItem() const -> T& override
    {
      return this->curItem.getPtr();
    }

    auto GetItem(int index) const -> T& override
    {
      // 実装
    }
  };

  template <typename T> class OperateIterator : public Iterator<T>
  {
  public:
    using Iterator<T>::Iterator;

    auto Advance() -> T& override
    {
      if (this->CanAdvance())
      {
        this->curItem.SetPtr(this->curItem.GetNext());
        ++this->idx;
      }
      return this->curItem.getPtr();
    }

    auto Retreat() -> T& override
    {
      if (this->CanRetreat())
      {
        this->curItem.SetPtr(this->curItem.GetPrev());
        --this->idx;
      }
      return this->curItem.getPtr();
    }

    auto CanAdvance() const -> bool override
    {
      return this->idx < this->curItem.GetSize() - 1;
    }

    auto CanRetreat() const -> bool override
    {
      return this->idx > 0;
    }

    auto CurrentItem() const -> T& override
    {
      return this->curItem.getPtr();
    }

    auto GetItem(int index) const -> T& override
    {
      // 実装
    }
  };

  template <typename Item> class AbstractArray
  {
  public:
    virtual ~AbstractArray() = 0;
    virtual auto CreateIterator() const -> std::unique_ptr<Iterator<Item>> = 0;
  };

  template <typename Item>
  AbstractArray<Item>::~AbstractArray() {}
}; // namespace iterator

#endif // ITERATOR_HPP