#include "common/commonType.hpp"
#include "file/FileDriver.hpp"
#include <fstream>

namespace fileDriver
{
/*
 * @brief ファイルに追加する実装が必要．
 * @todo  実装
*/
  auto TxtFileWriter::WriteData(const TxtData& data, OutputStream& file) -> ResultCode
  {
    try
    {
      file.close();
      return ResultCode::SUCCESS;
    }
    catch (const std::exception& e)
    {
      return ResultCode::ERROR;
    }
  };

  auto TxtFileReader::FormatData(InputStream& file, TxtData& data) -> ResultCode
  {
    try
    {
      Line line;
      while (std::getline(file, line))
      {
        data.AppendLine(line);
      }
      file.close();
    }
    catch (const std::exception& e)
    {
      return ResultCode::ERROR;
    }

    return ResultCode::SUCCESS;
  };
} // namespace fileDriver
