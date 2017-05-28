//
// Created by b.karjoo on 5/24/2017.
//

#include "strategy_tester.h"

using namespace std;


strategy_tester::strategy_tester(const std::vector<std::string> &inputs) {
    for (auto a : inputs)
        input_files.push_back(a);
    // TODO : file must be parsed
    // TODO : it's functions must be converted to 3 categories
}

strategy_tester::strategy_tester(const std::vector<std::string> &inputs, const std::string &output) {
    for (auto a : inputs)
        input_files.push_back(a);
    output_directory = output;
}

void strategy_tester::run() {
    cout << "running strategy" << endl;
    // TODO: parse the input file
        // TODO: own a parser file (has set of rule vectors)

    input_file_parser ifp(input_files[0]);
    auto once_rules = ifp.getOnce_commands();
    auto daily_rules = ifp.getOpening_commands();
    auto tick_rules = ifp.getTick_commands();
    // TODO: set up launch rule
    // TODO: run opening functions
    // TODO: setup loops
    // TODO: outer loop each day functions
    // TODO: inner loop each tick functions
}
