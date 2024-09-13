#ifndef FILEDRIVER_HPP
#define FILEDRIVER_HPP

#include "Logger.hpp"
#include "type.hpp"
#include <fstream>
namespace fileDriver
{

  using namespace fileSystem;

  using OutputStream = std::ofstream;
  using InputStream  = std::ifstream;
  //抽象クラス
  template <typename DataType>
  class FileReader
  {
  public:
    virtual ~FileReader() = default;
    auto ReadFile(const Path& filePath, DataType& inputData) -> ResultCode
    {
      InputStream file(filePath);

      if (!file.is_open())
      {
        return ResultCode::ERROR;
      }

      try
      {
        return FormatData(file, inputData);
      }
      catch (const std::exception& e)
      {
        return ResultCode::ERROR;
      }
    };

  protected:
    // ファイルを第二引数の型に合わせて調整する。
    virtual auto FormatData(InputStream& file, DataType& data) -> ResultCode = 0;
  };


    template <typename DataType>
  class FileWriter
  {
  public:
    virtual ~FileWriter() = default;
    auto SaveFile(const DataType outputData, const Path& filePath) -> ResultCode
    {
      return SaveFileImpl(outputData,filePath);
    }
  protected:

    virtual auto WriteData(const DataType& data, OutputStream& file) -> ResultCode = 0;
  private:
    auto SaveFileImpl( const DataType& outputData, const Path& filePath) -> ResultCode
    {
      OutputStream file(filePath);

      if (!file.is_open())
      {
        return ResultCode::ERROR;
      }

      try
      {
        return WriteData( outputData, file);
      }
      catch (const std::exception& e)
      {
        return ResultCode::ERROR;
      }
    };
  };

  //実装クラス
  class TxtFileReader : public FileReader<TxtData>
  {
  private:
    auto FormatData(InputStream& file, TxtData& data) -> ResultCode override;
  };

  class TxtFileWriter : public FileWriter<TxtData>
  {
  private:
    auto WriteData(const TxtData& outputData, OutputStream& file) -> ResultCode override;
  };

} // namespace FileDriver
#endif
