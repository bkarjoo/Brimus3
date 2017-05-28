//
// Created by b.karjoo on 5/26/2017.
//
#include "gtest/gtest.h"
#include "launch_rules.h"
#include "shunting-yard.h"

using namespace std;
TEST(launchRulesTests, captureLaunchRule) {
    launch_rules lr;
    string theRuleStr{"CurrentDate > #2017-1-1#"};
    int i = 14;
    string result = lr.get_launch_rule(theRuleStr,i);
    EXPECT_EQ("#2017-1-1#",result);
    theRuleStr = "CurrentDate > #2017-01-01#";
    i = 14;
    result = lr.get_launch_rule(theRuleStr,i);
    EXPECT_EQ("#2017-01-01#",result);
}

TEST(launchRulesTests, convertToGreg) {
    string s1 = "#2017-1-1#";
    string s2 = "#2017-01-01#";

    boost::gregorian::date d1(2017,1,1);

    launch_rules lr;

    EXPECT_EQ(d1, lr.convert_to_gregorian(s1));
    EXPECT_EQ(d1, lr.convert_to_gregorian(s2));
}

TEST(launchRulesTests, julian) {
    string s1 = "#2017-1-1#";
    string s2 = "#2017-01-01#";

    boost::gregorian::date d1(2017,1,1);

    launch_rules lr;

    EXPECT_EQ(2457755, d1.julian_day());
}

TEST(launchRulesTests, replaceWithJulian) {
    string s1 = "(CurrentDate >= #2011-03-14# AND CurrentDate <= #2011-05-17#)";
    string s2 = "(CurrentDate >= 2455635 AND CurrentDate <= 2455699)";
    launch_rules lr;
    string s3 = lr.parse_launch_rules(s1);
    EXPECT_EQ(s2,s3);
}

TEST(launchRulesTests, shuntingYardTest) {
    string s1 = "(CurrentDate >= #2011-03-14# && CurrentDate <= #2011-05-17#)";
    launch_rules lr;
    string sParse = lr.parse_launch_rules(s1);
    lr.set_claculator(sParse);
    // TODO: make the function to test against the calculator
    boost::gregorian::date d1(2011,3,14);
    EXPECT_EQ(true,lr.is_run_date(d1));
}
