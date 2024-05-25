/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** test
*/

#include <criterion/criterion.h>
#include <iostream>
#include "../ex03/Toy.hpp"

Test(ex00, test01)
{
    Toy toto;
    Toy ET(Toy ::ALIEN, " green ", "alien.txt");
    toto.setName("TOTO !");
    if (toto.getType() == Toy ::BASIC_TOY)
        std ::cout << "basic toy: " << toto.getName() << std ::endl << toto.getAscii() << std ::endl;
    if (ET.getType() == Toy ::ALIEN)
        std ::cout << "this alien is: " << ET.getName() << std ::endl << ET.getAscii() << std ::endl;
}

Test(ex00, test02)
{
    Toy ET(Toy::ALIEN, "", "");
    std::cout << "basic toy: " << ET.getName() << std::endl << ET.getAscii() << std::endl;

    Toy test(Toy::ALIEN, "bob", "alien.txt");
    std::cout << test.getType() << std::endl;

    Toy toset(Toy::ALIEN, "try", "");
    toset.setAscii("alien.txt");
    std::cout << toset.getAscii() << std::endl;
}