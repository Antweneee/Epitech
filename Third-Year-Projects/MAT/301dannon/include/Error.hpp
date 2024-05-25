/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-301dannon-antoine.gavira-bottari
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <exception>
#include <iostream>
#include <string>

#define EXIT_FAILURE_EPI    (84)
#define EXIT_ERROR_FUNCTION (-1)

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
