/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "tool.hpp"

void Tool::CheckInput(std::string input)
{
    if (_status == CHOICE_PROPOSITION && input[0] >= '1' && input[0] <= '9' && stoi(input) <= _listAddrChoice.size())
        ExitWithAddrFromChoiceList(stoi(input) - 1);
    if (input.size() >= 2 && input != "ABORT") throw (ErrorInvalidInput());
    else if (input == "ABORT") exit(0);
}

void Tool::GetInput(void)
{
    std::string input = "";

    getline(std::cin, input);
    CheckInput(input);
    if (input == "") exit(0);
    _input = _parser.StringToLowerCase(input);
}

void Tool::AutoInput(void)
{
    _input = _listchoice[0];
}