/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include "../Peasant.hpp"
#include "../Knight.hpp"
#include "../Priest.hpp"
#include "../Enchanter.hpp"
#include "../Paladin.hpp"
#include "../IPotion.hpp"
#include "../ICharacter.hpp"
#include "../PowerPotion.hpp"
#include "../PoisonPotion.hpp"
#include "../HealthPotion.hpp"

Test(peasant, test)
{
    Peasant peasant("Gildas", 42);
    peasant.getName();
    peasant.getPower();
    peasant.getHp();
    peasant.attack();
    peasant.special();
    peasant.damage(50);
    peasant.damage(100);
    peasant.special();
    peasant.damage(200);
    peasant.rest();
}

Test(peasant_rtt, test)
{
    Peasant peasant("Gildas", 42);
    peasant.damage(50);
    peasant.damage(100);
    peasant.damage(200);
    peasant.rest();
}

Test(peasant_error, test)
{
    Peasant valentin("valentin", 9);
    valentin.attack();
    valentin.damage(95);
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.attack();
    valentin.damage(5);
    valentin.attack();
    valentin.special();
}

Test(priest, test1)
{
    Priest merlin("Gildas", 42);
    merlin.getName();
    merlin.getPower();
    merlin.getHp();
    merlin.attack();
    merlin.special();
    merlin.damage(50);
    merlin.damage(100);
    merlin.special();
    merlin.damage(200);
    merlin.rest();
}

Test(rpi_rtt, test2)
{
    Priest merlin("Gildas", 42);
    merlin.damage(50);
    merlin.damage(100);
    merlin.damage(200);
    merlin.rest();
}

Test(rpsirt, test3)
{
    Priest valentin("valentin", 9);
    valentin.attack();
    valentin.damage(95);
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.attack();
    valentin.damage(5);
    valentin.attack();
    valentin.special();
}

Test(priest_true, subject3)
{
    Priest merlin("Arthur", 20);
    merlin.attack();
    merlin.special();
    merlin.rest();
    merlin.special();
    merlin.damage(50);
}

Test(propro_false, izi2)
{
    Priest Priest("Merlin", 20);
    Priest.attack();
    Priest.special();
    Priest.rest();
    std::cout << Priest.getName() << std::endl;
    Priest.special();
    Priest.damage(50);
}

Test(Chacal, toto)
{
    Priest priest("Trichelieu", 20);
    priest.attack();
    priest.special();
    priest.rest();
    priest.damage(50);
}

Test(merlin, test)
{
    Enchanter merlin("Gildas", 42);
    merlin.getName();
    merlin.getPower();
    merlin.getHp();
    merlin.attack();
    merlin.special();
    merlin.damage(50);
    merlin.damage(100);
    merlin.special();
    merlin.damage(200);
    merlin.rest();
}

Test(merlin_rtt, test)
{
    Enchanter merlin("Gildas", 42);
    merlin.damage(50);
    merlin.damage(100);
    merlin.damage(200);
    merlin.rest();
}

Test(merlin_trt, test)
{
    Enchanter valentin("valentin", 9);
    valentin.attack();
    valentin.damage(95);
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.attack();
    valentin.damage(5);
    valentin.attack();
    valentin.special();
}

Test(merlin_true, subject)
{
    Enchanter merlin(" Arthur ", 20);
    merlin.attack();
    merlin.special();
    merlin.rest();
    merlin.special();
    merlin.damage(50);
}

Test(Merlin_false, izi)
{
    Enchanter enchanter(" Merlin ", 20);
    enchanter.attack();
    enchanter.special();
    enchanter.rest();
    std::cout << enchanter.getName() << std::endl;
    enchanter.special();
    enchanter.damage(50);
}

Test(Knight, test)
{
    Knight knight("Gildas", 42);
    knight.getName();
    knight.getPower();
    knight.getHp();
    knight.attack();
    knight.special();
    knight.damage(50);
    knight.damage(100);
    knight.special();
    knight.damage(200);
    knight.rest();
}

Test(Knight_rtt, test)
{
    Knight knight("Gildas", 42);
    knight.damage(50);
    knight.damage(100);
    knight.damage(200);
    knight.rest();
}

Test(knight_trt, test)
{
    Knight valentin("valentin", 9);
    valentin.attack();
    valentin.damage(95);
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.attack();
    valentin.damage(5);
    valentin.attack();
    valentin.special();
}

Test(Knight_true, subject)
{
    Knight knight(" Arthur ", 20);
    knight.attack();
    knight.special();
    knight.rest();
    knight.special();
    knight.damage(50);
}

Test(peasant_error2, test)
{
    Peasant valentin("valentin", 101);
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
    valentin.attack();
}

Test(paladin, test1)
{
    Paladin merlin("Gildas", 42);
    merlin.getName();
    merlin.getPower();
    merlin.getHp();
    merlin.attack();
    merlin.special();
    merlin.damage(50);
    merlin.damage(100);
    merlin.special();
    merlin.damage(200);
    merlin.rest();
}

Test(paladin, test2)
{
    Paladin merlin("Gildas", 42);
    merlin.damage(50);
    merlin.damage(100);
    merlin.damage(200);
    merlin.rest();
}

Test(paladin, test3)
{
    Paladin valentin("valentin", 9);
    valentin.attack();
    valentin.damage(95);
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.rest();
    valentin.attack();
    valentin.damage(5);
    valentin.attack();
    valentin.special();
}

Test(paladin_true, subject3)
{
    Paladin merlin("Arthur", 20);
    merlin.attack();
    merlin.special();
    merlin.rest();
    merlin.special();
    merlin.damage(50);
}

Test(paladin_false, izi2)
{
    Paladin paladin("Merlin", 20);
    paladin.attack();
    paladin.special();
    paladin.rest();
    std::cout << paladin.getName() << std::endl;
    paladin.special();
    paladin.damage(50);
}

Test(paladin, toto)
{
    Paladin paladin("Trichelieu", 20);
    paladin.attack();
    paladin.special();
    paladin.rest();
    paladin.damage(50);
}

Test(ICharacter, zebi)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    ICharacter *knight = new Knight("Arthur", 20);
    ICharacter *enchanter = new Enchanter("Merlin", 20);
    ICharacter *priest = new Priest("Trichelieu", 20);
    ICharacter *paladin = new Paladin("Uther", 99);
    peasant->attack();
    knight->special();
    enchanter->rest();
    priest->damage(21);
    std ::cout << paladin->getName() << ": "
               << paladin->getHp() << " health points, "
               << paladin->getPower() << " power points."
               << std::endl;
    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;
}

Test(IPotion, tfou3lick)
{
    ICharacter *peasant = new Peasant("Gildas", 42);
    PoisonPotion poison_potion;
    HealthPotion health_potion;
    IPotion &potion = health_potion;
    std ::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
               << peasant->getPower() << " PP." << std ::endl;
    peasant->drink(poison_potion);
    std ::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
               << peasant->getPower() << " PP." << std ::endl;
    peasant->drink(potion);
    std ::cout << peasant->getName() << ": " << peasant->getHp() << "HP, "
               << peasant->getPower() << " PP." << std ::endl;
    delete peasant;
}