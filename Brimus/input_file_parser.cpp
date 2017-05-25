//
// Created by b.karjoo on 5/24/2017.
//

#include "input_file_parser.h"
#include <fstream>
using namespace std;


string input_file_parser::get_command() {
    string s;
    char c;
    bool initialized = false;
    bool open_for_addition = true;
    while (true) {
        if (file_index < file.size())
        {
            c = file[file_index++];
            if (c == '\n') line_number++;
            if (!initialized && (c == 32 || c == '\n')) continue;
            if (c == '{') {
                file_index--;
                return s;
            }
            if (c != 32 && c != '{' && c != '\n' && c != '\t') {

                if (open_for_addition)
                    s += c;
                else
                    throw new std::invalid_argument("Error in file format");
            }
            if (s.size() == 1) initialized = true;
            if (initialized && c == ' ') open_for_addition = false;
        } else
            break;
    }
    return s;
}

input_file_parser::input_file_parser(std::string input_file) {
    ifstream fs(input_file);
    char c;
    while (fs.get(c)) file += c;
    fs.close();
}

std::string input_file_parser::get_details() {
    string  s;
    char c;
    bool initialized = false;
    int open_brackets = 0;
    while (true) {
        if (file_index < file.size())
        {
            c = file[file_index++];
            if (c == '\n') line_number++;
            if (!initialized && (c == 32 || c == '\n')) continue;
            if (c == '{') open_brackets++;
            if (c == '}') open_brackets--;
             s += c;

            if (s.size() == 1) initialized = true;
            if (initialized && open_brackets == 0) return s;
        } else
            break;
    }
    return s;
}

void input_file_parser::parse_commands() {
    // grammar : some_string open_bracket closed bracket
    while (true) {
        if (file_index < file.size())
        {
            string cmd = get_command();
            string det = get_details();
            command* cp = new command;
            cp->name = cmd;
            cp->instruction = det;
            // if commands are good

            if (cp->name == "print" || cp->name == "order" || cp->name == "assign")
                tick_commands->push_back(cp);
            if (cp->name == "basket_rules" || cp->name == "launch_rules")
                opening_commands->push_back(cp);
            if (cp->name == "basket_symbols" || cp->name == "basket_ignore")
                opening_commands->push_back(cp);

        } else
            break;
    }
}

vector<command *> *input_file_parser::getOnce_commands() const {
    return once_commands;
}

vector<command *> *input_file_parser::getOpening_commands() const {
    return opening_commands;
}

vector<command *> *input_file_parser::getTick_commands() const {
    return tick_commands;
}
