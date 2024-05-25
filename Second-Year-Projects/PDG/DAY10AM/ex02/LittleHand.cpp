/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** LittleHand
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{
}

LittleHand::~LittleHand()
{
}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes, FruitBox &coconuts)
{
    FruitBox temp = unsorted;
    Fruit *tmp;

    while (temp._node)
    {
        if (temp._node->fruit->getName() == "lemon") {
            if (lemons.nbFruits() + 1 <= lemons._size) {
                tmp = temp.pickFruit();
                lemons.putFruit(tmp);
            } else
                temp._node = temp._node->next;
        } else if (temp._node->fruit->getName() == "lime") {
            if (limes.nbFruits() + 1 <= limes._size) {
                tmp = temp.pickFruit();
                limes.putFruit(tmp);
            } else
                temp._node = temp._node->next;
        } else if (temp._node->fruit->getName() == "banana") {
            if (bananas.nbFruits() + 1 <= bananas._size) {
                tmp = temp.pickFruit();
                bananas.putFruit(tmp);
            } else
                temp._node = temp._node->next;
        } else if (temp._node->fruit->getName() == "coconut") {
            if (coconuts.nbFruits() + 1 <= coconuts._size) {
                tmp = temp.pickFruit();;
                coconuts.putFruit(tmp);
            }
        }
    }
    //unsorted = temp;
}

FruitBox *const *LittleHand::organizeCoconut(Coconut const * const *coconuts)
{
    int nbr = 0;

    if (! coconuts)
        return NULL;
    for (; coconuts[nbr]; nbr++);
    int plus = nbr % 6;
    int row = nbr / 6; (plus > 0 ? row++ : 0);

    FruitBox **box = new FruitBox*[row + 2];
    int j = 0;
    for (int i = 0; i < row; i++) {
        box[i] = new FruitBox(6);
        if ((i == row - 1) && (plus != 0)) {
            for (int x = 0; x < plus; x++) {
                box[i]->putFruit(const_cast <Coconut *>(coconuts[j]));
                j++;
            }
        } else {
            for (int x = 0; x < 6; x++) {
                box[i]->putFruit(const_cast<Coconut*>(coconuts[j]));
                j++;
            }
        }
    }
    box[row] = nullptr;
    return box;
}
