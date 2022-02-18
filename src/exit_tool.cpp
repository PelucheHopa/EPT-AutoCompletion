/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::ExitWithAddr(int nbr)
{
    std::cout << "=> " << _listAddress[nbr].getAddrComplete() << std::endl;
    exit (0);
}

void Tool::ExitWithAddrFromChoiceList(int nbr)
{
    std::cout << "=> " << _listAddrChoice[nbr].getAddrComplete() << std::endl;
    exit (0);
}