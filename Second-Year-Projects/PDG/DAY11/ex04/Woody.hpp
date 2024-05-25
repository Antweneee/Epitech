/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : virtual public Toy
{
    public:
        Woody(std::string name, std::string ascii = "woody.txt") : Toy(WOODY, name, ascii) {}
        Woody(const Woody &cpy) : Toy(cpy.type, cpy.name, cpy.picture.data) {type = cpy.type; name = cpy.name; picture = cpy.picture;}
        virtual ~Woody() {}

        void speak(std::string say);
    protected:
    private:
};

#endif /* !WOODY_HPP_ */
