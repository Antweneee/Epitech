/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_

#include <string>
#include "IPotion.hpp"
#include "HealthPotion.hpp"
#include "PowerPotion.hpp"
#include "PoisonPotion.hpp"

class ICharacter {
    public:
        virtual ~ICharacter() = default;
        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        virtual void damage(int damage) = 0;
        virtual void drink(const HealthPotion &popo) = 0;
        virtual void drink(const PowerPotion &popo) = 0;
        virtual void drink(const PoisonPotion &popo) = 0;
        virtual void drink(const IPotion &popo) = 0;
    protected:
    private:
};

#endif /* !ICHARACTER_HPP_ */
