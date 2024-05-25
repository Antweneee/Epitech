/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Lemon
*/

#ifndef LEMON_HPP_
#define LEMON_HPP_

#include <iostream>
#include "Fruit.hpp"

class Lemon : public Fruit
{
    public:
        Lemon(); //: Fruit("Lemon", 3) {}
        ~Lemon();
        int getVitamins() const;
        std::string getName() const;
    protected:
        std::string _name;
        int _vitamins;
    private:
};

#endif /* !LEMON_HPP_ */
