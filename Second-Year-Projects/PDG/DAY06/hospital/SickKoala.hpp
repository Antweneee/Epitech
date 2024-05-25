/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** SickKoala
*/

#ifndef SICKKOALA_HPP_
#define SICKKOALA_HPP_

#include <fstream>
#include <string>
#include <iostream>
#include <regex>

class SickKoala {
    public:
        std::string _name;
        SickKoala(std::string set);
        ~SickKoala();
        void poke(void);
        bool takeDrug(std::string check);
        void overDrive(std::string check);
        std::string getName(void);
    protected:
    private:
};

#endif /* !SICKKOALA_HPP_ */