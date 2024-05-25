/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Player
*/

#include "enums.hpp"
#include "Player.hpp"

Player::Player() : Drawable(84, 100), _rect_width(84), _rect_height(100), _rect_top(200), _rect_left(84), _is_clicked(false), _is_animated(true), _rect_set(false), _is_set(false), _moved(false) , _is_actualized(true), _nb_incatation(0),_team_id(0), _action_id(DEFAULT), _level(0)
{
    _fork_texture.loadFromFile("gui/assets/egg.png");
    _fork_sprite.setTexture(_fork_texture);
    _broadcast_texture.loadFromFile("gui/assets/player/text.png");
    _broadcast_sprite.setTexture(_broadcast_texture);
}

Player::Player(player_data_t const &data_player) : Drawable(84, 100), _rect_width(84), _rect_height(100), _rect_top(200), _rect_left(84), _moved(false), _is_actualized(true), _nb_incatation(0) ,_team_id(0), _action_id(DEFAULT), _level(0)
{
    set_position(data_player.pos_x, data_player.pos_y);
    set_player_id(data_player.player_id);
    set_team_id(data_player.team_id);
    set_action_id(data_player.action_id);
    set_level(data_player.level);
    if (data_player.action_id == MOVE_FORWARD || data_player.action_id == INCANTATION) {
        _is_animated = true;
    } else {
        _is_animated = false;
    }
    _is_set = false;
    _fork_texture.loadFromFile("gui/assets/egg.png");
    _fork_sprite.setTexture(_fork_texture);
    _broadcast_texture.loadFromFile("gui/assets/player/text.png");
    _broadcast_sprite.setTexture(_broadcast_texture);
}


Player::Player(Player const &player) : Drawable(84, 100)
{
    _pos_x = player._pos_x;
    _pos_y = player._pos_y;
    _player_id = player._player_id;
    _team_id = player._team_id;
    _action_id = player._action_id;
    _level = player._level;
    if (_action_id == MOVE_FORWARD || _action_id == INCANTATION) {
        _is_animated = true;
    } else {
        _is_animated = false;
    }
    _nb_incatation = 0;
    _is_set = false;
    _rect_width = 84;
    _rect_height = 100;
    _rect_top = player._rect_top;
    _rect_left = player._rect_left;
    _is_actualized = true;
    set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
    _fork_texture.loadFromFile("gui/assets/egg.png");
    _fork_sprite.setTexture(_fork_texture);
    _broadcast_texture.loadFromFile("gui/assets/player/text.png");
    _broadcast_sprite.setTexture(_broadcast_texture);
}

Player::~Player()
{
}

void Player::do_animation(int plus_x, int plus_y)
{
    float second = 0;
    sf::Time time;
    sf::IntRect rect = get_rect();
    sf::Vector2f pos = get_pos();

    time = _clock.getElapsedTime();
    second = time.asMicroseconds() / 1000000.0;
    if (second > 0.5) {
        if (rect.left == 168) {
            rect.left -= 168;
            if (rect.top == 200)
                pos.x += plus_x;
            else if (rect.top == 300)
                pos.x -= plus_x;
            else if (rect.top == 100)
                pos.y -= plus_y;
            else if (rect.top == 0)
                pos.y += plus_y;
            rect.left += 84;
        } else {
            if (rect.top == 200)
                pos.x += plus_x;
            else if (rect.top == 300)
                pos.x -= plus_x;
            else if (rect.top == 100)
                pos.y -= plus_y;
            else if (rect.top == 0)
                pos.y += plus_y;
            rect.left += 84;
        }
        _clock.restart();
        set_rect(rect);
        _rect_top = rect.top;
        _rect_left = rect.left;
        _sprite.setTextureRect(rect);
    }
    set_sprite_pos(pos);
    if ((rect.top == 200 || rect.top == 300) && pos.x == (_pos_x * CASE_SIZE) + 70) {
        _is_actualized = false;
        _is_animated = false;
    }
    if ((rect.top == 0 || rect.top == 100) && pos.y == (_pos_y * CASE_SIZE) + 60) {
        _is_actualized = false;
        _is_animated = false;
    }
}

void Player::incantation_animation()
{
    float second = 0;
    sf::Time time;
    sf::IntRect rect = get_rect();

    time = _clock.getElapsedTime();
    second = time.asMicroseconds() / 1000000.0;
    if (second > 0.5) {
        if (rect.left == 168) {
            rect.left -= 168;
            _nb_incatation++;
        } else
            rect.left += 84;
    _clock.restart();
    set_rect(rect);
    _sprite.setTextureRect(rect);
    }
    if (_nb_incatation >= 2) {
        set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
        _is_actualized = false;
    }
}

void Player::set_sprite_rectangle_from_action(player_actions const action)
{
    int rect_with = 84;
    int rect_height = 100;
    int rect_top = 0;
    int rect_left = 0;

    rect_top = get_rect().top;
    if (action == RIGHT && rect_top == 0) {
        rect_top = 300; rect_left = 84;
        set_rect(84, 100, 300, 84);
    } else if (action == RIGHT && rect_top == 100) {
        rect_top = 200; rect_left = 84;
        set_rect(84, 100, 200, 84);
    } else if (action == RIGHT && rect_top == 200) {
        rect_top = 0; rect_left = 84;
        set_rect(84, 100, 0, 84);
    } else if (action == RIGHT && rect_top == 300) {
        rect_top = 100; rect_left = 84;
        set_rect(84, 100, 100, 84);
    } else if (action == LEFT && rect_top == 0) {
        rect_top = 200; rect_left = 84;
        set_rect(84, 100, 200, 84);
    } else if (action == LEFT && rect_top == 100) {
        rect_top = 300; rect_left = 84;
        set_rect(84, 100, 300, 84);
    } else if (action == LEFT && rect_top == 200) {
        rect_top = 100; rect_left = 84;
        set_rect(84, 100, 100, 84);
    } else if (action == LEFT && rect_top == 300) {
        rect_top = 0; rect_left = 84;
        set_rect(84, 100, 0, 84);
    }
    _rect_width = rect_with;
    _rect_height = rect_height;
    _rect_top = rect_top;
    _rect_left = rect_left;
    _rect_set = true;
}

void Player::check_animation()
{
    sf::Vector2f player_pos = get_pos();

    if (_rect_top == 0) {
        player_pos.y -= 246;
    } else if (_rect_top == 100) {
        player_pos.y += 246;
    } else if (_rect_top == 200) {
        player_pos.x -= 246;
    } else if (_rect_top == 300) {
        player_pos.x += 246;
    }
    set_sprite_pos(player_pos);
    _moved = true;
}

void Player::check_actions(sf::RenderWindow &window)
{
    if (_is_actualized == false) {
        return;
    }
    if (_rect_set == false) {
        set_sprite_rectangle_from_action(_action_id);
        if (_action_id == MOVE_FORWARD || _action_id == INCANTATION)
            _is_actualized = true;
        else
            _is_actualized = false;
    }
    if (_action_id == MOVE_FORWARD && _moved == false) {
        check_animation();
    } else if (_action_id == MOVE_FORWARD && _moved == true && _is_animated == true) {
        do_animation(41, 41);
    } else if (_action_id == INCANTATION && _is_set == false) {
        if (_level == 1) {
            change_sprite("gui/assets/player/luffy_incantation_blue.png");
            set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
        } else if (_level == 2) {
            change_sprite("gui/assets/player/luffy_incantation_green.png");
            set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
        } else if (_level == 3) {
            change_sprite("gui/assets/player/luffy_incantation_orange.png");
            set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
        } else if (_level == 4) {
            change_sprite("gui/assets/player/luffy_incantation.png");
            set_rect(_rect_width, _rect_height, _rect_top, _rect_left);
        }
        set_rect(84, 100, 0, 0);
        _is_set = true;
        _nb_incatation = 0;
    }
    if (_action_id == INCANTATION && _is_set == true && _is_animated == true && _nb_incatation < 2) {
        incantation_animation();
    } else if (_action_id == BROADCAST) {
        std::cout << "here" << std::endl;
        _is_actualized = false;
        window.draw(_broadcast_sprite);
    } else if (_action_id == FORK) {
        _is_actualized = false;
        _fork_sprite.setPosition(get_pos());
        window.draw(_fork_sprite);
    }
    if (_level == 2 && _nb_incatation == 2) {
        change_sprite("gui/assets/player/luffy_walk_green.png");
    } else if (_level == 3 && _nb_incatation == 2) {
        change_sprite("gui/assets/player/luffy_walk_orange.png");
    } else if (_level == 4 && _nb_incatation == 2) {
        change_sprite("gui/assets/player/luffy_walk.png");
    }

}

void Player::handle_player(sf::RenderWindow &window, sf::Mouse &mouse)
{
    (void) mouse;
    check_actions(window);
    draw(window);
}

bool Player::is_clicked(sf::Vector2f position)
{
    std::cout << "Player x: " << position.x << " y: " << position.y << std::endl;
    if (position.x >= get_pos().x && position.x <= get_pos().x + 84 && position.y >= get_pos().y && position.y <= get_pos().y + 100) {
        return true;
    }
    return false;
}