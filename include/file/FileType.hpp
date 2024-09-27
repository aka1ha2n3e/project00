
#ifndef FILETYPE_HPP_
#define FILETYPE_HPP_

#include "file/FileData.hpp"
#include "common/generalType.hpp"


namespace fileSystem
{

    class File
    {
    };
  class TxtFile : public File
  {
     public:
        FileContents<TxtData> contents;
  };
};// namespace fileSystem.hpp

#endif //FILETYPE_HPP