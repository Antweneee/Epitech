/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Enchanter.hpp"

class Priest : public Enchanter {
    public:
        /******* constructor *******/
        Priest(std::string name, int power) : Peasant(name, power), Enchanter(name, power) {
            std::cout << _name << " enters in the order." << std::endl;
        }
        ~Priest() {
            std::cout << _name << " finds peace." << std::endl;
        }
        /******* var *******/

        /******* function *******/
        void rest() override;
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */