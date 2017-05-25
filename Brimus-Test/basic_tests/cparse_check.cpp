//
// Created by b.karjoo on 5/25/2017.
//
#include "gtest/gtest.h"
#include "shunting-yard.h"
#include <iostream>

using namespace std;

TEST(cparseTests, testOne)
{
    TokenMap vars;
    vars["x"] = 45;
    calculator c1;
    c1.compile("x", vars);
    cout << c1.eval(vars) << endl;
    vars["x"] = 20;
    cout << c1.eval(vars) << endl;
    double answer = c1.eval(vars).asDouble();
    cout << answer << endl;
    calculator c2("5");
    cout << c2.eval().asInt() << endl;
}