/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"

namespace Arcade {
    class Nibbler : public IGame
    {
        public:
            Nibbler(std::string map_path = "config/Nibbler_map.txt");
            ~Nibbler();
            void init();
            void getkey(Arcade::KEYS key);
            void game_over();
            void character_handler();
            void end_handler();
            void points_handler();
            void engine(Arcade::KEYS);
            IInfo::GameData get_game_data();
            std::vector<IInfo::DataInfo> read_file(std::string map_path);
            Arcade::PROTO get_lib_name() { return Arcade::PROTO::NIBBLER; };
            template<typename T>
            void debug(const T &to_print) { std::cout << to_print << std::endl;}

            IInfo::GameData _data;
            std::vector<std::pair<int, int>> _body_pos;
            std::pair<int, int> _prev_headpos;
            char _snake_head;
            char _snake_body;
            char _snake_tail;

        private:
        protected:
    };
}

extern "C" Arcade::Nibbler *get_game();



#endif /* !NIBBLER_HPP_ */
