//
// Created by b.karjoo on 5/25/2017.
//
#include "gtest/gtest.h"
#include "basket.h"
#include <iostream>
using namespace std;
TEST(basketTests, parseTest) {
    basket b;
    b.parse_basket("SPY GE AMZN");
    cout << endl;
    for (auto a : *b.get_basket())
        cout << a << endl;
    EXPECT_EQ(3,b.size());
}

