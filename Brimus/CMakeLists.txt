add_library(Brimus input_strategy_file.cpp input_strategy_file.h strategy_tester.cpp strategy_tester.h stdafx.h launch_rules.cpp launch_rules.h)

target_include_directories(Brimus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})