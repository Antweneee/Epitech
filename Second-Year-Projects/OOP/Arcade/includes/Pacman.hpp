/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"

namespace Arcade
{
    class Pacman : public IGame
    {
        public:
            Pacman(std::string map_path = "config/pac_man_map.txt");
            ~Pacman();
            void init();
            void getkey(Arcade::KEYS key);
            void game_over();
            void character_handler();
            void end_handler();
            void points_handler();
            void engine(Arcade::KEYS);
            IInfo::GameData get_game_data();
            std::vector<IInfo::DataInfo> read_file(std::string map_path);
            Arcade::PROTO get_lib_name() { return Arcade::PROTO::PACMAN; };
            template<typename T>
            void debug(const T &to_print) { std::cout << to_print << std::endl;}

        protected:
        private:
            IInfo::GameData _data;
            char _prevc;
            char e_prevc;
            int _to_win;
    };
}
extern "C" Arcade::Pacman *get_game();


#endif /* !PACMAN_HPP_ */
