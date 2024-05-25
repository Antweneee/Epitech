/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include <iostream>

#include "Part.hpp"

class KoalaBot {
    public:
        std::string _serial;
        Arms _arms;
        Legs _legs;
        Head _head;

        void setParts(Arms &arm);
        void setParts(Legs &leg);
        void setParts(Head &head);

        void swapParts(Arms &arm);
        void swapParts(Legs &leg);
        void swapParts(Head &head);

        void informations();
        bool status();

        KoalaBot(std::string serial = "Bob-01");
        ~KoalaBot();
    protected:
    private:
};

#endif /* !KOALABOT_HPP_ */
