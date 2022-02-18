/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <boost/regex.hpp>
#include "error.hpp"
#include "err_ending_file.hpp"
#include "err_invalid_addr.hpp"
#include "err_args.hpp"
#include "err_invalid_input.hpp"
#include "err_file_empty.hpp"
#include "address.hpp"
#include "parser.hpp"
#include "compt.hpp"

class Tool
{
    typedef enum s_status
    {
        NOTHING,
        CITY_PROPOSITION,
        ROAD_PROPOSITION,
        CHOICE_PROPOSITION,
        RESEARCH_CITY,
        RESEARCH_ROAD
    } status;
private:
//global
    std::vector<Address> _listAddress;
    std::vector<Address> _listAddrChoice;
    std::vector<char> _listchoice;
    std::vector<Compt> _compt;
    std::ifstream *_file;
    std::string _stock;
    std::string _save;
    std::string _input;
    status _status;
    int v_letter;
    int _diff;
    int _time_out;
    int _nbr_one = -1;
    int _nbr_two = -1;
//city
    std::string _city;
    bool _city_complete;
//road
    std::string _road;
    bool _road_complete;
//parser
    Parser _parser;
public:
    Tool();
    ~Tool();
    //file
    void Help(void);
    void Openfile(char *str);
    void Readfile(void);
    //get Input
    void CheckInput(std::string input);
    void GetInput(void);
    void AutoInput(void);
    //verif
    bool CheckExist(char a);
    //modificater stock
    void CheckTimeOut(void);
    void AddToStock(void);
    void AddSeparatorCityRoad(void);
    std::vector<std::string> Split(std::string input, std::string token);
    //list
    void NewElementChoiceList(char letter);
    void UpgradeElementChoiceList(char letter);
    void ClearAllList(void);
    void InitListAddress(void);
    void DisplayListAddress(void);
    void ExitWithAddr(int nbr);
    void ExitWithAddrFromChoiceList(int nbr);
    //city
    void DisplayCity(int nbr);
    void ChoiceCity(void);
    bool CheckSimilarCityAddr(std::string str);
    void CheckCity(int nbr);
    //road
    void DisplayRoad(int nbr);
    void ChoiceRoad(void);
    bool CheckSimilarRoadAddr(std::string str);
    void CheckRoad(int nbr);
    //return value
    int GetDiff(void) { return (_diff); };
    status getStatus(void) { return (_status); };
    std::vector<Address> getListAddress(void) { return (_listAddress);};
};

#endif