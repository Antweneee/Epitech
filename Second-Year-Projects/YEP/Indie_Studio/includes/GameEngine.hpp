/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
    #define GAMEENGINE_HPP_

    #include <iostream>
    #include <fstream>
    #include <string>
    #include "Core.hpp"
    #include "Text.hpp"
    #include "Models.hpp"
    #include "Textures.hpp"
    #include "Player.hpp"
    #include "Button.hpp"
    #include "Pause.hpp"
    #include "IInfo.hpp"

class GameEngine
{
    public:
        GameEngine();
        ~GameEngine();
        void init(std::vector<PlayerSettings> &settings);
        void engine(std::vector<PlayerSettings> &settings);
        bool draw();
        void draw(char c, float x, float z);
        void findDeletedPlayer(const std::string &deleted_player);
        void pause();
        bool get_pause()&  {return this->_is_paused;};
        std::map<std::string, double> get_winner();

    protected:
    private:
        MapGeneration _mapClass;
        Core _core;
        Model _modelwall;
        Model _modelwood;
        Model _modelwoodbonus;
        Model _modelSpeedBonus;
        Model _modelBombeUpBonus;
        Model _modelShieldBonus;
        Model _modelsol;
        Texture2D _texturewall;
        Texture2D _texturewood;
        Texture2D _texturewoodbonus;
        Texture2D _textureSpeedbonus;
        Texture2D _textureBombeUpbonus;
        Texture2D _textureShieldbonus;
        Texture2D _texturesol;
        Camera3D _camera;
        Vector3 _firstpos;
        Player p1;
        Player p2;
        Player p3;
        Player p4;
        Player player;
        IInfo::PaueScenes _is_paused;
        Pause _pause;
        Models _models;
        Textures _textures;
        std::map<std::string, double> _scores;
};

#endif /* !GAMEENGINE_HPP_ */
