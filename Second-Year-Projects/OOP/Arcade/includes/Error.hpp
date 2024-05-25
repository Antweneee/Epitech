/*
** EPITECH PROJECT, 2022
** lol
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include "includes.hpp"

class Errors : public std::exception {
    public:
        Errors(const std::string& message) : _message(message) {}
        virtual ~Errors() throw() {}
        const char* what() const noexcept {return _message.c_str();}

    protected:
    private:
        std::string _message;
};

class LibErrors : public Errors {
    public:
        LibErrors(const std::string& message) : Errors(message) {}
        virtual ~LibErrors() throw() {}
};

#endif /* !ERROR_HPP_ */
