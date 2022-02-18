/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::Help()
{
    std::cout << "USAGE" << std::endl << "     ./autoCompletion dictionary" << std::endl
              << std::endl << "DESCRIPTION" << std::endl
              << "     dictionary    file containing one address per line, as knowledge base" << std::endl;
    exit (0);
}