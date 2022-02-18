/*
** EPITECH PROJECT, 2020
** ErrorS
** File description:
** Error
*/

#ifndef ERR_INVALID_INPUT_HPP_
#define ERR_INVALID_INPUT_HPP_

#include "error.hpp"

class ErrorInvalidInput: public Error {
    public:
        ErrorInvalidInput() : Error("Error : Invalid input", __FILE__, __LINE__) {};
        ~ErrorInvalidInput() {};
};
#endif /* !ERROR_HPP_ */