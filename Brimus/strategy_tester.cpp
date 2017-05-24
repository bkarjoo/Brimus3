//
// Created by b.karjoo on 5/24/2017.
//

#include "strategy_tester.h"

using namespace std;


strategy_tester::strategy_tester(const std::vector<std::string> &inputs) {
    for (auto a : inputs)
        cout << a << endl;
}

strategy_tester::strategy_tester(const std::vector<std::string> &inputs, const std::string &output) {
    for (auto a : inputs)
        cout << a << endl;
    cout << "output: " << output << endl;
}

void strategy_tester::run() {
    cout << "running strategy" << endl;
}
