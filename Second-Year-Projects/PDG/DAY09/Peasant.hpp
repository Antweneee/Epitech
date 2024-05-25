/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_

#include <iostream>
#include "ICharacter.hpp"
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"

class Peasant : public ICharacter
{
    public:
        /******* constructor *******/
        Peasant(const std::string &name, int power) : _name(name), _power((power > 100 ? 100 : power)), _health(100) {
            std::cout << _name << " goes for an adventure." << std::endl;
        }
        ~Peasant() {
            std::cout << _name << " is back to his crops." << std::endl;
        }

        /******* function *******/
        const std::string &getName() const;
        int getPower() const;
        int getHp() const;
        virtual int attack();
        virtual int special();
        virtual void rest();
        void damage(int damage);
        void drink(const HealthPotion &popo);
        void drink (const PowerPotion &popo);
        void drink (const PoisonPotion &popo);
        void drink (const IPotion &popo);
    protected:
        std::string _name;
        int _power;
        int _health;
    private:
};

#endif /* !PEASANT_HPP_ */
