#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>
#include "common/commonType.hpp"
#include "common/generalType.hpp"

/**
 * @namespace iterator
 * @brief イテレータ関連のクラスと機能を提供する名前空間
 */
namespace iterator
{
  /**
   * @class Iterator
   * @brief イテレータの抽象基底クラス
   * @tparam Item イテレートする要素の型
   */
  template <typename Item> class Iterator
  {
  public:
    virtual ~Iterator() = default;
    
    /**
     * @brief コンストラクタ
     * @param element 初期要素へのポインタ
     */
    Iterator(Item* element) : curItem{element} {};
    
    virtual auto Advance() -> Item& = 0;
    virtual auto Retreat() -> Item& = 0;
    virtual auto CanAdvance() const -> bool = 0;
    virtual auto CanRetreat() const -> bool = 0;
    virtual auto CurrentItem() const -> Item& = 0;
    
    /**
     * @brief 指定されたインデックスの要素を取得
     * @param index 取得する要素のインデックス
     * @return 指定されたインデックスの要素への参照
     */
    virtual auto GetItem(int index) const -> Item& = 0;
  
  protected:
    ElementPtr<Item> curItem; ///< 現在の要素へのポインタ
    int idx = 0; ///< 現在のインデックス
  };

  /**
   * @class BrowseIterator
   * @brief 閲覧用イテレータクラス
   * @tparam Item イテレートする要素の型
   */
  template <typename Item> class BrowseIterator : public Iterator<Item>
  {
  public:
    /**
     * @brief コンストラクタ
     * @param element 初期要素へのポインタ
     */
    BrowseIterator(Item* element) : Iterator<Item>(element) {}

    // メソッドの実装（省略）
  };

  /**
   * @class OperateIterator
   * @brief 操作用イテレータクラス
   * @tparam Item イテレートする要素の型
   */
  template <typename Item> class OperateIterator : public Iterator<Item>
  {
  public:

  };

  /**
   * @class AbstractArray
   * @brief 抽象配列クラス
   * @tparam Item 配列の要素の型
   */
  template <typename Item> class AbstractArray : public Iterator<Item>
  {
  public:
    virtual ~AbstractArray() = default;
    
    /**
     * @brief イテレータを作成する
     * @return 作成されたイテレータ
     */
    virtual auto CreateIterator() const -> std::unique_ptr<Iterator<Item>> = 0;
  };

}; // namespace iterator

#endif // ITERATOR_HPP