cmake_minimum_required(VERSION 3.16)
project(MyProject)

# FetchContent for GoogleTest (optional if not using Conan)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Include the Conan toolchain before defining targets
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# Enable testing
enable_testing()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add executable target for your tests
add_executable(my_tests test/main_test.cpp src/Operations.cpp)

# Link libraries (Conan libraries and GoogleTest)
find_package(GTest REQUIRED)
target_link_libraries(my_tests gtest gtest_main)

# Enable code coverage flags if building in Debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Add a custom target to run tests and generate coverage report
add_custom_target(
    coverage    
    COMMAND ./my_tests
    COMMAND lcov --capture --directory . --output-file coverage.info
    COMMAND genhtml --rc geninfo_unexecuted_blocks=1 --ignore-errors mismatch coverage.info --output-directory out
    DEPENDS my_tests
)

# Add CTest support
add_test(NAME my_project_tests COMMAND ${CMAKE_BINARY_DIR}/my_tests)

# Include directories (if needed for your project)
include_directories(${CMAKE_SOURCE_DIR}/inc)


# Link libraries (e.g., Conan libraries, GTest, etc.)
target_link_libraries(my_tests PRIVATE ${CONAN_LIBS})
