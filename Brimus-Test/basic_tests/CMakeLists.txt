include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicBrimusTests sample.cpp input_file_parser_check.cpp basket_check.cpp launch_rules_check.cpp)

target_link_libraries(runBasicBrimusTests gtest gtest_main)
target_link_libraries(runBasicBrimusTests Brimus)
target_link_libraries(runBasicBrimusTests CParse)