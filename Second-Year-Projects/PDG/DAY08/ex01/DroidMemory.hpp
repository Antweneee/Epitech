/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08-antoine.gavira-bottari
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include "Droid.hpp"

class DroidMemory {
    public:
        //constructor

        DroidMemory(size_t FingerPrint, size_t Exp);
        DroidMemory();
        ~DroidMemory();

        //function

        size_t getFingerprint() const;
        size_t getExp() const;
        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        //operator

        DroidMemory &operator<<(DroidMemory &mem);
        DroidMemory &operator>>(DroidMemory &memory);
        DroidMemory &operator+=(DroidMemory &memory);
        DroidMemory &operator+=(size_t exp);
        DroidMemory operator+(DroidMemory &memory);
        DroidMemory operator+(size_t exp);
    protected:
    private:
        size_t _Fingerprint;
        size_t _Exp;
};

std::ostream &operator<<(std::ostream &print, DroidMemory const &droid);

#endif /* !DROIDMEMORY_HPP_ */
