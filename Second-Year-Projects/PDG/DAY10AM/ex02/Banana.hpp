/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Banana
*/

#ifndef BANANA_HPP_
#define BANANA_HPP_

#include <iostream>
#include "Fruit.hpp"

class Banana : public Fruit
{
    public:
        Banana(); //: Fruit("Banana", 5) {}
        ~Banana();
        int getVitamins() const;
        std::string getName() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !BANANA_HPP_ */