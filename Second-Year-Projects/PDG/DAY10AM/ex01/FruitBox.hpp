/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();

        int nbFruits() const;
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const;
        FruitNode *_node;
        int _size;
    protected:
    private:
};

#endif /* !FRUITBOX_HPP_ */
