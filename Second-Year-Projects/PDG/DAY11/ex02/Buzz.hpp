/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : virtual public Toy
{
    public:
        Buzz(std::string name, std::string ascii = "buzz.txt") : Toy(BUZZ, name, ascii) {}
        Buzz(const Buzz &cpy) : Toy(cpy.type, cpy.name, cpy.picture.data) {type = cpy.type; name = cpy.name; picture = cpy.picture;}
        virtual ~Buzz() {}

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */

/*
public:
        Woody(std::string name, std::string ascii = "woody.txt") : Toy(WOODY, name, ascii) {}
        Woody(const Woody &cpy) {type = cpy.type; name = cpy.name; picture = cpy.picture;}
        virtual ~Woody() {}

        // Woody &operator=(Woody const &cpy);
        // Woody &operator<<(std::string const &ascii);
    protected:
    private:
    */