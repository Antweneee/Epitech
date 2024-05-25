/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** Fruit
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <iostream>

class Fruit
{
    public:
        virtual ~Fruit() = default;
        virtual int getVitamins() const = 0;
        virtual std::string getName() const = 0;
    protected:
    private:
};

#endif /* !FRUIT_HPP_ */
