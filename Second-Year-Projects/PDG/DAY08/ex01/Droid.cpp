/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08-antoine.gavira-bottari
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _id(id), _Energy(50), _Attack(25), _Toughness(15)
{
    _Status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &copy) : _id(copy._id), _Energy(copy._Energy), _Attack(copy._Attack), _Toughness(copy._Toughness)
{
    _Status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated" << ", Memory Dumped"<<std::endl;
}

Droid::~Droid()
{
    if (_Status)
        delete _Status;
    std::cout << "Droid '" << _id <<  "' Destroyed" << std::endl ;
}

std::string Droid::getId() const
{
    return _id;
}

size_t Droid::getEnergy() const
{
    return _Energy;
}

size_t Droid::getAttack() const
{
    return _Attack;
}

size_t Droid::getToughness() const
{
    return _Toughness;
}

std::string *Droid::getStatus() const
{
    return _Status;
}

void Droid::setId(std::string id)
{
    _id = id;
}

void Droid::setEnergy(size_t engergy)
{
    _Energy = engergy;
}

void Droid::setStatus(std::string *status)
{
    _Status = status;
}

Droid &Droid::operator =(Droid const &cpy)
{
    _id = cpy.getId();
    _Energy = cpy.getEnergy();
    delete _Status;
    _Status = cpy.getStatus();
    return *this;
}

bool Droid::operator==(const Droid& check) const
{
    if (/*_id == check._id && _Energy == check._Energy && _Attack == check._Attack && _Toughness == check._Toughness &&*/ *_Status == *(check._Status))
        return true;
    return false;
}

bool Droid::operator!=(const Droid& check) const
{
    if (/*_id == check._id || _Energy == check._Energy || _Attack == check._Attack || _Toughness == check._Toughness ||*/ *_Status == *(check._Status))
        return true;
    return false;
}

Droid &Droid::operator<<(size_t &energy)
{
    int add = 0;

    if (_Energy < 100) {
        add = std::min(100 - _Energy, energy);
        _Energy += add;
        energy -= add;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &print, Droid const &droid)
{
    if (droid.getEnergy() > 100)
        return (print << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", 100");
    else
        return (print << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", "  << droid.getEnergy());
}