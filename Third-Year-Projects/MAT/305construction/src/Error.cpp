/*
** EPITECH PROJECT, 2022
** 305construction
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::ostream &os, const std::string &message) throw()
    : _message(message), _os(os)
{
    os << message << std::endl;
}

const char *Error::what() const throw()
{
    return _message.c_str();
}
