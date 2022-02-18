/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_FILE_EMPTY_HPP_
#define ERR_FILE_EMPTY_

#include "error.hpp"

class ErrorFileEmpty: public Error {
    public:
        ErrorFileEmpty() : Error("File empty", __FILE__, __LINE__) {};
        ~ErrorFileEmpty() {};
};
#endif /* !ERROR_HPP_ */