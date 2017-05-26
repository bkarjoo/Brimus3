//
// Created by b.karjoo on 5/25/2017.
//
#include "gtest/gtest.h"
#include "basket.h"
#include "input_file_parser.h"

using namespace std;
TEST(basketTests, parseTest) {
    basket b;
    b.parse_basket("SPY GE AMZN");
    cout << endl;
//    for (auto a : *b.get_basket())
//        cout << a << endl;
    EXPECT_EQ(3,b.size());
}

TEST(basketTest, parseFile) {
    basket b;
    input_file_parser ifp("loadfile.strat");
    ifp.parse_commands();
    auto a = ifp.getOnce_commands();

    EXPECT_EQ(2,a->size());
    EXPECT_EQ("basket_symbols",(*a)[0]->name);
    b.parse_basket((*a)[0]->instruction);
//    for (auto a : *b.get_basket())
//        cout << a << endl;
    EXPECT_EQ(6, b.size());

    EXPECT_EQ("basket_ignore",(*a)[1]->name);
    basket b2;
    b2.parse_basket((*a)[1]->instruction);
//    for (auto a : *b2.get_basket())
//        cout << a << endl;
    EXPECT_EQ(1, b2.size());
}