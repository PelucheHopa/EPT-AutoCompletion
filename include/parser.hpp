/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <boost/regex.hpp>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include "error.hpp"
#include "err_invalid_addr.hpp"
#include "address.hpp"

class Parser
{
public:
    Parser() {};
    ~Parser() {};
    std::vector<std::string> Split(std::string input, std::string token);
    std::string StringToLowerCase(std::string data);
    std::string StringToUpperCase(std::string data);
    Address::road GetTypeRoadWithString(std::string typeRoad);
    std::string GetStringRoadWithType(Address::road typeRoad);
    Address Format(Address addr);
    Address ParseLine_pattern_one(std::string line, std::regex pattern);
    Address ParseLine_pattern_two(std::string line, std::regex pattern);
    std::string build(std::string line, std::regex pattern, int group);
};

#endif