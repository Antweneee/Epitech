/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"

class LittleHand
{
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes);

protected:
private:
};

#endif /* !LITTLEHAND_HPP_ */