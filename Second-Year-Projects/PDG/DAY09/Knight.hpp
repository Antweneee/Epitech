/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_

#include "Peasant.hpp"

class Knight : virtual public Peasant {
    public:
        /******* constructor *******/
        Knight(const std::string &name, int power) : Peasant(name, power) {
            std::cout << _name << " vows to protect the kingdom." << std::endl;
        }
        ~Knight() {
            std::cout << _name << " takes off his armor." << std::endl;
        }

        /******* var *******/

        /******* function *******/
        int attack() override;
        int special() override;
        void rest() override;
    protected:
    private:
};

#endif /* !KNIGHT_HPP_ */