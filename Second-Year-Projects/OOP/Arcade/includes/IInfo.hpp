/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** IInfo
*/

#ifndef IINFO_HPP_
#define IINFO_HPP_

#include "includes.hpp"

namespace IInfo
{
    struct DataInfo {
        std::string Content;
        int x;
        int y;
    };
    class GameData {
        public:
            GameData() { _score = 0; };
            ~GameData() {}
            void init_info(int x , int y) {};

            std::vector<DataInfo> _map;
            std::vector<DataInfo> _enemies;
            std::string _name;
            size_t _score;
            bool _win;
            int ppos_x;
            int ppos_y;
            bool _loose;
            GameData &operator =(const GameData &assign)
            {
                _map = assign._map;
                _enemies = assign._enemies;
                _score = assign._score;
                _win = assign._win;
                _loose = assign._loose;
                ppos_x = assign.ppos_x;
                ppos_y = assign.ppos_y;
                return *this;
            }

        protected:
        private:
    };
}

#endif /* !IINFO_HPP_ */
