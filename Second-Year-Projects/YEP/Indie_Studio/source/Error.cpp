/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(std::ostream &os, const std::string &message) throw()
    : _message(message), _os(os)
{
}

Error::~Error() throw()
{
}

const char *Error::what() const throw()
{
    return _message.c_str();
}
