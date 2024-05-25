/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10pm-antoine.gavira-bottari
** File description:
** Errors
*/

#include <iostream>
#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component)
{
    _message = message;
    _component = component;
}

std::string const&NasaError::getComponent() const noexcept
{
    return _component;
}

const char *NasaError::what() const noexcept
{
    return _message.c_str();
}