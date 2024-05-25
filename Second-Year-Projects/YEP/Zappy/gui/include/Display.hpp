/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

    #include <vector>
    #include "SFML_includes.hpp"
    #include "Player.hpp"
    #include "Cases.hpp"
    #include "scenes.hpp"
    #include "MenuScene.hpp"
    #include "SettingsScene.hpp"
    #include "BoxDescription.hpp"
    #include "keys.hpp"

class Display
{
    public:
        Display(std::string machine);
        ~Display();

        std::vector<Player> get_players() const;
        std::vector<Cases> get_cases() const;

        void init_menu();
        void draw_menu(const Scenes &scene);
        void init(std::vector<Player> const &players, std::vector<Cases> const &cases);
        int engine();
        void refresh_datas(std::vector<Player> &players, std::vector<Cases> &cases);
        void destroy_all();

        std::shared_ptr<Settings> getSettings() const;

    private:
        int handle_events(const Scenes &scene);
        void set_players(std::vector<Player> const &);
        void set_cases(std::vector<Cases> const &);
        void draw(const Scenes &scene);
        void clear();
        void reset_view(int const x_change, int const y_change);
        void refresh_players(std::vector<Player> &players);
        void refresh_cases(std::vector<Cases> &cases);
        void init_cases_sprite();
        void init_view();
        void draw_cases_sprites();
        void is_here(Cases const &cases);
        void draw_description();

        std::vector<Player> _players;
        std::vector<Cases> _cases;

        std::map <std::string, sf::Sprite> _sprites;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Vector2f> _positions;
        std::map<int, std::unique_ptr<sf::Text>> _menuText;
        std::map<int, std::unique_ptr<sf::Text>> _settingsText;
        std::vector<std::unique_ptr<sf::Text>> _cellDescriptionText;
        std::vector<std::pair<int,int>> _cellDescriptionTextPosition;
        std::vector<std::pair<int,int>> _cellDescriptionSpritePosition;

        std::vector<std::unique_ptr<sf::Text>> _playerDescriptionText;
        std::vector<std::pair<int,int>> _playerDescriptionTextPosition;

        sf::Font _font;

        std::shared_ptr<Settings> _settings;
        std::unique_ptr<MenuScene> _menuScene;
        std::unique_ptr<SettingsScene> _settingsScene;
        std::unique_ptr<BoxDescription> _boxDescriptionScene;

        bool _displayDescription;
        bool _displayPlayerDescription;

        int _map_max_x;
        int _map_max_y;
        bool _click;

        sf::Mouse _mouse;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::View _view;

        std::vector<sf::Keyboard::Key> _keys = {
            sf::Keyboard::Key::A,
            sf::Keyboard::Key::B,
            sf::Keyboard::Key::C,
            sf::Keyboard::Key::D,
            sf::Keyboard::Key::E,
            sf::Keyboard::Key::F,
            sf::Keyboard::Key::H,
            sf::Keyboard::Key::I,
            sf::Keyboard::Key::J,
            sf::Keyboard::Key::K,
            sf::Keyboard::Key::L,
            sf::Keyboard::Key::M,
            sf::Keyboard::Key::N,
            sf::Keyboard::Key::O,
            sf::Keyboard::Key::P,
            sf::Keyboard::Key::Q,
            sf::Keyboard::Key::R,
            sf::Keyboard::Key::S,
            sf::Keyboard::Key::T,
            sf::Keyboard::Key::U,
            sf::Keyboard::Key::V,
            sf::Keyboard::Key::W,
            sf::Keyboard::Key::X,
            sf::Keyboard::Key::Y,
            sf::Keyboard::Key::Z,
            sf::Keyboard::Key::Num0,
            sf::Keyboard::Key::Num1,
            sf::Keyboard::Key::Num2,
            sf::Keyboard::Key::Num3,
            sf::Keyboard::Key::Num4,
            sf::Keyboard::Key::Num5,
            sf::Keyboard::Key::Num6,
            sf::Keyboard::Key::Num7,
            sf::Keyboard::Key::Num8,
            sf::Keyboard::Key::Num9,
            sf::Keyboard::Key::Backspace,
            sf::Keyboard::Key::Space,
        };
};

#endif /* !DISPLAY_HPP_ */
