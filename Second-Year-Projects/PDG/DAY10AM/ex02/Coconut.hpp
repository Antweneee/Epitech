/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Coconut
*/

#ifndef COCONUT_HPP_
#define COCONUT_HPP_

#include "Fruit.hpp"
#include <iostream>


class Coconut : public Fruit {
    public:
        Coconut();
        ~Coconut();

        std::string getName() const;
        int getVitamins() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !COCONUT_HPP_ */

