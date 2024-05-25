/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08-antoine.gavira-bottari
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(size_t FingerPrint, size_t Exp)
{
    _Fingerprint = FingerPrint;
    _Exp = Exp;
}

DroidMemory::DroidMemory()
{
    _Fingerprint = random();
    _Exp = 0;
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerprint() const
{
    return _Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return _Exp;
}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    _Fingerprint =fingerprint;
}

void DroidMemory::setExp(size_t exp)
{
    _Exp = exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory& memory){

    _Exp += memory._Exp;
    _Fingerprint ^= memory._Fingerprint;
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory& memory){
    memory._Exp += _Exp;
    memory._Fingerprint ^= _Fingerprint;
    return memory;
}

DroidMemory &DroidMemory::operator+=(DroidMemory& memory){
    return (*this << memory);
}

DroidMemory &DroidMemory::operator+=(size_t value)
{
    _Exp += value;
    _Fingerprint ^= value;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory& memory)
{
    return (*this += memory);
}

DroidMemory DroidMemory::operator+(size_t val)
{
    return (*this += val);
}

std::ostream &operator<<(std::ostream &print, DroidMemory const &droid)
{
        return (print << "DroidMemory '" << droid.getFingerprint() << "', "  << droid.getExp());
}

