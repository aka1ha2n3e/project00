#ifndef FILEDATA_HPP
#define FILEDATA_HPP

#include <vector>
#include "common/commonType.hpp"
#include "iterator/iterator.hpp"



/**
 * @namespace fileSystem
 * @brief ファイルシステム関連の機能を提供する名前空間
 */
namespace fileSystem
{
    /**
     * @enum FileType
     * @brief ファイルタイプを表す列挙型
     */
    enum class FileType
    {
        TXT, ///< テキストファイル
    };

    /**
     * @class TxtData
     * @brief テキストデータを管理するクラス
     */
    class TxtData : public iterator::AbstractArray<Line>
    {
    public:
        /**
         * @brief 行を追加する
         * @param input 追加する行
         */
        auto AppendLine(const Line input) -> void;

        /**
         * @brief 最初の行を取得する
         * @return 最初の行への参照
         */
        auto GetFirstLine() -> Line& { return data.front(); }

        /**
         * @brief イテレータを作成する
         * @return 作成されたイテレータへのユニークポインタ
         */
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<Line>> override;

        auto operator[](int idx) -> Line&;

    private:
        std::vector<Line> data; ///< テキストデータの保存先
    };

}; // namespace fileSystem

#endif // FILEDATA_HPP