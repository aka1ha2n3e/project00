#ifndef COMMONTYPE_HPP
#define COMMONTYPE_HPP

#include <filesystem>
#include <string>

/**
 * @namespace data
 * @brief データ関連の型や定数を定義する名前空間
 */
namespace data
{
};

/**
 * @namespace loging
 * @brief ロギング関連の型や定数を定義する名前空間
 */
namespace loging
{
  /// @brief 文字列型の別名
  using String = std::string;

  /**
   * @enum LogLevel
   * @brief ログレベルを定義する列挙型
   */
  enum class LogLevel {
      INFO,         ///< 情報レベルのログ
      WARNING,      ///< 警告レベルのログ
      ERROR,        ///< エラーレベルのログ
      DEBUG,        ///< デバッグレベルのログ
      USER_ACTION,  ///< ユーザーアクションのログ
  };
};

/**
 * @namespace fileSystem
 * @brief ファイルシステム関連の型や定数を定義する名前空間
 */
namespace fileSystem
{
  /// @brief ファイルパス型の別名
  using Path = std::filesystem::path;
  /// @brief ディレクトリ
  using Directory = std::string;
  /// @brief ファイル名
  using FileName = std::string;

  /// @brief バイト型の別名
  using Byte = std::byte;
  /// @brief 1行のテキスト
  using Line = std::string;

  enum class ResultCode
  {
    SUCCESS,
    ERROR,
    UNKNOWN,
  };
};// namespace fileSystem

/**
 * @namespace utils
 * @brief ユーティリティ関連の型や定数を定義する名前空間
 */
namespace utils
{
  /// @brief 文字
  using String = std::string;
};

/**
 * @namespace textEditor
 * @brief テキストエディタ関連
 */
namespace textEditor
{
  /// @brief 文字列名
  using String = std::string;
  /// @brief ユーザーが入力したデータ
  using Coordinate = int;
  /// @brief 1行のテキスト
  using Line = std::string;

  // 操作結果を表す列挙型
  enum class ResultCode
  {
    SUCCESS,
    FAILURE,
    INVALID_OPERATION,
  };

  // エディタのファイル操作状態を表す列挙型
  enum class FileOperationState
  {
    EDITING,
    SAVING,
    LOADING,
  };
};// namespace textEditor

/**
 * @namespace UI
 * @brief ユーザーインターフェース関連の型や定数を定義する名前空間
 */
namespace UI
{
  /// @brief 文字列
  using String = std::string;
  /// @brief 表示座標
  using Coordinate = int;
};

/*
* 
*/
namespace input
{
enum class ResultCode
{
  SUCCESS,
  FAILURE,
  INVALID_OPERATION,
};
};

#endif // COMMONTYPE_HPP