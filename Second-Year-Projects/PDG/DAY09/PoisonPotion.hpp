/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** PoisonPotion
*/

#ifndef POISONPOTION_HPP_
#define POISONPOTION_HPP_

#include "IPotion.hpp"

class PoisonPotion : public IPotion
{
    public:
        PoisonPotion();
        ~PoisonPotion();
        std::string getpotion() const {return _popo;}

    protected:
    private:
        std::string _popo;
};

#endif /* !POISONPOTION_HPP_ */
