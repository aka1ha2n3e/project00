#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP
#include "FileIO.hpp"
namespace fileManager
{
    using namespace fileIO;

    class FileManager
    {
        public:
        virtual ~FileManager();
        virtual auto CreateFileIO() -> std::unique_ptr<FileIO> = 0;
    };

    class TxtFileManager
    {
        public:
        auto CreateFileIO() -> std::unique_ptr<FileIO>;
    };
}
#endif