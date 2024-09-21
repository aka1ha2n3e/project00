#ifndef TYPE_HPP_
#define TYPE_HPP_

#include <string>
#include <vector>
#include "FileType.hpp"
#include "commonType.hpp"
#include "iterator.hpp"
#include "generalType.hpp"



namespace data
{
}; // namespace data


namespace loging
{
};

namespace fileSystem{

  class TxtFile : public FileContents<TxtData>
  {
  };

  enum class ResultCode
  {
    SUCCESS,
    ERROR,
    UNKNOWN,
  };
} // namespace fileSystem

namespace utils
{
} // namespace utils

namespace textEditor
{

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
} // namespace textEditor

namespace UI
{
} // namespace UI
#endif // TYPE_HPP_
