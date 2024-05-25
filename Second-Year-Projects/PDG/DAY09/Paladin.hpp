/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Priest.hpp"
#include "Knight.hpp"

class Paladin : public Knight, public Priest {
    public:
        /******* constructor *******/
        Paladin(std::string name, int power) : Peasant(name, power), Knight(name, power), Priest(name, power) {
            std::cout << _name << " fights for the light." << std::endl;
        }
        ~Paladin() {
            std::cout << _name << " is blessed." << std::endl;
        }
        /******* var *******/

        /******* function *******/
        int attack() override;
        int special() override;
        void rest() override;
    protected:
    private:
};

#endif /* !PALADIN_HPP_ */