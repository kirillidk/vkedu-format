#pragma once

#include <stdexcept>
#include <string>

namespace vkedu {
namespace utility {

class InvalidBracesArgumentException : public std::invalid_argument {
public:
    explicit InvalidBracesArgumentException(const std::string& message)
        : std::invalid_argument(message) {}
};

class FormatArgumentsException : public std::out_of_range {
public:
    explicit FormatArgumentsException(const std::string& message)
        : std::out_of_range(message) {}
};

}  // namespace utility
}  // namesapce vkedu