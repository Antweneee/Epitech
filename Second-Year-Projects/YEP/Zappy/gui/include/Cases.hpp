/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Cases
*/

#ifndef CASES_HPP_
#define CASES_HPP_

#include <map>
#include <iostream>
#include "Drawable.hpp"
#include "data_server.h"
#include "enums.hpp"

class Cases : public Drawable
{
    public:
        Cases();
        Cases(Cases const &cases);
        Cases(cases_data_t const &data_case);
        ~Cases();

        void handle_case(sf::RenderWindow &window);
        bool is_clicked(sf::Vector2f position);

        int get_food() const {return _nb_food;}
        int get_linemate() const {return _nb_linemate;}
        int get_deraumere() const {return _nb_deraumere;}
        int get_sibur() const {return _nb_sibur;}
        int get_mendiane() const {return _nb_mendiane;}
        int get_phiras() const {return _nb_phiras;}
        int get_thystame() const {return _nb_thystame;}
        int get_pos_x() const {return _pos_x; }
        int get_pos_y() const {return _pos_y; }

        void set_position(int pos_x, int pos_y) {_pos_x = pos_x;_pos_y = pos_y;}
        void set_nb_food(int nb_food) {_nb_food = nb_food;}
        void set_nb_linemate(int nb_linemate) {_nb_linemate = nb_linemate;}
        void set_nb_deraumere(int nb_deraumere) {_nb_deraumere = nb_deraumere;}
        void set_nb_sibur(int nb_sibur) {_nb_sibur = nb_sibur;}
        void set_nb_mendiane(int nb_mendiane) {_nb_mendiane = nb_mendiane;}
        void set_nb_phiras(int nb_phiras) {_nb_phiras = nb_phiras;}
        void set_nb_thystame(int nb_thystame) {_nb_thystame = nb_thystame;}

        Cases &operator=(const Cases &cases) {
            _pos_x = cases._pos_x;
            _pos_y = cases._pos_y;
            _nb_food = cases._nb_food;
            _nb_linemate = cases._nb_linemate;
            _nb_deraumere = cases._nb_deraumere;
            _nb_sibur = cases._nb_sibur;
            _nb_mendiane = cases._nb_mendiane;
            _nb_phiras = cases._nb_phiras;
            _nb_thystame = cases._nb_thystame;
            return *this;
        }
    private:
        int _pos_x;
        int _pos_y;
        int _nb_food;
        int _nb_linemate;
        int _nb_deraumere;
        int _nb_sibur;
        int _nb_mendiane;
        int _nb_phiras;
        int _nb_thystame;
};

#endif /* !CASES_HPP_ */
