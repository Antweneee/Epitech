/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_

#include "Peasant.hpp"

class Enchanter : virtual public Peasant {
    public:
        /******* constructor *******/
        Enchanter(std::string name, int power) : Peasant(name, power) {
            std::cout << _name << " learns magic from his spellbook." << std::endl;
        }
        ~Enchanter() {
            std::cout << _name << " closes his spellbook." << std::endl;
        }
        /******* var *******/

        /******* function *******/
        int attack() override;
        int special() override;
        void rest() override;
    protected:
    private:
};

#endif /* !ENCHANTER_HPP_ */