/*
** EPITECH PROJECT, 2021
** addr
** File description:
** addr
*/

#include "address.hpp"

Address::Address(std::string addrComplete, std::string city, std::string nameRoad, road typeRoad, int nbr)
{
    _addr_complete = addrComplete;
    _city = city;
    _nbrRoad = nbr;
    _typeRoad = typeRoad;
    _nameRoad = nameRoad;
}