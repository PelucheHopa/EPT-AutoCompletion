/*
** EPITECH PROJECT, 2021
** address class
** File description:
** address
*/

#ifndef ADDRESS_HPP_
#define ADDRESS_HPP_

#include <iostream>
#include <vector>

class Address
{
public:
    typedef enum s_road {
        NOTHING,
        ALLEE,
        AVENUE,
        BOULEVARD,
        CHEMIN,
        IMPASSE,
        PLACE,
        QUAI,
        RUE,
        SQUARE
    } road;
private:
    std::string _addr_complete;
    std::string _city;
    int _nbrRoad;
    road _typeRoad;
    std::string _nameRoad;
public:
    Address(std::string addrComplete, std::string city, std::string nameRoad, road typeRoad, int nbr);
    ~Address() {};
    std::string getCity(void) { return (_city); };
    road getTypeRoad(void) { return (_typeRoad); };
    std::string getNameRoad(void) { return (_nameRoad); };
    std::string getAddrComplete(void) { return (_addr_complete); };
    int getNbrRoad(void) { return (_nbrRoad); };
    void setCity(std::string name) { _city = name; };
    void setTypeRoad(road type) { _typeRoad = type; };
    void setNameRoad(std::string name) { _nameRoad = name; };
    void setNbrRoad(int nbr) { _nbrRoad = nbr;};
    void setAddrComplete(std::string str) { _addr_complete = str;};
};

#endif
