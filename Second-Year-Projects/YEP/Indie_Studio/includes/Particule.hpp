/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Particule
*/

#ifndef PARTICULE_HPP_
    #define PARTICULE_HPP_
    #include <raylib.h>

class Particule {
    public:
        struct particule {
            Vector2 position;
            Color color;
            float alpha;
            float size;
            float rotation;
            bool active;
        };
        using Particle = struct particule;
        Particule();
        ~Particule();

    protected:
    private:
};

#endif /* !PARTICULE_HPP_ */
