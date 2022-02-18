/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::ClearAllList(void)
{
    _listchoice.clear();
    _compt.clear();
}

void Tool::NewElementChoiceList(char letter)
{
    int b = 0;

    for (int a = 0; a < _compt.size(); a++) std::cout << _compt[a].getCaract() << std::endl;
    for (b = 0; b < _compt.size() && _compt[b].getNbr() > 1; b++);
    for (; b < _compt.size() && _compt[b].getCaract() < letter; b++);
    _compt.insert(_compt.begin() + b, Compt(1, letter));
    _listchoice.push_back(letter);
    _diff++;
}

void Tool::UpgradeElementChoiceList(char letter)
{
    int a = 0;
    int b = 0;

    if (CheckExist(letter) && letter != '\0')
        for (a = 0; a < _compt.size(); a++) {
            if (_compt[a].getCaract() == letter) {
                for (b = 0; _compt[b].getNbr() > _compt[a].getNbr(); b++);
                for (; b < _compt.size() && _compt[b].getCaract() < letter; b++);
                _compt.insert(_compt.begin() + b, Compt(_compt[a].getNbr() + 1, _compt[a].getCaract()));
                _compt.erase(_compt.begin() + a + 1);
            }
        }
}

void Tool::InitListAddress(void)
{  
    ClearAllList();

    _diff = 0;

    switch (_status)
    {
    case RESEARCH_CITY :
        for (int nbr = 0; nbr != _listAddress.size(); nbr++) CheckCity(nbr);
        break;
    case RESEARCH_ROAD :
        for (int nbr = 0; nbr != _listAddress.size(); nbr++) CheckRoad(nbr);
        break;
    case CHOICE_PROPOSITION :
        GetInput();
        break;
    case CITY_PROPOSITION :
        ChoiceCity();
        break;
    case ROAD_PROPOSITION :
        ChoiceRoad();
        break;
    default:
        break;
    }
    if (_diff == 1) AutoInput();
}

void Tool::DisplayListAddress(void)
{
    for (int nbr = 0; nbr < _listchoice.size() && nbr < 5; nbr++) {
        std::cout << "{";
        if (_city_complete) std::cout << _parser.StringToUpperCase(_city) << ", ";
        std::cout << _parser.StringToUpperCase(_stock) << _compt[nbr].getCaract() << "}";
        if (nbr < _listchoice.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
}
