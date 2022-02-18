/*
** EPITECH PROJECT, 2021
** Maxime Thiong-kay
** File description:
** autoCompletion
*/

#include "error.hpp"
#include "tool.hpp"

int main(int ac, char **av)
{
    Tool tool;

    try {
        if (ac != 2) throw (ErrorArgs());
        else if ((std::string)(av[1]) == "-h") tool.Help();
        else {
            tool.Openfile(av[1]);
            tool.Readfile();
            while (true) {
                tool.InitListAddress();
                if (tool.GetDiff() >= 2) {
                    tool.DisplayListAddress();
                    tool.GetInput();
                }
                tool.AddToStock();
                tool.CheckTimeOut();
;           }
        }
    }
    catch (ErrorInvalidAddr invalid_addr) {
        std::cerr << invalid_addr.getline() << std::endl;
        std::cerr << invalid_addr.what() << std::endl;
        exit(84);
    }
    catch (Error error) {
        std::cerr << error.what() << std::endl;
        exit(84);
    }
    return (0);
}
