#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "commonType.hpp"
#include "generalType.hpp"

namespace iterator
{
  template <typename T> class Iterator
  {
  public:
    virtual ~Iterator() = default;
    Iterator(T* element) : curItem{element} {};
    virtual auto Advance() -> T = 0;
    virtual auto Retreat() -> T = 0;
    virtual auto CanAdvance() const -> bool = 0;
    virtual auto CanRetreat() const -> bool = 0;
    virtual auto CurrentItem() const -> T& = 0;
    virtual auto GetItem(int hash) const -> T& = 0;
  protected:
    /* custom ptr */
    ElementPtr<T> curItem;
    int idx = 0;
  };

/*
 * @brief イテレーターの具体的な実装．まだ張りぼて.
 * @todo  実装
*/
  template <typename T> class BrowseIterator : public Iterator<T>
  {
      public:
         auto Advance( ) -> T override
         {
             return this->curItem.GetNext();
         };
         auto Retreat( ) -> T override
         {
             return this->curItem.GetPrev();
         };

         auto CanAdvance( ) const -> bool override
         {
           return this->GetNext() != nullptr;
         };
         auto CanRetreat( ) const -> bool override
         {
           return this->GetPvev() != nullptr;
         };

         auto CurrentItem() const -> T& override
         {
         return this->curItem.getPtr();
         };
private:
         
  };

/*
 * @brief イテレーターの具体的な実装．まだ張りぼて.
 * @todo  実装
*/
  template <typename T> class OperateIterator : public Iterator<T>
  {
      public:
         using Iterator<T>::Iterator;
         auto Advance( ) -> T override;
         auto Retreat( ) -> T override;
         auto CanAdvance( ) const -> bool override;
         auto CanRetreat( ) const -> bool override;
         auto CurrentItem() const -> T& override{};
    private:
  };

  template <typename Item> class AbstractArry
  {
  public:
    virtual ~AbstractArry() = 0;
    virtual auto CreateIterator() const -> std::unique_ptr<Iterator<Item>> = 0;
  };
}; // namespace iterator

#endif // ITERATOR_HPP
