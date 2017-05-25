//
// Created by b.karjoo on 5/25/2017.
//

#ifndef BRIMUS3_BASKET_H
#define BRIMUS3_BASKET_H
#include "stdafx.h"

class basket {
    typedef std::set<std::string> strset;
    typedef std::shared_ptr<strset> strsetptr;
    strsetptr symbols = std::make_shared<strset>();
public:
    void parse_basket(std::string basket_definition);
    void add_symbol(std::string s) { symbols->insert(s);}
    bool has_symbol(std::string s) { return symbols->find(s) != symbols->end(); }
    int size() { return symbols->size(); }
    strsetptr get_basket() { return symbols; }
};


#endif //BRIMUS3_BASKET_H
