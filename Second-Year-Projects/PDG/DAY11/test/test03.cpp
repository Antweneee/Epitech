/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** test03
*/

#include <criterion/criterion.h>
#include <iostream>
#include <memory>
#include "../ex03/Toy.hpp"
#include "../ex03/Buzz.hpp"
#include "../ex03/Woody.hpp"

Test(ex03, test00)
{
    std ::unique_ptr<Toy> b(new Buzz("buzziiiii"));
    std ::unique_ptr<Toy> w(new Woody("wood"));
    std ::unique_ptr<Toy> t(new Toy(Toy ::ALIEN, "ET", "alien .txt"));
    b->speak("To the code , and beyond !!!!!!!!");
    w->speak("There 's a snake in my boot.");
    t->speak("the claaaaaaw");
}