#ifndef FILEDRIVER_HPP
#define FILEDRIVER_HPP

#include "logging/Logger.hpp"
#include "common/commonType.hpp"
#include "file/FileData.hpp"
#include <fstream>

/**
 * @namespace fileDriver
 * @brief ファイル操作に関する機能を提供する名前空間
 */
namespace fileDriver
{
  using namespace fileSystem;

  using OutputStream = std::ofstream;
  using InputStream  = std::ifstream;

  /**
   * @class FileReader
   * @brief ファイル読み込みの抽象基底クラス
   * @tparam DataType 読み込むデータの型
   */
  template <typename DataType>
  class FileReader
  {
  public:
    virtual ~FileReader() = default;

    /**
     * @brief ファイルを読み込むメソッド
     * @param filePath 読み込むファイルのパス
     * @param inputData 読み込んだデータを格納する変数
     * @return 処理結果のコード
     */
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
    /**
     * @brief ファイルデータを指定の型に変換する純粋仮想関数
     * @param file 入力ストリーム
     * @param data 変換されたデータを格納する変数
     * @return 処理結果のコード
     */
    virtual auto FormatData(InputStream& file, DataType& data) -> ResultCode = 0;
  };

  /**
   * @class FileWriter
   * @brief ファイル書き込みの抽象基底クラス
   * @tparam DataType 書き込むデータの型
   */
  template <typename DataType>
  class FileWriter
  {
  public:
    virtual ~FileWriter() = default;

    /**
     * @brief ファイルに保存するメソッド
     * @param outputData 保存するデータ
     * @param filePath 保存先のファイルパス
     * @return 処理結果のコード
     */
    auto SaveFile(const DataType outputData, const Path& filePath) -> ResultCode
    {
      return SaveFileImpl(outputData,filePath);
    }

  protected:
    /**
     * @brief データをファイルに書き込む純粋仮想関数
     * @param data 書き込むデータ
     * @param file 出力ストリーム
     * @return 処理結果のコード
     */
    virtual auto WriteData(const DataType& data, OutputStream& file) -> ResultCode = 0;

  private:
    /**
     * @brief ファイル保存の実装メソッド
     * @param outputData 保存するデータ
     * @param filePath 保存先のファイルパス
     * @return 処理結果のコード
     */
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

  /**
   * @class TxtFileReader
   * @brief テキストファイル読み込みクラス
   */
  class TxtFileReader : public FileReader<TxtData>
  {
  private:
    /**
     * @brief テキストデータをフォーマットするメソッド
     * @param file 入力ストリーム
     * @param data フォーマットされたデータを格納する変数
     * @return 処理結果のコード
     */
    auto FormatData(InputStream& file, TxtData& data) -> ResultCode override;
  };

  /**
   * @class TxtFileWriter
   * @brief テキストファイル書き込みクラス
   */
  class TxtFileWriter : public FileWriter<TxtData>
  {
  private:
    /**
     * @brief テキストデータをファイルに書き込むメソッド
     * @param outputData 書き込むデータ
     * @param file 出力ストリーム
     * @return 処理結果のコード
     */
    auto WriteData(const TxtData& outputData, OutputStream& file) -> ResultCode override;
  };

} // namespace FileDriver
#endif