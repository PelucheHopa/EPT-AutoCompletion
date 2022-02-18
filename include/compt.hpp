/*
** EPITECH PROJECT, 2021
** tool
** File description:
** tool
*/

#ifndef COMPT_HPP_
#define COMPT_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <boost/regex.hpp>
#include "error.hpp"

class Compt
{
    int _nbr;
    char _caract;
public:
    Compt(int nbr, char caract) : _nbr(nbr), _caract(caract) {};
    ~Compt() {};
    void setNbr(int nbr) { _nbr = nbr; };
    int getNbr(void) { return (_nbr); };
    char getCaract(void) { return (_caract); };
};

#endif