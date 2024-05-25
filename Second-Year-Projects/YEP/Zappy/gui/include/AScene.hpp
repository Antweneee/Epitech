/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
    #define ASCENE_HPP_

    #include "Settings.hpp"

class AScene {
    public:
        AScene(std::shared_ptr<Settings> settings) : _settings(settings) {}
        virtual ~AScene() = default;

    protected:
        std::shared_ptr<Settings> _settings;
        Scenes _scene;

    private:
};

#endif /* !ASCENE_HPP_ */
