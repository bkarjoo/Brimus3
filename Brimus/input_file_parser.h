//
// Created by b.karjoo on 5/24/2017.
//

#ifndef BRIMUS3_INPUT_STRATEGY_FILE_H
#define BRIMUS3_INPUT_STRATEGY_FILE_H
#include "command.h"
#include "stdafx.h"

// Single Responsibility : parse the file
// results are 7 categories of tokens
class input_file_parser {
    int file_index = 0;
    int line_number = 1;
    std::vector<command*>* once_commands = new std::vector<command*>;
    std::vector<command*>* opening_commands = new std::vector<command*>;
    std::vector<command*>* tick_commands = new std::vector<command*>;
    std::string file;
public:
    input_file_parser(std::string input_file);

    std::vector<command *> *getOnce_commands() const;

    std::vector<command *> *getOpening_commands() const;

    std::vector<command *> *getTick_commands() const;

    void parse_commands();
    int size() { return file.size(); }
    std::string get_command();

    std::string get_details();
};


#endif //BRIMUS3_INPUT_STRATEGY_FILE_H
