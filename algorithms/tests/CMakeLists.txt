file(GLOB ALG_TEST_SOURCES "*.cpp" "../*.cpp")

add_executable(AlgTests ${ALG_TEST_SOURCES})

target_include_directories(AlgTests PRIVATE ${CMAKE_SOURCE_DIR}/algorithms)

target_link_libraries(AlgTests PRIVATE gtest gtest_main)

add_test(NAME AlgTests COMMAND AlgTests)