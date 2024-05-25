/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD09-antoine.gavira-bottari
** File description:
** IPotion
*/

#ifndef IPOTION_HPP_
#define IPOTION_HPP_

#include <iostream>

class IPotion
{
    public:
        virtual ~IPotion() = default;
        virtual std::string getpotion() const = 0;
    protected:
    private:
};

#endif /* !IPOTION_HPP_ */
