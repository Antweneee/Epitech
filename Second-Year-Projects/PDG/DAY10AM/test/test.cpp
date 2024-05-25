/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** test
*/

#include <criterion/criterion.h>
#include <iostream>
#include "../ex01/Lemon.hpp"
#include "../ex01/Banana.hpp"
#include "../ex01/FruitBox.hpp"


Test(ex00, test)
{
    Lemon l;
    Banana b;
    std::cout << l.getVitamins() << std::endl;
    std::cout << b.getVitamins() << std::endl;
    std::cout << l.getName() << std::endl;
    std::cout << b.getName() << std::endl;
    Fruit &f = l ;
    std::cout << f.getVitamins() << std::endl;
    std::cout << f.getName() << std::endl;
}

Test(linkedlist, test)
{
    FruitBox box(7);
    Banana banane;
    Lemon lemon;
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&banane));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.pickFruit();
    std::cout << box.nbFruits() << std::endl;
}

Test(linkedlist2, test)
{
    FruitBox box(2);
    FruitBox box2(2);
    Banana banane;
    Lemon lemon;
    box.head();
    box.pickFruit();
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&banane));
    box.pickFruit();
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box.nbFruits() << std::endl;
    box.putFruit(NULL);
    std::cout << box.nbFruits() << std::endl;
    box.pickFruit();
    std::cout << box.nbFruits() << std::endl;
    box = box2;
    box2.putFruit(dynamic_cast<Fruit *>(&lemon));
    std::cout << box2.nbFruits() << std::endl;
    //std::cout << box.head()->_fruit->getName() << std::endl;
}