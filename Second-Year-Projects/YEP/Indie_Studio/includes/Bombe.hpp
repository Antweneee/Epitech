/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Bombe
*/

#ifndef BOMBE_HPP_
#define BOMBE_HPP_

#include <iostream>
#include <cstdio>
#include <ctime>
#include <chrono>
#include "Models.hpp"
#include "Textures.hpp"
#include "Core.hpp"

#define BOMBE_EXPLODE 4

class Bombe {
    public:
        Bombe();
        Bombe(const Bombe &other) = default;
        ~Bombe();
        void Activate();
        void Unload();
        bool checkChrono();
        void drawTexture();
        void startChrono(std::chrono::steady_clock::time_point startChrono) { this->_startChrono = startChrono; }

        std::chrono::steady_clock::time_point getStart() const { return this->_startChrono; }
        Vector3 getPosition() const { return this->_position; }
        bool getActive() const { return this->_active; }

        void setStart(std::chrono::steady_clock::time_point __startChrono) { this->_startChrono = __startChrono; }
        void setPosition(Vector3 position) { this->_position = position; }
        void setActive(bool active) { this->_active = active; }

        Bombe &operator=(Bombe const &bombe)
        {
            if (this == &bombe)
                return *this;
            this->_modelbombe = bombe._modelbombe;
            this->_texturebombe = bombe._texturebombe;
            this->_position = bombe._position;
            this->_active = bombe._active;
            this->_startChrono = bombe._startChrono;
            return *this;
        }

    protected:
    private:
        Models _models;
        Textures _textures;
    private:
        Model _modelbombe;
        Texture2D _texturebombe;
    private:
        Vector3 _position;
        bool _active = false;
        std::chrono::steady_clock::time_point _startChrono;
};

#endif /* !BOMBE_HPP_ */
