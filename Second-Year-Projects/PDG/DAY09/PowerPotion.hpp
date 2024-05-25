/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** PowerPotion
*/

#ifndef POWERPOTION_HPP_
#define POWERPOTION_HPP_

#include "IPotion.hpp"

class PowerPotion : public IPotion
{
    public:
        PowerPotion();
        ~PowerPotion();
        std::string getpotion() const {return _popo;}
    protected:
    private:
        std::string _popo;
};

#endif /* !POWERPOTION_HPP_ */
