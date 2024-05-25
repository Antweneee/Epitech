/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Display
*/

#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "enums.hpp"
#include "Display.hpp"

Display::Display(std::string machine)
{
    _textures.emplace(std::pair<std::string, sf::Texture> ("deraumere", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("food", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("linemate", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("mendiane", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("phiras", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("sibur", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("thystame", sf::Texture()));
    _textures.emplace(std::pair<std::string, sf::Texture> ("egg", sf::Texture()));

    _sprites.emplace(std::pair<std::string, sf::Sprite> ("deraumere", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("food", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("linemate", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("mendiane", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("phiras", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("sibur", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("thystame", sf::Sprite()));
    _sprites.emplace(std::pair<std::string, sf::Sprite> ("egg", sf::Sprite()));

    _positions.emplace(std::pair<std::string, sf::Vector2f> ("deraumere", sf::Vector2f(0, 0)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("food", sf::Vector2f(102, 112)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("linemate", sf::Vector2f(102, 0)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("mendiane", sf::Vector2f(0, 112)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("phiras", sf::Vector2f(196, 0)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("sibur", sf::Vector2f(196, 196)));
    _positions.emplace(std::pair<std::string, sf::Vector2f> ("thystame", sf::Vector2f(0, 196)));

    _font.loadFromFile("gui/assets/font/arial/arial.ttf");
    _settings = std::make_shared<Settings>(machine);
    _menuScene = std::make_unique<MenuScene>(_settings);
    _settingsScene = std::make_unique<SettingsScene>(_settings);

    _menuText.emplace(0, std::make_unique<sf::Text>("START", _font));
    _menuText.emplace(1, std::make_unique<sf::Text>("SETTINGS", _font));
    _menuText.emplace(2, std::make_unique<sf::Text>("EXIT", _font));

    _menuText.at(STARTBUTTON)->setFillColor(sf::Color::Black);
    _menuText.at(STARTBUTTON)->setCharacterSize(30);
    _menuText.at(STARTBUTTON)->setPosition(915, 372);

    _menuText.at(SETTINGSBUTTON)->setFillColor(sf::Color::Black);
    _menuText.at(SETTINGSBUTTON)->setCharacterSize(30);
    _menuText.at(SETTINGSBUTTON)->setPosition(885, 552);

    _menuText.at(EXITBUTTON)->setFillColor(sf::Color::Black);
    _menuText.at(EXITBUTTON)->setCharacterSize(30);
    _menuText.at(EXITBUTTON)->setPosition(930, 732);


    _settingsText.emplace(0, std::make_unique<sf::Text>("100", _font));
    _settingsText.emplace(1, std::make_unique<sf::Text>(machine.c_str(), _font));
    _settingsText.emplace(2, std::make_unique<sf::Text>("Return", _font));

    _settingsText.at(STARTBUTTON)->setFillColor(sf::Color::Black);
    _settingsText.at(STARTBUTTON)->setCharacterSize(30);
    _settingsText.at(STARTBUTTON)->setPosition(950, 365);

    _settingsText.at(SETTINGSBUTTON)->setFillColor(sf::Color::Black);
    _settingsText.at(SETTINGSBUTTON)->setCharacterSize(30);
    _settingsText.at(SETTINGSBUTTON)->setPosition(950, 650);

    _settingsText.at(EXITBUTTON)->setFillColor(sf::Color::Black);
    _settingsText.at(EXITBUTTON)->setCharacterSize(30);
    _settingsText.at(EXITBUTTON)->setPosition(300, 890);



    // std::vector<std::shared_ptr<sf::Texture>> textures;
    // textures.push_back(std::make_shared<sf::Texture>(_textures["deraumere"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["food"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["linemate"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["mendiane"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["phiras"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["sibur"]));
    // textures.push_back(std::make_shared<sf::Texture>(_textures["thystame"]));

    _boxDescriptionScene = std::make_unique<BoxDescription>();

    _displayDescription = false;
    _displayPlayerDescription = false;

    _cellDescriptionText.push_back(std::make_unique<sf::Text>("Case: x, y", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("deraumere", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("food", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("linemate", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("mendiane", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("phiras", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("sibur", _font));
    _cellDescriptionText.push_back(std::make_unique<sf::Text>("thystame", _font));

    _cellDescriptionText.at(0)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(0)->setCharacterSize(30);

    _cellDescriptionText.at(1)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(1)->setCharacterSize(30);

    _cellDescriptionText.at(2)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(2)->setCharacterSize(30);

    _cellDescriptionText.at(3)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(3)->setCharacterSize(30);

    _cellDescriptionText.at(4)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(4)->setCharacterSize(30);

    _cellDescriptionText.at(5)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(5)->setCharacterSize(30);

    _cellDescriptionText.at(6)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(6)->setCharacterSize(30);

    _cellDescriptionText.at(7)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(7)->setCharacterSize(30);

    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(50, 20));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(100, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(400, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(600, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(900, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(1200, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(1500, 130));
    _cellDescriptionTextPosition.push_back(std::make_pair<int,int>(1750, 130));


    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(50, 120));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(340, 130));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(550, 120));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(850, 120));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(1150, 120));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(1450, 120));
    _cellDescriptionSpritePosition.push_back(std::make_pair<int,int>(1700, 120));


    _playerDescriptionText.push_back(std::make_unique<sf::Text>("Teams id:", _font));
    _playerDescriptionText.push_back(std::make_unique<sf::Text>("Level:", _font));

    _cellDescriptionText.at(0)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(0)->setCharacterSize(30);
    _cellDescriptionText.at(1)->setFillColor(sf::Color::Black);
    _cellDescriptionText.at(1)->setCharacterSize(30);

    _playerDescriptionTextPosition.push_back(std::make_pair<int,int>(75, 20));
    _playerDescriptionTextPosition.push_back(std::make_pair<int,int>(75, 150));
}

Display::~Display()
{
}

void Display::init_view()
{
    _view.setCenter(1000, 625);
    _view.setSize(2000, 1250);
    _window.setView(_view);
}

void Display::init(std::vector<Player> const &players, std::vector<Cases> const &cases)
{
    set_players(players);
    for (auto &to_init : _players)
        to_init.init_sprite("gui/assets/player/luffy_walk_blue.png", (to_init.get_pos_x() * CASE_SIZE + 70), (to_init.get_pos_y() * CASE_SIZE + 60));
    set_cases(cases);
    for (auto &to_init : _cases)
        to_init.init_sprite("gui/assets/grass.png", to_init.get_pos_x() * CASE_SIZE, to_init.get_pos_y() * CASE_SIZE);
    init_cases_sprite();
    init_view();
}

void Display::init_cases_sprite()
{
    _textures["deraumere"].loadFromFile("gui/assets/ressources/deraumere.png");
    _textures["food"].loadFromFile("gui/assets/ressources/food.png");
    _textures["linemate"].loadFromFile("gui/assets/ressources/linemate.png");
    _textures["mendiane"].loadFromFile("gui/assets/ressources/mendiane.png");
    _textures["phiras"].loadFromFile("gui/assets/ressources/phiras.png");
    _textures["sibur"].loadFromFile("gui/assets/ressources/sibur.png");
    _textures["thystame"].loadFromFile("gui/assets/ressources/thystame.png");

    _textures["egg"].loadFromFile("gui/assets/egg.png");

    _sprites["deraumere"].setTexture(_textures["deraumere"]);
    _sprites["food"].setTexture(_textures["food"]);
    _sprites["linemate"].setTexture(_textures["linemate"]);
    _sprites["mendiane"].setTexture(_textures["mendiane"]);
    _sprites["phiras"].setTexture(_textures["phiras"]);
    _sprites["sibur"].setTexture(_textures["sibur"]);
    _sprites["thystame"].setTexture(_textures["thystame"]);
    _sprites["egg"].setTexture(_textures["egg"]);
}

std::vector<Player> Display::get_players() const
{
    return _players;
}

std::vector<Cases> Display::get_cases() const
{
    return _cases;
}

void Display::set_players(std::vector<Player> const &players)
{
    for (auto &i : players)
        _players.emplace_back(i);
}

void Display::set_cases(std::vector<Cases> const &cases)
{
    int max_x = 0;
    int max_y = 0;

    std::srand(std::time(nullptr));
    for (auto &i : cases) {
        if (max_x < i.get_pos_x())
            max_x = i.get_pos_x();
        if (max_y < i.get_pos_y())
            max_y = i.get_pos_y();
        _cases.emplace_back(i);
    }
    _map_max_x = max_x;
    _map_max_y = max_y;
}

void Display::reset_view(int const x_change, int const y_change)
{
    sf::Vector2f actual_center = _view.getCenter();
    sf::Vector2f view_size = _view.getSize();

    if (x_change == 7 && (actual_center.x + x_change + (view_size.x / 2) < (_map_max_x + 1) * CASE_SIZE)) {
        actual_center.x += x_change;
    } if (x_change == -7 && (actual_center.x + x_change) - (view_size.x / 2) > 0) {
        actual_center.x += x_change;
    } if (y_change == 7 && (actual_center.y + y_change + (view_size.y / 2) < (_map_max_y + 1) * CASE_SIZE)) {
        actual_center.y += y_change;
    } if (y_change == -7 && (actual_center.y + y_change) - (view_size.y / 2) > 0) {
        actual_center.y += y_change;
    }
    _view.setCenter(actual_center);
    _window.setView(_view);
}

int Display::handle_events(const Scenes &scene)
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)) {
            _window.close();
            return 1;
        }
        if (scene == Scenes::GAME) {
            if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Up) reset_view(0, -7);
            else if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Down) reset_view(0, 7);
            else if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Right) reset_view(7, 0);
            else if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Left) reset_view(-7, 0);
            if (_event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2f pos = {(float)_mouse.getPosition().x, (float)_mouse.getPosition().y};
                if (_view.getCenter().x != 1000) {
                    pos.x += _view.getCenter().x - 1000;
                }
                if (_view.getCenter().y != 625) {
                    pos.y += _view.getCenter().y - 625 + (CASE_SIZE / 2);
                }
                if (!_players.empty()) {
                    for (auto& player : _players) {
                        if (player.is_clicked(pos)) {
                            _displayDescription = false;
                            _displayPlayerDescription = true;
                            std::string tmp = "Team: " + std::to_string(player.get_team_id());
                            _playerDescriptionText.at(0)->setString(tmp);
                            tmp = "Level: " + std::to_string(player.get_level());
                            _playerDescriptionText.at(1)->setString(tmp);
                            return 0;
                        }
                    }
                }
                if (!_cases.empty()) {
                    for (auto &cell : _cases) {
                        if (cell.is_clicked(pos)) {
                            _displayDescription = true;
                            _displayPlayerDescription = false;
                            std::string caseStr = "Cell: " + std::to_string(cell.get_pos_x()) + ", " + std::to_string(cell.get_pos_y());
                            _cellDescriptionText.at(0)->setString(caseStr);
                            _cellDescriptionText.at(1)->setString(std::to_string(cell.get_deraumere()));
                            _cellDescriptionText.at(2)->setString(std::to_string(cell.get_food()));
                            _cellDescriptionText.at(3)->setString(std::to_string(cell.get_linemate()));
                            _cellDescriptionText.at(4)->setString(std::to_string(cell.get_mendiane()));
                            _cellDescriptionText.at(5)->setString(std::to_string(cell.get_phiras()));
                            _cellDescriptionText.at(6)->setString(std::to_string(cell.get_sibur()));
                            _cellDescriptionText.at(7)->setString(std::to_string(cell.get_thystame()));
                        }
                    }
                }
            }
        }
        if (scene == Scenes::MENU) {
            for (auto &button : _menuScene->getButtonList()) {
                if (button->isMouseOverButton(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))) {
                    _menuText.at(button->getId())->setFillColor(sf::Color::Yellow);
                    if (_event.type == sf::Event::MouseButtonPressed) {
                        button->onclick(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
                        _menuText.at(button->getId())->setFillColor(sf::Color::Red);
                        if (_settings->getScene() == Scenes::QUIT) {
                            _window.close();
                            return 1;
                        }
                    }
                } else {
                    _menuText.at(button->getId())->setFillColor(sf::Color::White);
                }
            }
        }
        if (scene == Scenes::SETTINGS) {
            int id;
            for (auto &button : _settingsScene->getButtonList()) {
                if (button->getId() == 0 || button->getId() == 1)
                    id = 0;
                else
                    id = button->getId();
                if (button->isMouseOverButton(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))) {
                    _settingsText.at(id)->setFillColor(sf::Color::Yellow);
                    if (_event.type == sf::Event::MouseButtonPressed) {
                        button->onclick(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y));
                        _settingsText.at(id)->setFillColor(sf::Color::Red);
                        int volume = _settings->getVolume();
                        std::string tmp = std::to_string(volume);
                        if (id == 0)
                            _settingsText.at(id)->setString(tmp);
                    }
                } else {
                    if (id > 1 || (button->getId() == 0 && !_settingsScene->getButtonList().at(1)->isMouseOverButton(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y))) || (button->getId() == 1 && !_settingsScene->getButtonList().at(0)->isMouseOverButton(std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))) {
                        _settingsText.at(id)->setFillColor(sf::Color::White);
                    }
                }
            }
            if (_event.type == sf::Event::KeyPressed) {
                for (auto &key : _keys) {
                    if (key == _event.key.code) {
                        _settingsText.at(1)->setString(_settingsScene->updateSrting(_settingsText.at(1)->getString().toAnsiString(), key));
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

int Display::engine()
{
    if (handle_events(_settings->getScene()) == 1)
        return 1;
    clear();
    draw(_settings->getScene());
    return 0;
}

void Display::refresh_players(std::vector<Player> &players)
{
    bool is_new = true;

    for (auto &new_player : players) {
        for (auto &current_players : _players) {
            if (new_player.get_player_id() == current_players.get_player_id()) {
                current_players = new_player;
                if (current_players.get_action_id() == MOVE_FORWARD || current_players.get_action_id() == INCANTATION)
                    current_players.set_is_animated(true);
                is_new = false;
                break;
            }
        }
        if (is_new == true)
            _players.emplace_back(new_player);
        is_new = true;
    }
    for (auto &player : _players) {
        if (player.get_level() == 1)
            player.init_sprite("gui/assets/player/luffy_walk_blue.png", (player.get_pos_x() * CASE_SIZE + 70), (player.get_pos_y() * CASE_SIZE + 60));
        else if (player.get_level() == 2)
            player.init_sprite("gui/assets/player/luffy_walk_green.png", (player.get_pos_x() * CASE_SIZE + 70), (player.get_pos_y() * CASE_SIZE + 60));
        else if (player.get_level() == 3)
            player.init_sprite("gui/assets/player/luffy_walk_orange.png", (player.get_pos_x() * CASE_SIZE + 70), (player.get_pos_y() * CASE_SIZE + 60));
        else if (player.get_level() == 4)
            player.init_sprite("gui/assets/player/luffy_walk.png", (player.get_pos_x() * CASE_SIZE + 70), (player.get_pos_y() * CASE_SIZE + 60));
        player.set_rect_set(false);
        player.set_moved(false);
        if (player.get_action_id() == MOVE_FORWARD)
            player.set_is_animated(true);
    }
}

void Display::refresh_cases(std::vector<Cases> &cases)
{
    bool is_new = true;

    for (auto &new_cases : cases) {
        for (auto &current_cases : _cases) {
            if (new_cases.get_pos_x() == current_cases.get_pos_x() && new_cases.get_pos_y() == current_cases.get_pos_y()) {
                current_cases = new_cases;
                is_new = false;
                break;
            }
        }
        if (is_new == true)
            _cases.emplace_back(new_cases);
        is_new = true;
    }
    for (auto &_case : _cases)
        _case.init_sprite("gui/assets/grass.png", _case.get_pos_x() * CASE_SIZE, _case.get_pos_y() * CASE_SIZE);
}


void Display::refresh_datas(std::vector<Player> &players, std::vector<Cases> &cases)
{
    if (!players.empty())
        refresh_players(players);
    if (!cases.empty())
        refresh_cases(cases);
}

void Display::destroy_all()
{
}

void Display::is_here(Cases const &cases)
{
    sf::Vector2f tmp;
    tmp.x = cases.get_pos_x() * CASE_SIZE;
    tmp.y = cases.get_pos_y() * CASE_SIZE;

    if (cases.get_deraumere() > 0) {
        _sprites["deraumere"].setPosition(tmp.x + _positions["deraumere"].x, tmp.y + _positions["deraumere"].y);
        _window.draw(_sprites["deraumere"]);
    }
    if (cases.get_food() > 0) {
        _sprites["food"].setPosition(tmp.x + _positions["food"].x, tmp.y + _positions["food"].y);
        _window.draw(_sprites["food"]);
    }
    if (cases.get_linemate() > 0) {
        _sprites["linemate"].setPosition(tmp.x + _positions["linemate"].x, tmp.y + _positions["linemate"].y);
        _window.draw(_sprites["linemate"]);
    }
    if (cases.get_mendiane() > 0) {
        _sprites["mendiane"].setPosition(tmp.x + _positions["mendiane"].x, tmp.y + _positions["mendiane"].y);
        _window.draw(_sprites["mendiane"]);
    }
    if (cases.get_phiras() > 0) {
        _sprites["phiras"].setPosition(tmp.x + _positions["phiras"].x, tmp.y + _positions["phiras"].y);
        _window.draw(_sprites["phiras"]);
    }
    if (cases.get_sibur() > 0) {
        _sprites["sibur"].setPosition(tmp.x + _positions["sibur"].x, tmp.y + _positions["sibur"].y);
        _window.draw(_sprites["sibur"]);
    }
    if (cases.get_thystame() > 0) {
        _sprites["thystame"].setPosition(tmp.x + _positions["thystame"].x, tmp.y + _positions["thystame"].y);
        _window.draw(_sprites["thystame"]);
    }
}

void Display::draw_cases_sprites()
{
    for (auto &cases : _cases) {
        cases.handle_case(_window);
        is_here(cases);
    }
}

void Display::draw(const Scenes &scene)
{
    if (scene == Scenes::MENU)
        draw_menu(scene);
    if (scene == Scenes::SETTINGS)
        draw_menu(scene);
    if (scene == Scenes::GAME) {
        draw_cases_sprites();
        for (auto &player : _players)
            player.handle_player(_window, _mouse);
        if (_displayDescription || _displayPlayerDescription)
            draw_description();
    }
    _window.display();
}

void Display::clear()
{
    _window.clear(sf::Color::White);
}

std::shared_ptr<Settings> Display::getSettings() const
{
    return _settings;
}

void Display::init_menu()
{
    if (!_window.isOpen()) {
        _window.create(sf::VideoMode(1920, 1080), "Zappy GUI");
        _window.setFramerateLimit(60);

    }
    _settings->playMusic(0);
}

void Display::draw_menu(const Scenes &scene)
{
    if (scene == Scenes::MENU) {
        _window.draw(_menuScene->getSkySprite());
        _window.draw(_menuScene->getSunnySprite());
        for (auto &button : _menuScene->getButtonList()) {
            _window.draw(button->getSprite());
        }
        _window.draw(*_menuText.at(STARTBUTTON));
        _window.draw(*_menuText.at(SETTINGSBUTTON));
        _window.draw(*_menuText.at(EXITBUTTON));
    }
    if (scene == Scenes::SETTINGS) {
        _window.draw(_menuScene->getSkySprite());
        _window.draw(_menuScene->getSunnySprite());
        _window.draw(_settingsScene->getRectangleShape());
        for (auto &button : _settingsScene->getButtonList()) {
            _window.draw(button->getSprite());
        }
        _window.draw(*_settingsText.at(0));
        _window.draw(*_settingsText.at(1));
        _window.draw(*_settingsText.at(2));
    }
}

void Display::draw_description()
{
    sf::Vector2f viewPos = _view.getCenter();
    sf::Vector2f boxPos = {viewPos.x - 960, viewPos.y + 312 + 90};

    _boxDescriptionScene->setPosBoxSprite(boxPos);
    _window.draw(_boxDescriptionScene->getBoxSprite());

    if (_displayDescription) {
        std::vector<std::pair<int, int>> positions;

        for (auto &pos : _cellDescriptionSpritePosition) {
            positions.push_back(std::make_pair(boxPos.x + pos.first, boxPos.y + pos.second));
        }
        _boxDescriptionScene->setPosMapSprite(positions);

        _window.draw(_boxDescriptionScene->getDeraumereSprite());
        _window.draw(_boxDescriptionScene->getFoodSprite());
        _window.draw(_boxDescriptionScene->getLinemateSprite());
        _window.draw(_boxDescriptionScene->getMendianeSprite());
        _window.draw(_boxDescriptionScene->getPhirasSprite());
        _window.draw(_boxDescriptionScene->getSiburSprite());
        _window.draw(_boxDescriptionScene->getThystameSprite());

        if (!_cellDescriptionText.empty() && !_cellDescriptionTextPosition.empty()) {
            for (std::size_t i = 0; i < _cellDescriptionText.size(); i++) {
                _cellDescriptionText.at(i)->setPosition(boxPos.x + _cellDescriptionTextPosition.at(i).first, boxPos.y + _cellDescriptionTextPosition.at(i).second);
                _window.draw(*_cellDescriptionText.at(i));
            }
        }
    }

    if (_displayPlayerDescription) {
        if (!_playerDescriptionText.empty() && !_playerDescriptionTextPosition.empty()) {
            for (std::size_t i = 0; i < _playerDescriptionText.size(); i++) {
                _playerDescriptionText.at(i)->setPosition(boxPos.x + _playerDescriptionTextPosition.at(i).first, boxPos.y + _playerDescriptionTextPosition.at(i).second);
                _window.draw(*_playerDescriptionText.at(i));
            }
        }
    }
}