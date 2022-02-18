/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

Tool::Tool()
{
//utility
    _file = NULL;
    _stock = "";
    _input = "";
    _save = "";
    v_letter = 0;
    _diff = 2;
//city
    _city = "";
    _city_complete = false;
//road
    _road = "";
    _road_complete = false;
    _status = RESEARCH_CITY;
//security
    _time_out = 0;
}

Tool::~Tool()
{
    if (!_file->is_open()) {
        _file->close();
        delete(_file);
    }
}

void Tool::AddToStock(void)
{
    if (CheckExist(_input[0])) _stock = _stock + _input;
}

bool Tool::CheckExist(char a)
{
    int nbr = 0;

    for (; nbr < _listchoice.size(); nbr++) if (_listchoice[nbr] == a) return (true);
    return (false);
}

void Tool::AddSeparatorCityRoad(void)
{
    static bool statok = true;

    v_letter = v_letter + 2;
    if (statok) {
        statok = false;
        _stock = _stock + ", ";
    }
}

void Tool::CheckTimeOut()
{
    if (_save == _stock) _time_out++;
    else _time_out = 0;
    if (_time_out > 5) throw (ErrorInvalidAddr("TIMEOUT"));
    _save = _stock;
}