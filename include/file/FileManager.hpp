#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include "file/FileIO.hpp"
#include "common/generalType.hpp"

/**
 * @namespace fileManager
 * @brief ファイル管理に関する機能を提供する名前空間
 */
namespace fileManager
{
    using namespace fileIO;

    /**
     * @class FileManager
     * @brief ファイル管理を行うクラス
     */
    class FileManager
    {
    public:
        FileManager(fileSystem::FileType extension);
    
    private:
        ContextPtr<FileIO> format; ///< ファイルI/Oフォーマット

        /**
         * @brief FileIOオブジェクトを作成する
         * @param extension ファイルの拡張子
         * @return 作成されたFileIOオブジェクトへのユニークポインタ
         */
        auto CreateFileIO(fileSystem::FileType extension) -> std::unique_ptr<FileIO>;
    };

}
#endif