/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <map>
#include <vector>
#include "data_server.h"
#include "Drawable.hpp"

class Player : public Drawable
{
    public:
        Player();
        Player(player_data_t const &data_player);
        Player(Player const &);
        ~Player();

        void handle_player(sf::RenderWindow &window, sf::Mouse &mouse);
        bool is_clicked(sf::Vector2f position);

        void set_player_id(int player_id) {_player_id = player_id;}
        void set_team_id(int team_id) {_team_id = team_id;}
        void set_action_id(player_actions action_id) {_action_id = action_id;}
        void set_level(int level) {_level = level;}
        void set_position(int pos_x, int pos_y) {_pos_x = pos_x;_pos_y = pos_y;}
        void set_rect_set(bool set) {_rect_set = set;}
        void set_moved(bool moved) {_moved = moved;}
        void set_is_animated(bool is_animated) {_is_animated = is_animated;}

        int get_pos_x() const {return _pos_x;}
        int get_pos_y() const {return _pos_y;}
        int get_player_id() const {return _player_id;}
        int get_team_id() const {return _team_id;}
        player_actions get_action_id() const {return _action_id;}
        int get_level() const {return _level;}

        Player &operator=(const Player &player) {
            _pos_x = player._pos_x;
            _pos_y = player._pos_y;
            _player_id = player._player_id;
            _team_id = player._team_id;
            _action_id = player._action_id;
            _level = player._level;
            _is_actualized = true;
            if (_action_id == MOVE_FORWARD || _action_id == INCANTATION)
                _is_animated = true;
            _nb_incatation = 0;
            _is_set = false;
            return *this;
        };
    private:
        void set_sprite_rectangle_from_action(player_actions const action);
        void check_actions(sf::RenderWindow &window);
        void check_animation();
        void do_animation(int plus_x, int plus_y);
        void incantation_animation();

        int _rect_width;
        int _rect_height;
        int _rect_top;
        int _rect_left;
        bool _is_clicked;
        bool _is_animated;
        bool _rect_set;
        bool _is_set;
        bool _moved;
        bool _is_actualized;
        int _nb_incatation;

        sf::Sprite _fork_sprite;
        sf::Texture _fork_texture;
        sf::Sprite _broadcast_sprite;
        sf::Texture _broadcast_texture;

        int _pos_x;
        int _pos_y;
        int _player_id;
        int _team_id;
        player_actions _action_id;
        int _level;

        sf::Clock _clock;
};

#endif /* !PLAYER_HPP_ */
