/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** HealthPotion
*/

#ifndef HEALTHPOTION_HPP_
#define HEALTHPOTION_HPP_

#include "IPotion.hpp"

class HealthPotion : public IPotion
{
    public:
        HealthPotion();
        ~HealthPotion();
        std::string getpotion() const {return _popo;}
    protected:
    private:
        std::string _popo;
};

#endif /* !HEALTHPOTION_HPP_ */
