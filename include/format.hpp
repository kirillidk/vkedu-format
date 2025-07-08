#pragma once

#include <string>
#include <vector>
#include <type_traits>  // std::is_constructible_v
#include <sstream>
#include <string_view>

namespace vkedu {
namespace utility {

template <typename T>
[[nodiscard]] std::string to_string(T&& value) {
    if constexpr (std::is_constructible_v<std::string, T>) {
        return {std::forward<T>(value)};
    } else {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }
}

template <typename... Ts>
[[nodiscard]] std::vector<std::string> parse_args(Ts&&... Args) {
    return {to_string(std::forward<Ts>(Args))...};
}

}  // namespace utility

template <typename... Ts>
[[nodiscard]] std::string format(std::string_view fmt, Ts&&... Args) {
    std::vector<std::string> str_args =
        utility::parse_args(std::forward<Ts>(Args)...);

    std::string result {};

    for (size_t i = 0; i < fmt.size(); ++i) {
        if (fmt[i] == '{') {
            std::string ind_str {};

            ++i;
            while (i < fmt.size() && fmt[i] != '}') {
                ind_str.push_back(fmt[i]);
                ++i;
            }

            size_t ind = std::stoll(ind_str);
            result.append(str_args[ind]);
        } else {
            result.push_back(fmt[i]);
        }
    }

    return result;
}

}  // namespace vkedu