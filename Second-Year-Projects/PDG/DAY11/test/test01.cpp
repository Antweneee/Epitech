/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** test01
*/

#include <criterion/criterion.h>
#include <iostream>
#include "../ex03/Toy.hpp"

Test(ex01, test01)
{
    Toy toto;
    Toy ET(Toy::ALIEN, "green", "");
    toto.setName("TOTO !");
    Toy& b = ET;
    if (b.getType() == Toy ::BASIC_TOY)
        std ::cout << "basic toy: " << b.getName() << std ::endl
                   << b.getAscii() << std ::endl;
    if (b.getType() == Toy ::ALIEN)
        std ::cout << "this alien is: " << b.getName() << std ::endl
                   << b.getAscii() << std ::endl;
}