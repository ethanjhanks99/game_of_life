cmake_minimum_required(VERSION 3.12)

set(PROJECT ConwaysLife)
set(UNIT_TEST_RUNNER UnitTestRunner)

set(HEADER_FILES
    LifeSimulator.hpp
    PatternAcorn.hpp
    PatternBlinker.hpp
    PatternBlock.hpp
    PatternGlider.hpp
    PatternGosperGliderGun.hpp
    PatternPulsar.hpp
    RendererConsole.hpp
    Pattern.hpp
    Renderer.hpp
    rlutil.h)

set(SOURCE_FILES 
    LifeSimulator.cpp
    PatternAcorn.cpp
    PatternBlinker.cpp
    PatternBlock.cpp
    PatternGlider.cpp
    PatternGosperGliderGun.cpp
    PatternPulsar.cpp
    RendererConsole.cpp)

set(UNIT_TEST_FILES 
    TestGameOfLife.cpp)

project(${PROJECT})

add_executable(${PROJECT} ${HEADER_FILES} ${SOURCE_FILES} main.cpp)
add_executable(${UNIT_TEST_RUNNER} ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES})

set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD 23)
set_property(TARGET ${UNIT_TEST_RUNNER} PROPERTY CXX_STANDARD 23)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(${PROJECT} PRIVATE /W4 /permissive-)
  target_compile_options(${UNIT_TEST_RUNNER} PRIVATE /W4 /permissive-)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(${PROJECT} PRIVATE -Wall -Wextra -pedantic)
  target_compile_options(${UNIT_TEST_RUNNER} PRIVATE -Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  target_compile_options(${PROJECT} PRIVATE -Wall -Wextra -pedantic)
  target_compile_options(${UNIT_TEST_RUNNER} PRIVATE -Wall -Wextra -pedantic)
endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)

    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES} main.cpp)
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()

    add_custom_target(
        ClangFormat
        COMMAND ${CLANG_FORMAT}
        -i
        -style=file
        ${SOURCE_FILES_PATHS})

    add_dependencies(${PROJECT} ClangFormat)

endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY  https://github.com/google/googletest.git
  GIT_TAG         v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googleTest)

target_link_libraries(${UNIT_TEST_RUNNER} gtest_main)
