#ifndef FILEIO_HPP
#define FILEIO_HPP
#include "FileDriver.hpp"
#include "FileType.hpp"
namespace fileIO
{
    using namespace fileDriver;


    /*
     * @todo 暫定的にvoidを入れたが，本来は戻り値が分からないといけない．参照元のFileDriver.hppではテンプレートのため型が分からない．
     * @brief ファイルマネージャーにFileIOの機能を提供する．使用する際になんの機能が欲しいか引数で選択できるようにする．
    */
    class FileIO
    {
        public:
            virtual ~FileIO();
            virtual auto CreateFileWriter(fileSystem::FileType extension) -> File;
            virtual auto CreateFileReader(fileSystem::FileType extension) -> File;
    };


};
#endif