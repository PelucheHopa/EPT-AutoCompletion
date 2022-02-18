/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::Openfile(char *str)
{
    _file = new std::ifstream(str);
    if (!_file->is_open())
        throw (ErrorEndingFile());
    if (_file->peek() == std::ifstream::traits_type::eof()) throw (ErrorFileEmpty());
}

void Tool::Readfile(void)
{
    std::string line;
    //city, nbr, road, nR
    std::regex pattern_one { "^[ \t,]*([a-zA-Z- \\é\\è\\à’']+)[ \t,]+([0-9]+)[ \t]+([a-zA-Z\\é\\è\\à’']+)[ \t]+([a-zA-Z- \\é\\è\\à’']+)" };
    //nbr, roadT, roadName, city
    std::regex pattern_two { "^[ \t,]*([0-9]+)[ \t]+([a-zA-Z\\é\\è\\à’']+)[ \t]+([a-zA-Z- \\é\\è\\à’']+)[ \t,]+([a-zA-Z- \\é\\è\\à’']+)" };
    if (_file) {
        while (getline(_file[0], line)) {
            if (std::regex_search(line, pattern_one)) _listAddress.push_back(_parser.ParseLine_pattern_one(line, pattern_one));
            else if (std::regex_search(line, pattern_two)) _listAddress.push_back(_parser.ParseLine_pattern_two(line, pattern_two));
            else throw (ErrorInvalidAddr(line));
        }
    }
}