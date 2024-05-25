/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** LittleHand
*/

#ifndef LITTLEHAND_HPP_
#define LITTLEHAND_HPP_

#include "FruitBox.hpp"
#include "Coconut.hpp"

class LittleHand
{
public:
    LittleHand();
    ~LittleHand();
    static void sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes, FruitBox &coconuts);
    static FruitBox *const *organizeCoconut(Coconut const * const *coconuts);
    protected :
    private :
};

#endif /* !LITTLEHAND_HPP_ */
