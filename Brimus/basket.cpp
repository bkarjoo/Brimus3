//
// Created by b.karjoo on 5/25/2017.
//

#include "basket.h"

using namespace std;

void basket::parse_basket(std::string basket_definition) {
    string s;
    for (auto a : basket_definition) {
        if (a != '\n' && a != '\t' && a != 32) {
            s += a;
        }
        if (s != "" & (a == '\n' || a == '\t' || a == 32)) {
            symbols->insert(s);
            s = "";
        }
    }
    if (s != "") symbols->insert(s);
}
