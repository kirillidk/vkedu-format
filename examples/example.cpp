#include <iostream>
#include <format.hpp>
#include <cassert>

int main() {
    auto text = vkedu::format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");
}