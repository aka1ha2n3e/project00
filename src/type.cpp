#include "type.hpp"

namespace fileSystem
{
    auto TxtData::AppendLine(Line input) -> void
    {
      data.push_back(input);
    }

    auto TxtData::operator[](int idx) -> Line&
    {
      return data[idx];
    }
};
