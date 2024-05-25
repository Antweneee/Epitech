/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** test2
*/

#include <criterion/criterion.h>
#include "../ex01/Banana.hpp"
#include "../ex01/Lemon.hpp"
#include "../ex01/Lime.hpp"
#include "../ex01/Fruit.hpp"
#include "../ex01/FruitBox.hpp"
#include "../ex01/LittleHand.hpp"


Test(ex01, test01)
{
    FruitBox box(10);
    FruitBox lemon(2);
    FruitBox lime(2);
    FruitBox banana(3);

    Banana baa[3];
    Lemon lee[2];
    Lime lii[2];

    for (int i = 0; i < 3; i++)
        box.putFruit(&baa[i]);
    for (int i = 0; i < 2; i++)
        box.putFruit(&lee[i]);
    for (int i = 0; i < 2; i++)
        box.putFruit(&lii[i]);
    LittleHand hand;
    hand.sortFruitBox(box, lemon, banana, lime);
    std::cout <<  "nb fruits lemon : " << lemon.nbFruits() << std::endl;
    std::cout <<  "nb fruits lime : " << lime.nbFruits() << std::endl;
    std::cout <<  "nb fruits banana : " << banana.nbFruits() << std::endl;
    std::cout <<  "nb fruits unsorted : " << box.nbFruits() << std::endl;
}