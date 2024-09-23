#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include "FileIO.hpp"
#include "generalType.hpp"

namespace fileManager
{
    using namespace fileIO;

    class FileManager
    {
        public:
        FileManager(fileSystem::FileType extension);
        private:
        ContextPtr<FileIO> format;
        auto CreateFileIO(fileSystem::FileType extension) -> std::unique_ptr<FileIO>;
    };

}
#endif