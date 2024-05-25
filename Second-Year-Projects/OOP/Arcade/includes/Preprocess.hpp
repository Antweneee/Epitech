/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** Preprocess
*/

#ifndef PREPROCESS_HPP_
#define PREPROCESS_HPP_

#include "enum.hpp"
#include "includes.hpp"
#include "IGame.hpp"
#include "IDisplay.hpp"

namespace Preprocessor
{
    class Loader
    {
        public:
            Loader(const std::string &file);
            ~Loader();
            void StartGame(Arcade::PROTO, Arcade::PROTO);
            void *LoadGame(std::string lib, Arcade::PROTO);
            void *LoadGraphics(std::string lib, Arcade::PROTO);
            bool LibChange(Arcade::KEYS KEY);
            void startChange(Arcade::PROTO cible, int game);
            std::unique_ptr<IGame> _class_game;
            std::unique_ptr<IDisplay> _class_display;
            void engine();
            void save_score(IInfo::GameData data);
            void set_name(std::string name) { _name = name;}

        private:
            Arcade::PROTO _initial_lib;
            Arcade::PROTO _loaded_game;
            Arcade::PROTO _loaded_graphics;
            void *_lib_game;
            void *_lib_graphics;
            bool _game_status;
            int _score;
            std::string _name;
            //std::vector<std::string> _map;
    };
}

#endif /* !PREPROCESS_HPP_ */
