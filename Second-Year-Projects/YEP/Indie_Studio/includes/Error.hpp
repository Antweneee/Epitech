/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>

#define EXIT_FAILURE_EPI 84

class Error : public std::exception {
    public:
        Error(std::ostream &, const std::string &) throw();
        virtual ~Error() throw();
        const char *what() const throw();

    protected:
    private:
        std::string _message;
        std::ostream &_os;
};


#endif /* !ERROR_HPP_ */
