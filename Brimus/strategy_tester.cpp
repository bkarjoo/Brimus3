//
// Created by b.karjoo on 5/24/2017.
//

#include "strategy_tester.h"

using namespace std;


strategy_tester::strategy_tester(const std::vector<std::string> &inputs) {
    for (auto a : inputs)
        input_files.push_back(a);
}

strategy_tester::strategy_tester(const std::vector<std::string> &inputs, const std::string &output) {
    for (auto a : inputs)
        input_files.push_back(a);
    output_directory = output;
}

void strategy_tester::run() {
    cout << "running strategy" << endl;
}
