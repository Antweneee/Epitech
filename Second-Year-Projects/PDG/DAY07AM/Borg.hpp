/*
** EPITECH PROJECT, 2022
** POOL
** File description:
** Borg
*/

#ifndef BORG_HPP_
#define BORG_HPP_

#include "Destination.hpp"
#include "WarpSystem.hpp"

namespace Borg {
    class Ship;
};

#include "Federation.hpp"

namespace Borg
{
    class Ship
    {
        private:
        int _side;
        int _maxWarp;
        Destination _location;
        Destination _home;
        int _weaponFrequency;
        short _repair;

        public:
        int _shield;
        Ship(int weaponFrequency = 20, short repair = 3);
        ~Ship();
        WarpSystem::Core *_core;
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d); //set destination to d
        bool move(int warp); //set destination to _home
        bool move(Destination d); //set destination to d
        bool move(); //set_location to _home
        int getShield();
        void setShield(int shield);
        int getWeaponFrequency();
        void setWeaponFrequency(int frequency);
        short getRepair();
        void setRepair(short repair);
        void fire(Federation::Starfleet::Ship *target);
        void fire(Federation::Ship *target);
        void repair();
    };
};

#endif /* !BORG_HPP_ */