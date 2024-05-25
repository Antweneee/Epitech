/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Player
*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <raylib.h>
#include "Player.hpp"
#include "map.hpp"

Player::Player(const std::string& modelPath, const std::string& TexturePath, PlayerSettings &settings) : _animsCount(0), _rotation(90), _frameCounter(0), _is_ai(settings.get_isAi()), _is_alive(true), _playerChar(settings.get_map_char()), _position(settings.get_pos())
{
    _model = _models.loadModel(modelPath);
    _texture = _textures.loadTexture(TexturePath);
    _animations = _models.loadModelAnimations(modelPath, _animsCount);
    _models.setMaterialTexture(_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
}

Player::~Player()
{
    //this->unloadPlayerScope();
}

float get_next_dizaine(int position)
{
    while (position != 200) {
        position++;
        if (position % 5 == 0 && position % 10 != 0)
            return position;
    }
    return position;
}

float get_previous_dizaine(int position)
{
    while (position != 0) {
        position--;
        if (position % 5 == 0 && position % 10 != 0)
            return position;
    }
    return position;
}

void Player::interpret_key(MapGeneration &mapClass)
{
    std::map<std::string, std::string> bindings = _settings.get_bindings();
    std::string up = bindings.at("up");
    std::string down = bindings.at("down");
    std::string left = bindings.at("left");
    std::string right = bindings.at("right");
    std::string bomb = bindings.at("bomb");

    if (_settings.get_controller().compare("Controller") == 0) {
        for (auto const &[bind_key, raylib_key] : _controller_interpreter) {
            if (up.compare(bind_key) == 0) {
                ControllerMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerUp(mapClass);});
            } else if (down.compare(bind_key) == 0) {
                ControllerMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerDown(mapClass);});
            } else if (left.compare(bind_key) == 0) {
                ControllerMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerLeft(mapClass);});
            } else if (right.compare(bind_key) == 0) {
                ControllerMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerRight(mapClass);});
            } else if (bomb.compare(bind_key) == 0) {
                _c_bomb_key = raylib_key;
            }
        }
    } else {
        for (auto const &[bind_key, raylib_key] : _key_interpreter) {
            if (up.compare(bind_key) == 0 && (bind_key == "Z" || bind_key == "I" || bind_key == "UP_ARROW")) {
                keyMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerUp(mapClass);});
            } else if (down.compare(bind_key) == 0 && (bind_key == "S" || bind_key == "K" || bind_key == "DOWN_ARROW")) {
                keyMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerDown(mapClass);});
            } else if (left.compare(bind_key) == 0 && (bind_key == "Q" || bind_key == "J" || bind_key == "LEFT_ARROW")) {
                keyMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerLeft(mapClass);});
            } else if (right.compare(bind_key) == 0 && (bind_key == "D" || bind_key == "L" || bind_key == "RIGHT_ARROW")) {
                keyMethodPtr.emplace(raylib_key, [this, mapClass](){movePlayerRight(mapClass);});
            } else if (bomb.compare(bind_key) == 0 && (bind_key == "SPACE" || bind_key == "U" || bind_key == ":")) {
                _bomb_key = raylib_key;
            }
        }
    }
}

void Player::initPlayer(MapGeneration &mapClass, PlayerSettings &settings)
{
    _settings = settings;
    this->_next_x = get_next_dizaine(this->_position.x);
    this->_next_z = get_next_dizaine(this->_position.z);
    this->_previous_x = get_previous_dizaine(this->_position.x);
    this->_previous_z = get_previous_dizaine(this->_position.z);
    if (!_is_ai)
        interpret_key(mapClass);
    _playerChar = _settings.get_map_char();
    _lastChar = ' ';
    this->setSpeed(1.25f);
    this->setBombeUp(3);
    this->setIsSpeed(false);
    this->setIsBombeUp(false);
    this->setIsShield(false);
    _lifespan_start = std::chrono::system_clock::now();
}

void Player::manageCorePlayer(Core core)
{
    if (_is_alive) {
        if (!_is_ai) {
            if (_settings.get_controller().compare("Controller") == 0) {
                if (core.isGamepadButtonDown(0, _c_bomb_key) && bombe.getActive() == false) {
                    bombe.Activate();
                    bombe.setActive(true);
                    bombe.setPosition(_position);
                    bombe.startChrono(std::chrono::steady_clock::now());
                    this->_lastChar = 'b';
                }
            } else {
                if (core.isKeyDown(_bomb_key) && bombe.getActive() == false) {
                    bombe.Activate();
                    bombe.setActive(true);
                    bombe.setPosition(_position);
                    bombe.startChrono(std::chrono::steady_clock::now());
                    this->_lastChar = 'b';
                }
            }
        }
        _models.drawModelEx(_model, _position, {0.0f, 1.0f, 0.0f}, _rotation, {4.0f, 4.0f, 4.0f}, WHITE);
    }
}

void Player::movePlayerInMap(MapGeneration &map)
{
    if (this->_position.x >= this->_next_x) { // move a droite
        this->_next_x = get_next_dizaine(this->_position.x);
        this->_previous_x = this->_next_x - 10;
        this->_lastChar = map.movePlayer(this->_playerChar, 1, 0, this->_lastChar);
    }
    else if (this->_position.x < this->_previous_x) { // move a gauche
        this->_previous_x = get_previous_dizaine(this->_position.x);
        this->_next_x = this->_previous_x + 10;
        this->_lastChar = map.movePlayer(this->_playerChar, -1, 0, this->_lastChar);
    }
    else if (this->_position.z >= this->_next_z) { // move en bas
        this->_next_z = get_next_dizaine(this->_position.z);
        this->_previous_z = this->_next_z - 10;
        this->_lastChar = map.movePlayer(this->_playerChar, 0, 1, this->_lastChar);
    }
    else if (this->_position.z < this->_previous_z) { // move en haut
        this->_previous_z = get_previous_dizaine(this->_position.z);
        this->_next_z = this->_previous_z + 10;
        this->_lastChar = map.movePlayer(this->_playerChar, 0, -1, this->_lastChar);
    }
}

static bool isBonus(char c)
{
    return c == '1' || c == '2' || c == '3';
}

void Player::executePlayerBonus()
{
    if (this->_lastChar == '1') {
        if (this->getIsSpeed() == false)
            this->setSpeed(this->getSpeed() + 0.75f);
        this->setIsSpeed(true);
        this->startBonusChrono(std::chrono::steady_clock::now(), SPEED);
    }
    if (this->_lastChar == '2') {
        if (this->getIsBombeUp() == false)
            this->setBombeUp(this->getBombeUp() + 3);
        this->setIsBombeUp(true);
        this->startBonusChrono(std::chrono::steady_clock::now(), BOMBE_UP);
    }
    if (this->_lastChar == '3') {
        this->setIsShield(true);
        this->startBonusChrono(std::chrono::steady_clock::now(), SHIELD);
    }
}

bool Player::isPlayerBonus()
{
    return this->getIsSpeed() == true || this->getIsBombeUp() == true || this->getIsShield() == true;
}

void Player::managePlayerBonus()
{
    if (this->getIsSpeed() == true) {
        std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - this->getSpeedChrono();
        if (elapsed.count() > SPEED_DOWN) {
            this->setSpeed(this->getSpeed() - 0.75f);
            this->setIsSpeed(false);
        }
    }
    if (this->getIsBombeUp() == true) {
        std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - this->getBombeUpChrono();
        if (elapsed.count() > BOMBE_UP_DOWN) {
            this->setBombeUp(this->getBombeUp() - 3);
            this->setIsBombeUp(false);
        }
    }
    if (this->getIsShield() == true) {
        std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - this->getShieldChrono();
        if (elapsed.count() > SHIELD_DOWN)
            this->setIsShield(false);
    }
}

void Player::managePlayer(Core core, MapGeneration &map)
{
    if (_is_ai && _is_alive) {
        manageIA(map);
        this->manageCorePlayer(core);
    }
    if (!_is_alive)
        return;
    if (_settings.get_controller().compare("Controller") == 0) {
        for (const auto &[ControllerKey, funcMovePlayer] : ControllerMethodPtr) {
            if (bombe.getActive() == true) {
                if (bombe.checkChrono() == true) {
                    bombe.setActive(false);
                    this->setIsBombe(true);
                    this->setBombeposition(bombe.getPosition());
                }
                bombe.drawTexture();
            }
            if (isBonus(this->_lastChar) == true)
                this->executePlayerBonus();
            if (this->isPlayerBonus() == true)
                this->managePlayerBonus();
            if (_is_ai)
                return;
            if (core.isGamepadButtonDown(0, ControllerKey)) {
                (funcMovePlayer)();
                this->updatePlayerAnimation();
                movePlayerInMap(map);
            }
        }
    } else {
        for (const auto &[keyBoardKey, funcMovePlayer] : keyMethodPtr) {
            if (bombe.getActive() == true) {
                if (bombe.checkChrono() == true) {
                    bombe.setActive(false);
                    this->setIsBombe(true);
                    this->setBombeposition(bombe.getPosition());
                }
                bombe.drawTexture();
            }
            if (isBonus(this->_lastChar) == true)
                this->executePlayerBonus();
            if (this->isPlayerBonus() == true)
                this->managePlayerBonus();
            if (_is_ai)
                return;
            if (core.isKeyDown(keyBoardKey)) {
                (funcMovePlayer)();
                this->updatePlayerAnimation();
                movePlayerInMap(map);
            }
        }
    }
    this->manageCorePlayer(core);
}

void Player::unloadPlayerScope()
{
    for (unsigned int i = 0; i < _animsCount; i++)
        _models.unloadModelAnimation(*_animations.get());
    _textures.unloadTexture(_texture);
    _models.unloadModel(_model);
}

void Player::updatePlayerAnimation()
{
    _frameCounter += 10;
    _models.updateModelAnimation(_model, *_animations, _frameCounter);
    if (_frameCounter >= _animations.get()->frameCount)
        _frameCounter = 0;
}

char checkNextChar(char player, int LR, int UD, MapGeneration &mapClass)
{
    std::vector<std::string> map = mapClass.readMap();
    std::string str1;
    str1.push_back(player);

    for (size_t i = 0; i != map.size(); i++) {
        size_t found = map[i].find(str1);
        if (found != std::string::npos) {
            if (LR)
                return map[i][found + LR];
            else if (UD)
                return map[i + UD][found];
        }
    }
    return '#';
}

void Player::IAdropBomb()
{
    //std::cout << "BOOOMMMMMBBBBEEE posted by player " << _playerChar << std::endl;
    bombe.Activate();
    bombe.setActive(true);
    bombe.setPosition(_position);
    bombe.startChrono(std::chrono::steady_clock::now());
    this->_lastChar = 'b';
}

/*
void Player::hideIA(MapGeneration mapClass)
{
    if (bombe.getActive() == true && _lastChar != 'b')
        findSafePlace(mapClass);
}
*/

bool Player::IsNearBomb(MapGeneration mapClass)
{
    std::vector<std::string> map = mapClass.readMap();
    int posXp = mapClass.getPlayerXpos(_playerChar);
    int posZp = mapClass.getPlayerZpos(_playerChar);

    if (map[posZp][posXp + 1] && (map[posZp][posXp + 1] == 'X' || (map[posZp][posXp + 1] >= 'A' && map[posZp][posXp + 1] <= 'D')))
        return true;
    if (map[posZp][posXp - 1] && (map[posZp][posXp - 1] == 'X' || (map[posZp][posXp - 1] >= 'A' && map[posZp][posXp - 1] <= 'D')))
        return true;
    if (map[posZp + 1][posXp] && (map[posZp + 1][posXp] == 'X' || (map[posZp + 1][posXp] >= 'A' && map[posZp + 1][posXp] <= 'D')))
        return true;
    if (map[posZp - 1][posXp] && (map[posZp - 1][posXp] == 'X' || (map[posZp][posXp - 1] >= 'A' && map[posZp][posXp - 1] <= 'D')))
        return true;
    return false;
}

bool Player::checkIsVeryFar(MapGeneration mapClass, int posXp, int posZp)
{
    std::vector<std::string> map = mapClass.readMap();

    if (map[posZp - 1][posXp] != 'X' && map[posZp - 1][posXp - 1] != 'X'
    && map[posZp - 1][posXp + 1] != 'X' && map[posZp][posXp + 1] != 'X'
    && map[posZp + 1][posXp + 1] != 'X' && map[posZp + 1][posXp - 1] != 'X'
    && map[posZp ][posXp - 1] != 'X') {
        if (_playerChar == 'A') {
            if (map[posZp + 1][posXp] == ' ' || (map[posZp + 1][posXp] >= 1 && map[posZp + 1][posXp] <= 3)) {
                _rotation = 90;
                _position.z += 7.5;
            }
            else {
                _rotation = 180;
                _position.x += 7.5;
            }
        }
        if (_playerChar == 'B') {
            if (map[posZp + 1][posXp] == ' ' || (map[posZp + 1][posXp] >= 1 && map[posZp + 1][posXp] <= 3)) {
                _rotation = 90;
                _position.z += 7.5;
            }
            else {
                _rotation = 0;
                _position.x -= 7.5;
            }
        }
        if (_playerChar == 'C') {
            if (map[posZp - 1][posXp] == ' ' || (map[posZp - 1][posXp] >= 1 && map[posZp - 1][posXp] <= 3)) {
                _rotation = -90;
                _position.z -= 7.5;
            }
            else {
                _rotation = 0;
                _position.x -= 7.5;
            }
        }
        if (_playerChar == 'D') {
            if (map[posZp - 1][posXp] == ' ' || (map[posZp - 1][posXp] >= 1 && map[posZp - 1][posXp] <= 3)) {
                _rotation = -90;
                _position.z -= 7.5;
            }
            else {
                _rotation = 180;
                _position.x += 7.5;
            }
        }
        movePlayerInMap(mapClass);
        return true;
    }
    return false;
}

void Player::moveIa(MapGeneration mapClass)
{
    int random;
    bool done = false;
    std::vector<std::string> map = mapClass.readMap();
    int posXp = mapClass.getPlayerXpos(_playerChar);
    int posZp = mapClass.getPlayerZpos(_playerChar);
    int count = 0;
    if (checkIsVeryFar(mapClass, posXp, posZp) == true)
        return;

    while (done == false) {
        count++;
            if (count < 15)
                random = rand()%(4 - 1 + 1 ) + 1;
            else
                done = true;
        if (random == 1 && (map[posZp - 1][posXp] == ' ' || (map[posZp - 1][posXp] <= 3 && map[posZp - 1][posXp] >= 1))) {
            _rotation = -90;
            _position.z -= 7.5;
            done = true;
        }
        else if (random == 2 && (map[posZp][posXp + 1] == ' ' || (map[posZp][posXp + 1] <= 3 && map[posZp][posXp + 1] >= 1))) {
            //std::cout << "DROITE pour " << _playerChar << std::endl;
            _rotation = 180;
            _position.x += 7.5;
            done = true;
        }
        else if (random == 3 && (map[posZp + 1][posXp] == ' ' || (map[posZp + 1][posXp] <= 3 && map[posZp + 1][posXp] >= 1))) {
            //std::cout << "BAS pour " << _playerChar << std::endl;
            _rotation = 90;
            _position.z += 7.5;
            done = true;
        }
        else if (random == 4 && (map[posZp][posXp - 1] == ' ' || (map[posZp][posXp - 1] <= 3 && map[posZp][posXp - 1] >= 1))) {
            //std::cout << "GAUCHE pour " << _playerChar << std::endl;
            _rotation = 0;
            _position.x -= 7.5;
            done = true;
        }
    }
    movePlayerInMap(mapClass);
}

bool Player::checkIsSafe(MapGeneration mapClass)
{
    int posXp = mapClass.getPlayerXpos(_playerChar);
    int posZp = mapClass.getPlayerZpos(_playerChar);
    std::vector<std::string> map = mapClass.readExplosionImpact();

    if (map[posZp][posXp] == 'T' || _lastChar == 'b')
        return false;
    return true;
}

void Player::findSafePlace(MapGeneration mapClass)
{
    int posXp = mapClass.getPlayerXpos(_playerChar);
    int posZp = mapClass.getPlayerZpos(_playerChar);
    std::vector<std::string> explosedMap = mapClass.readExplosionImpact();
    std::vector<std::string> map = mapClass.readMap();
    int random = 1;
    bool done = false;
    int count = 0;

    //std::cout << "cherche endroit sur" << std::endl;

    if (_lastChar == 'b') {
        //std::cout << "last b" << std::endl;
        while (done == false) {
            count++;
            if (count < 15)
                random = rand()%(4 - 1 + 1 ) + 1;
            else
                done = true;
            if (random == 1 && map[posZp - 1][posXp] == ' ') {
                _rotation = -90;
                _position.z -= 7.5;
                done = true;
            }
            else if (random == 2 && map[posZp][posXp + 1] == ' ') {
                _rotation = 180;
                _position.x += 7.5;
                done = true;
            }
            else if (random == 3 && map[posZp + 1][posXp] == ' ') {
                _rotation = 90;
                _position.z += 7.5;
                done = true;
            }
            else if (random == 4 && map[posZp][posXp - 1] == ' ') {
                _rotation = 0;
                _position.x -= 7.5;
                done = true;
            }
        }
        movePlayerInMap(mapClass);
    }
    else {
        //std::cout << "calcul other" << std::endl;

        for (int i = 1; ; i++) {
            if (0 < posZp - i && explosedMap[posZp - i][posXp] == ' ') {
                _next_pos_ia_z = posZp - i;
                _next_pos_ia_x = posXp;
                break;
            }
            else if ((int)explosedMap[posZp].size() >= posXp + i && explosedMap[posZp][posXp + i] == ' ') {
                _next_pos_ia_z = posZp;
                _next_pos_ia_x = posXp + i;
                break;
            }
            else if ((int)explosedMap.size() - 1 >= posZp + i && explosedMap[posZp + i][posXp] == ' ') {
                _next_pos_ia_z = posZp + i;
                _next_pos_ia_x = posXp;
                break;
            }
            else if (0 < posXp - i && explosedMap[posZp][posXp - i] == ' ') {
                _next_pos_ia_z = posZp;
                _next_pos_ia_x = posXp - i;
                break;
            }
        }
        calculated_next_safe_pos = true;
    }
}

void Player::goToSafePlace(MapGeneration mapClass)
{
    int posXp = mapClass.getPlayerXpos(_playerChar);
    int posZp = mapClass.getPlayerZpos(_playerChar);
    std::vector<std::string> map = mapClass.readExplosionImpact();
    std::vector<std::string> realmap = mapClass.readMap();

    //std::cout << "_next_pos_ia_x = " << _next_pos_ia_x << std::endl;
    //std::cout << "_next_pos_ia_z = " << _next_pos_ia_z << std::endl;

    //std::cout << "posXp = " << posXp << std::endl;
    //std::cout << "posZp = " << posZp << std::endl;

    if (_next_pos_ia_z < posZp && realmap[posZp - 1][posXp] == ' ') {
        _rotation = -90;
        _position.z -= 7.5;
    }
    else if (_next_pos_ia_x > posXp && realmap[posZp][posXp + 1] == ' ') {
        _rotation = 180;
        _position.x += 7.5;
    }
    else if (_next_pos_ia_z > posZp && realmap[posZp + 1][posXp] == ' ') {
        _rotation = 90;
        _position.z += 7.5;
    }
    else if (_next_pos_ia_x < posXp && realmap[posZp][posXp - 1] == ' ') {
        _rotation = 0;
        _position.x -= 7.5;
    }
    else {
        calculated_next_safe_pos = false;
        if (realmap[posZp - 1][posXp] == 'b') {
            _rotation = -90;
            _position.z -= 7.5;
        }
        else if (realmap[posZp][posXp + 1] == 'b') {
            _rotation = 180;
            _position.x += 7.5;
        }
        else if (realmap[posZp + 1][posXp] == 'b') {
            _rotation = 90;
            _position.z += 7.5;
        }
        else if (realmap[posZp][posXp - 1] == 'b') {
            _rotation = 0;
            _position.x -= 7.5;
        }
        //std::cout << "ye suis bloqué" << std::endl;
    }
    movePlayerInMap(mapClass);
}

void Player::manageIA(MapGeneration mapClass)
{

    if (bombe.getActive() == false && IsNearBomb(mapClass) == false)
        moveIa(mapClass);
    else if (bombe.getActive() == false && IsNearBomb(mapClass) == true)
        IAdropBomb(); // si les coo de la bombe sont atteintes pose la bombe
    else if (bombe.getActive() == true && checkIsSafe(mapClass) == false && calculated_next_safe_pos == false)
        findSafePlace(mapClass); //calcul les prochaines coo safe
    else if (bombe.getActive() == true && checkIsSafe(mapClass) == false && calculated_next_safe_pos == true)
        goToSafePlace(mapClass);// vas jusqu'a _next_pos_ia si les coo sont calculée dans _next_pos_ia_xz
    else if (bombe.getActive() == true && checkIsSafe(mapClass) == true)
        //std::cout << "reste caché" << std::endl;

    if (bombe.getActive() == true) {
        if (bombe.checkChrono() == true) {
            bombe.setActive(false);
            this->setIsBombe(true);
            this->setBombeposition(bombe.getPosition());
            calculated_next_safe_pos = false;
        }
        bombe.drawTexture();
    }
    this->updatePlayerAnimation();
}

void Player::movePlayerUp(MapGeneration mapClass)
{
    char nextChar = checkNextChar(_playerChar, 0, -1, mapClass);
    _rotation = -90;
    if (_position.z - 2.5 <= _previous_z && (nextChar == '#' || nextChar == 'X' || nextChar == '4' || nextChar == '5' || nextChar == '6'))
        return;
    _position.z -= this->getSpeed();
}

void Player::movePlayerDown(MapGeneration mapClass)
{
    char nextChar = checkNextChar(_playerChar, 0, 1, mapClass);
    _rotation = 90;
    if (_position.z + 2.5 >= _next_z && (nextChar == '#' || nextChar == 'X' || nextChar == '4' || nextChar == '5' || nextChar == '6'))
        return;
    _position.z += this->getSpeed();
}

void Player::movePlayerLeft(MapGeneration mapClass)
{
    char nextChar = checkNextChar(_playerChar, -1, 0, mapClass);
    _rotation = 0;
    if (_position.x - 2.5 <= _previous_x && (nextChar == '#' || nextChar == 'X' || nextChar == '4' || nextChar == '5' || nextChar == '6'))
        return;
    _position.x -= this->getSpeed();
}

void Player::movePlayerRight(MapGeneration mapClass)
{
    char nextChar = checkNextChar(_playerChar, 1, 0, mapClass);
    _rotation = 180;
    if (_position.x + 2.5 >= _next_x && (nextChar == '#' || nextChar == 'X' || nextChar == '4' || nextChar == '5' || nextChar == '6'))
        return;
    _position.x += this->getSpeed();
}

void Player::set_time_alive()
{
    std::chrono::time_point<std::chrono::system_clock> end_life = std::chrono::system_clock::now();

    _time_alive = end_life - _lifespan_start;
}

std::chrono::duration<double> Player::get_time_alive() const
{
    return _time_alive;
}

bool Player::get_is_alive() const
{
    return _is_alive;
}