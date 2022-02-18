/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

bool Tool::CheckSimilarRoadAddr(std::string str)
{
    std::vector<std::string> addr;
    std::vector<std::string> city;
    _nbr_one = -1;
    _nbr_two = -1;

    for (int nbr = 0; nbr < _listAddress.size(); nbr++) {
        city = _parser.Split(_listAddress[nbr].getCity(), " ");
        for (int a = 0; a < city.size(); a++) {    
            addr = _parser.Split(_listAddress[nbr].getNameRoad(), " ");
            for (int nb = 0; nb < addr.size() && city[a] == _city; nb++) {
                if (str == addr[nb]) {
                    if (_nbr_one == -1) _nbr_one = _listAddress[nbr].getNbrRoad();
                    else if (_nbr_two == -1 && _nbr_one != _listAddress[nbr].getNbrRoad()) _nbr_two = _listAddress[nbr].getNbrRoad();
                }
            }
        }
    }
    if (_nbr_two == -1) return(false);
    return (true);
}

void Tool::DisplayRoad(int nbr)
{
    std::vector<std::string> road;

    road = _parser.Split(_listAddrChoice[nbr].getNameRoad(), " ");
    if (road.size() > 0) {
        std::cout << ", " << _listAddrChoice[nbr].getNbrRoad() << " " << _parser.GetStringRoadWithType(_listAddrChoice[nbr].getTypeRoad()) << " ";
        for (int a = 0; a < road.size(); a++) {
            if (_road != road[a]) std::cout << road[a];
            else std::cout << _parser.StringToUpperCase(road[a]);
            if (a < road.size() - 1) std::cout << " ";
        }
    }
}

void Tool::ChoiceRoad()
{
    std::vector<std::string> road;
    std::vector<std::string> city;
    _listAddrChoice.clear();

    for (int nbr = 0; nbr < _listAddress.size(); nbr++) {
        city = _parser.Split(_listAddress[nbr].getCity(), " ");
        for (int a = 0; a < city.size(); a++) {
            road = _parser.Split(_listAddress[nbr].getNameRoad(), " ");
            for (int nb = 0; nb < road.size() && city[a] == _city; nb++)
                if (_road == road[nb]) _listAddrChoice.push_back(_listAddress[nbr]);
        }
    }
    city.clear();
    road.clear();
    for (int nbr = 0; nbr < _listAddrChoice.size(); nbr++) {
        //affiche ville
        std::cout << "{" << nbr + 1 << " : ";
        DisplayCity(nbr);
        //affiche partis road
        DisplayRoad(nbr);
        std::cout << "}";
        if (nbr < _listAddrChoice.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    _status = CHOICE_PROPOSITION;
}

void Tool::CheckRoad(int nbr)
{
    std::vector<std::string> city = _parser.Split(_listAddress[nbr].getCity(), " ");
    std::vector<std::string> road = _parser.Split(_listAddress[nbr].getNameRoad(), " ");
    int compt = 0;
    int b = 0;

    for (int a = 0; a < city.size(); a++)
        for (int nb = 0; nb < road.size() && city[a] == _city; nb++) {
            for (v_letter = 0; road[nb][v_letter] != '\0' && road[nb][v_letter] == _stock[v_letter]; v_letter++);
            if (road[nb][v_letter] == '\0') {
                _road = road[nb];
                if (CheckSimilarRoadAddr(road[nb])) {
                    if (_nbr_two != -1) _status = ROAD_PROPOSITION;
                    else ExitWithAddr(nbr);
                }
                else ExitWithAddr(nbr);
            }
            if (_stock[v_letter] == '\0') UpgradeElementChoiceList(road[nb][v_letter]);
            if (_stock[v_letter] == '\0' && !CheckExist(road[nb][v_letter]) && road[nb][v_letter] != '\0')
                NewElementChoiceList(road[nb][v_letter]);
        }
}