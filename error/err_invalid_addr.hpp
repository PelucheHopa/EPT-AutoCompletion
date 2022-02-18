/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_INVALID_ADDR_HPP_
#define ERR_INVALID_ADDR_HPP_

#include "error.hpp"

class ErrorInvalidAddr: public Error {
    private:
        std::string _line;
    public:
        ErrorInvalidAddr(std::string line) : Error("Unknow address", __FILE__, __LINE__) { _line = line; };
        ~ErrorInvalidAddr() {};
        std::string getline(void) { return (_line); };
};

#endif /* !ERROR_HPP_ */

//Unknown address