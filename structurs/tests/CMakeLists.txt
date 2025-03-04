file(GLOB STRUCT_TEST_SOURCES "*.cpp")

add_executable(StrTests ${STRUCT_TEST_SOURCES})

target_include_directories(StrTests PRIVATE ${CMAKE_SOURCE_DIR}/structurs)

target_link_libraries(StrTests PRIVATE gtest gtest_main)

add_test(NAME StrTests COMMAND StrTests)