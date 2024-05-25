/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include "KoalaNurse.hpp"

class KoalaDoctor {
    public:
        std::string _name;
        bool _isworking;

        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        void diagnose(SickKoala *patient);
        void timeCheck(void);
    protected:
    private:
};

#endif /* !KOALADOCTOR_HPP_ */