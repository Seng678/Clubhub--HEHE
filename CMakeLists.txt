cmake_minimum_required(VERSION 3.28)
project(clubhub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(clubhub_core
    src/event.cpp
    src/event_csv.cpp
    src/Student.cpp
)
target_include_directories(clubhub_core PUBLIC include)
if(MSVC)
    target_compile_options(clubhub_core PRIVATE /W4)
else()
    target_compile_options(clubhub_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(clubhub src/cli/main.cpp)
target_link_libraries(clubhub PRIVATE clubhub_core)

# --- Tests (CTest + GoogleTest) ---
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(StudentPrivacyTest tests/StudentPrivacyTest.cpp)
target_link_libraries(StudentPrivacyTest PRIVATE clubhub_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(StudentPrivacyTest)