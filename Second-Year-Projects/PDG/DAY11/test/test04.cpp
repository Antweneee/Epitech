/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** test04
*/

#include <criterion/criterion.h>
#include <iostream>
#include <memory>
#include "../ex04/Toy.hpp"
#include "../ex04/Buzz.hpp"
#include "../ex04/Woody.hpp"

Test(ex04, test00)
{
    Toy a(Toy ::BASIC_TOY, "REX", "rex.txt");
    std ::cout << a;
    a << "\\o/";
    std ::cout << a;
}
