#ifndef FILETYPE_HPP_
#define FILETYPE_HPP_

#include "iterator.hpp"
#include "commonType.hpp"

namespace fileSystem
{
    enum class FileType
    {
        TXT,
    };
    class TxtData : public iterator::AbstractArry<Line>
    {
        public:
        auto AppendLine(const Line input) -> void;
        auto GetFirstLine() -> Line&{return data.front();};
        auto CreateIterator() const -> std::unique_ptr<iterator::Iterator<Line>> override;

        auto operator[](int idx) -> Line&;
        private:
        std::vector<Line> data;
            
    };
};// namespace fileSystem.hpp

#endif // FILETYPE_HPP_