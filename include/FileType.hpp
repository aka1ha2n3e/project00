
#ifndef FILETYPE_HPP_
#define FILETYPE_HPP_

#include "FileData.hpp"
#include "generalType.hpp"


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