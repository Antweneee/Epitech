/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Cases
*/

#include "Cases.hpp"

Cases::Cases() : Drawable(246, 246) , _nb_food(0), _nb_linemate(0), _nb_deraumere(0), _nb_sibur(0), _nb_mendiane(0), _nb_phiras(0), _nb_thystame(0)
{
}

Cases::Cases(Cases const &cases) : Drawable(246, 246)
{
    _pos_x = cases.get_pos_x();
    _pos_y = cases.get_pos_y();
    _nb_food = cases.get_food();
    _nb_linemate = cases.get_linemate();
    _nb_deraumere = cases.get_deraumere();
    _nb_sibur = cases.get_sibur();
    _nb_mendiane = cases.get_mendiane();
    _nb_phiras = cases.get_phiras();
    _nb_thystame = cases.get_thystame();
}

Cases::Cases(cases_data_t const &data_case) : Drawable(246, 246)
{
    set_position(data_case.pos_x, data_case.pos_y);
    set_nb_deraumere (data_case.nb_deraumere);
    set_nb_food(data_case.nb_food);
    set_nb_linemate(data_case.nb_linemate);
    set_nb_mendiane(data_case.nb_mendiane);
    set_nb_phiras(data_case.nb_phiras);
    set_nb_sibur(data_case.nb_sibur);
    set_nb_thystame(data_case.nb_thystame);
}

Cases::~Cases()
{
}

void Cases::handle_case(sf::RenderWindow &window)
{
    draw(window);
}

bool Cases::is_clicked(sf::Vector2f position)
{
    if (position.x >= (_pos_x * CASE_SIZE) && position.x <= (_pos_x * CASE_SIZE) + CASE_SIZE && position.y >= (_pos_y * CASE_SIZE) && position.y <= (_pos_y * CASE_SIZE) + CASE_SIZE) {
        return true;
    }
    return false;
}