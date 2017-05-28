//
// Created by b.karjoo on 5/24/2017.
//

#include "launch_rules.h"
#include <boost/algorithm/string/replace.hpp>
using namespace std;

launch_rules::bdate launch_rules::convert_to_gregorian(std::string primusDate) {
    int i = 0;
    char c = primusDate[i++];
    string year,month,day;
    bool monthSet = false, daySet = false;
    if (c != '#') throw new std::invalid_argument("launch rule format error");
    while (i<primusDate.size()){
        c=primusDate[i++];
        if (c == '-') if (month.size() == 1) monthSet = true;
        if (c == '#') if (day.size() == 1) daySet = true;
        if (year.size() < 4)
            year += c;
        else if(month.size() < 2 && !monthSet && c != '-') {
            month += c;
        } else if(day.size() < 2 && !daySet && c != '-') {
            day += c;
        }
    }
    try {
        bdate dd(
                (unsigned short)stoi(year),
                (unsigned short)stoi(month),
                (unsigned short)stoi(day));
        return dd;
    } catch (...) {
        return {};
    }
}

/*
 * what would the parsed rules be stored as? as a string for cparse
 * when you get to a #, you read to the next #, converto to julian, replace it all
 */
string launch_rules::parse_launch_rules(std::string launchRules) {
    // launch rules is a copy
    int i=0; char c; string results;
    boost::algorithm::replace_all(launchRules,"AND","&&");
    boost::algorithm::replace_all(launchRules,"OR","||");
    boost::algorithm::replace_all(launchRules,"And","&&");
    boost::algorithm::replace_all(launchRules,"Or","||");
    boost::algorithm::replace_all(launchRules,"and","&&");
    boost::algorithm::replace_all(launchRules,"or","||");
    while(i<launchRules.size()) {
        c=launchRules[i++];
        if (c=='#'){
            i--;

            string one_date = get_launch_rule(launchRules,i);
            bdate date = convert_to_gregorian(one_date);
            int julian= date.julian_day();
            results += to_string(julian);
        }
        else
            results += c;
    }
    return results;
}

string launch_rules::get_launch_rule(const std::string &basic_string, int &i) {
    // format of chars to pick up is #2017-1-1# or #2017-01-01#
    string lr;
    lr += basic_string[i++];
    if (lr != "#") throw new std::invalid_argument("launch rule format error");
    while (i<basic_string.size()) {
        lr += basic_string[i++];
        if (lr[lr.size()-1] == '#') break;
    }
    return lr;
}

void launch_rules::set_claculator(std::string launch_rules) {
    vars = make_unique<TokenMap>();
    (*vars)["CurrentDate"] = 0;
    rules = make_unique<calculator>();
    rules_str = launch_rules;
}

bool launch_rules::is_run_date(launch_rules::bdate date) {
    // TODO: need to convert the date to julian
    int jDate = date.julian_day();
    // TODO: need to set it as a var
    (*vars)["CurrentDate"] = jDate;
    // TODO: nned to call calculate
    packToken results = rules->calculate(rules_str.c_str(),*vars);
    return results.asBool();
}

