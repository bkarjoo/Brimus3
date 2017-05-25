//
// Created by b.karjoo on 5/25/2017.
//
#include "gtest/gtest.h"
#include "input_file_parser.h"

TEST(inputFileParserTests, loadFile)
{
    input_file_parser ifp("loadfile.strat");
    EXPECT_EQ(1445, ifp.size());
}

TEST(inputFileParserTests, getFirstCommand)
{
    input_file_parser ifp("loadfile.strat");
    auto a = ifp.get_command();
    EXPECT_EQ("comment", a);
}

TEST(inputFileParserTests, getFirstCommandDetails)
{
    input_file_parser ifp("loadfile.strat");
    ifp.get_command();
    auto a = ifp.get_details();
    EXPECT_EQ("{short comment}", a);
}

TEST(inputFileParserTests, getAllCommands)
{
    input_file_parser ifp("loadfile.strat");
    ifp.parse_commands();
    auto a = ifp.getTick_commands();
    EXPECT_EQ(5, a->size());
}


