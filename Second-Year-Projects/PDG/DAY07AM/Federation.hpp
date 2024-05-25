/*
** EPITECH PROJECT, 2022
** POOL
** File description:
** Federation
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include <string>

namespace Federation
{
    namespace Starfleet
    {
        class Captain;
        class Ship;
        class Ensign;
    }
    class Ship;
};

#include "Borg.hpp"
#include "Destination.hpp"
#include "WarpSystem.hpp"


namespace Federation
{

    namespace Starfleet
    {
        class Captain
        {
            private:
            std::string _name;
            int _age;

            public:
            Captain(std::string name);
            ~Captain();
            std::string getName();
            int getAge();
            void setAge(int age);
        };
        class Ship
        {
            private:
            int _length;
            int _width;
            std::string _name;
            short _maxWarp;
            Destination _location;
            Destination _home;
            int _photonTorpedo;

            public:
            Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0);
            Ship();
            ~Ship();
            WarpSystem::Core *_core;
            void setupCore(WarpSystem::Core *core);
            void checkCore();
            Captain *_captain;
            void promote(Captain *captain);
            bool move(int warp, Destination d); //set destination to d
            bool move(int warp); //set destination to _home
            bool move(Destination d); //set destination to d
            bool move(); //set_location to _home
            int _shield;
            int getShield();
            void setShield(int shield);
            int getTorpedo();
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        };
        class Ensign
        {
            private:
            std::string _name;

            public:
            Ensign(std::string name);
            ~Ensign();
        };
    };
    class Ship
    {
        private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        Destination _location;
        Destination _home;

        public:
        Ship(int length, int width, std::string name);
        ~Ship();
        WarpSystem::Core *_core;
        void setupCore(WarpSystem::Core *core);
        void checkCore();
        bool move(int warp, Destination d); //set destination to d
        bool move(int warp); //set destination to _home
        bool move(Destination d); //set destination to d
        bool move(); //set_location to _home
        WarpSystem::Core *getCore();
    };
};

#endif /* !FEDERATION_HPP_ */