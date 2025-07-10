cmake_minimum_required(VERSION 3.20)
project(vkedu-format LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example
    examples/example.cpp
)

target_include_directories(example
  PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

if(BUILD_TESTS)
    include(FetchContent)
    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
    
    enable_testing()
    
    add_executable(format_tests
        tests/format.cpp
    )
    
    target_include_directories(format_tests
        PRIVATE
            ${PROJECT_SOURCE_DIR}/include
    )
    
    target_link_libraries(format_tests
        GTest::gtest
        GTest::gtest_main
    )
    
    include(GoogleTest)
    gtest_discover_tests(format_tests)
endif()