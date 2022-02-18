/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::DisplayCity(int nbr)
{
    std::vector<std::string> city = _parser.Split(_listAddrChoice[nbr].getCity(), " ");
    for (int a = 0; a < city.size(); a++) {
        if (_city != city[a]) std::cout << city[a];
        else std::cout << _parser.StringToUpperCase(city[a]);
        if (a < city.size() - 1) std::cout << " ";
    }
}

bool Tool::CheckSimilarCityAddr(std::string str)
{
    int compt = 0;
    std::vector<std::string> addr;

    for (int nbr = 0; nbr < _listAddress.size(); nbr++) {
        addr = _parser.Split(_listAddress[nbr].getCity(), " ");
        for (int nb = 0; nb < addr.size(); nb++) if (str == addr[nb]) compt++;
    }
    if (compt == 1) return(false);
    return (true);
}

void Tool::ChoiceCity()
{
    std::vector<std::string> city;
    _listAddrChoice.clear();

    for (int nbr = 0; nbr < _listAddress.size(); nbr++) {
        city = _parser.Split(_listAddress[nbr].getCity(), " ");
        for (int a = 0; a < city.size(); a++) {
            if (city[a] == _city) _listAddrChoice.push_back(_listAddress[nbr]);
        }
    }
    city.clear();
    for (int nbr = 0; nbr < _listAddrChoice.size(); nbr++) {
        std::cout << "{" << nbr + 1 << " : ";
        DisplayCity(nbr);
        std::cout << "}";
        if (nbr < _listAddrChoice.size() - 1) std::cout << " ";
    }
    _status = CHOICE_PROPOSITION;
    std::cout << std::endl;
}

void Tool::CheckCity(int nbr)
{
    v_letter = 0;
    int compt = 0;
    int b = 0;
    std::vector<std::string> city = _parser.Split(_listAddress[nbr].getCity(), " ");

    for (int nb = 0; nb < city.size(); nb++) {
        for (v_letter = 0; city[nb][v_letter] != '\0' && city[nb][v_letter] == _stock[v_letter]; v_letter++);
        if (city[nb][v_letter] == '\0') {
            _city_complete = true;
            _city = _stock;
            if (CheckSimilarCityAddr(city[nb])) {
                if (city.size() > 1)
                    _status = CITY_PROPOSITION;
                else _status = RESEARCH_ROAD;
            }
            else ExitWithAddr(nbr);
        }
        if (_stock[v_letter] == '\0') UpgradeElementChoiceList(city[nb][v_letter]);
        if (_stock[v_letter] == '\0' && !CheckExist(city[nb][v_letter]) && city[nb][v_letter] != '\0' && !_city_complete)
            NewElementChoiceList(city[nb][v_letter]);
    }
    if (_city_complete) _stock = "";
}