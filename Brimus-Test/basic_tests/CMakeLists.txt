include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicBrimusTests sample.cpp)

target_link_libraries(runBasicBrimusTests gtest gtest_main)
target_link_libraries(runBasicBrimusTests Brimus)