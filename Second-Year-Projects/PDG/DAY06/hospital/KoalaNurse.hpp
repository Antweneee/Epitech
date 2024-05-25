/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** KoalaNurse
*/

#ifndef KOALANURSE_HPP_
#define KOALANURSE_HPP_

#include "SickKoala.hpp"

class KoalaNurse {
    public:
    unsigned int _id;
    bool _isworking;
        KoalaNurse(unsigned int id);
        ~KoalaNurse();
        void giveDrug(std::string drug, SickKoala *patient);
        std::string readReport(std::string);
        void timeCheck(void);
    protected:
    private:
};

#endif /* !KOALANURSE_HPP_ */