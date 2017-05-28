//
// Created by b.karjoo on 5/24/2017.
//

#ifndef BRIMUS3_LAUNCH_RULES_H
#define BRIMUS3_LAUNCH_RULES_H

#include "stdafx.h"
#include "shunting-yard.h"

/*
 * 1. converts the launch rules to gregorian date
 * 2. replaces the rules string with julian dates
 * 3. creates a variable called current date
 * 4. creates a cparser calculator for evaluating the date rules
 * 5. contains_date functions return bool for running the strategy
 */
class launch_rules {
    typedef boost::gregorian::date bdate;
    std::unique_ptr<calculator> rules;
    std::unique_ptr<TokenMap> vars;
    std::string rules_str;
public:
    bdate convert_to_gregorian(std::string primusDate);
    std::string parse_launch_rules(std::string launchRules);
    std::string get_launch_rule(const std::string &basic_string, int &i);

    void set_claculator(std::string launch_rules);
    // TODO : in gtest test using the set calculator
    // TODO : make function bool run_today(boost::gregorian::date)
    bool is_run_date(bdate date);
};


#endif //BRIMUS3_LAUNCH_RULES_H
