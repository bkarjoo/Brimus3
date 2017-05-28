//
// Created by b.karjoo on 5/24/2017.
//

#ifndef BRIMUS3_STRATEGY_TESTER_H
#define BRIMUS3_STRATEGY_TESTER_H

#include "stdafx.h"
#include "input_file_parser.h"


class strategy_tester {
    std::vector<std::string> input_files;
    std::string output_directory = "results";
    std::unique_ptr<input_file_parser> parsed_input = nullptr;
public:
    strategy_tester(const std::vector<std::string>& inputs);
    strategy_tester(const std::vector<std::string>& inputs, const std::string& output);
    void run();
};


#endif //BRIMUS3_STRATEGY_TESTER_H
