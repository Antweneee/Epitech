/*
** EPITECH PROJECT, 2022
** POOL
** File description:
** Federation
*/

#include "Borg.hpp"
#include "Federation.hpp"

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = maxWarp;
    _home = EARTH;
    _location = _home;
    _shield = 100;
    _photonTorpedo = torpedo;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
};

Federation::Starfleet::Ship::Ship()
{
    _length = 289;
    _width = 132;
    _name = "Entreprise";
    _maxWarp = 6;
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << "USS " << _name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (_core->_coreReactor->isStable() == true)
        std::cout << "USS " << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << "USS " << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
    _length = length;
    _width = width;
    _name = name;
    _maxWarp = 1;
    _home = VULCAN;
    _location = _home;
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    _core = core;
    std::cout << _name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (_core->_coreReactor->isStable() == true)
        std::cout << _name << ": The core is stable at the time." << std::endl;
    else
        std::cout << _name << ": The core is unstable at the time." << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name) : _name(name)
{
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return _name;
}

int Federation::Starfleet::Captain::getAge()
{
    return _age;
}

void Federation::Starfleet::Captain::setAge(int age)
{
    _age = age;
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *captain)
{
    _captain = captain;
    std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
}

Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->isStable() == true)
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->_coreReactor->isStable() == true)
    {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->isStable() == true)
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Starfleet::Ship::move()
{
    if (_core->_coreReactor->isStable() == true)
    {
        _location = _home;
        return true;
    }
    return false;
}


bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= _maxWarp && d != _location && _core->_coreReactor->isStable() == true)
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move(int warp)
{
    if (warp <= _maxWarp && _core->_coreReactor->isStable() == true)
    {
        _location = _home;
        return true;
    }
    return false;
}

bool Federation::Ship::move(Destination d)
{
    if (d != _location && _core->_coreReactor->isStable() == true)
    {
        _location = d;
        return true;
    }
    return false;
}

bool Federation::Ship::move()
{
    if (_core->_coreReactor->isStable() == true)
    {
        _location = _home;
        return true;
    }
    return false;
}

int Federation::Starfleet::Ship::getShield()
{
    return _shield;
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    _shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return _photonTorpedo;
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    _photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedeos to fire, " << _captain->getName() << "!" << std::endl;
    else {
        _photonTorpedo--;
        target->_shield -= 50;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    }
}

void Federation::Starfleet::Ship::fire(int torpedoes, Borg::Ship *target)
{
    if (_photonTorpedo == 0)
        std::cout << _name << ": No more torpedeos to fire, " << _captain->getName() << "!" << std::endl;
    else if (torpedoes > _photonTorpedo)
        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
    else {
        _photonTorpedo -= torpedoes;
        target->_shield -= 50 * torpedoes;
        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
    }
}

WarpSystem::Core *Federation::Ship::getCore()
{
    return _core;
}