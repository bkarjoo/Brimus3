//
// Created by b.karjoo on 5/24/2017.
//

#ifndef BRIMUS3_STRATEGY_TESTER_H
#define BRIMUS3_STRATEGY_TESTER_H

#include "stdafx.h"

/*
 * parses the input files
 * files request a range of functions (place them in function map)
 * function updated before rule check
 * use boost observer utilities
 * creates calculator parser for the basket rules (not symbol list)
 * creates calculator parser for the launch rules
 * creates calculator parsers for each order
 * creates a calculator parser for each variable
 */
class strategy_tester {

public:
    strategy_tester(const std::vector<std::string>& inputs);
    strategy_tester(const std::vector<std::string>& inputs, const std::string& output);
    void run();
};


#endif //BRIMUS3_STRATEGY_TESTER_H
