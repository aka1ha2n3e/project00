#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include "FileIO.hpp"
namespace fileManager
{
    using namespace fileIO;

    class FileManager
    {
        public:
        auto CreateFileIO(fileSystem::FileType extension) -> std::unique_ptr<FileIO>;
    };

}
#endif