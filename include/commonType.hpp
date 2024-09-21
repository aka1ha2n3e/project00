#ifndef COMMONTYPE_HPP
#define COMMONTYPE_HPP


#include <filesystem>

namespace data
{
};

namespace loging
{
  using String = std::string;
  enum class LogLevel {
      INFO,
      WARNING,
      ERROR,
      DEBUG,
      USER_ACTION,
  };
};

namespace fileSystem
{

  using Path = std::filesystem::path;
  using Directory = std::string;
  using FileName = std::string;

  using Byte = std::byte;
  using Line = std::string;
};

namespace utils
{
  using String = std::string;
};

namespace textEditor
{
  using String = std::string;
  //using TextBuffer = std::vector<String>; /**< 文字データの保管場所 */
  using Key = int;                        /**< ユーザーが入力したデータ */
};

namespace UI
{
  using String = std::string;
  using Coordinate = int; /**< 表示する座標 */
};


#endif // COMMONTYPE_HPP
