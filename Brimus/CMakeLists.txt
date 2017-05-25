add_library(Brimus input_file_parser.cpp input_file_parser.h strategy_tester.cpp strategy_tester.h stdafx.h launch_rules.cpp launch_rules.h command.cpp command.h basket.cpp basket.h)

target_include_directories(Brimus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})