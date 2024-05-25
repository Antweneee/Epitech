/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

    #include <string>
    #include <iostream>
    #include <stdlib.h>
    #include <raylib.h>
    #include <map>
    #include <functional>
    #include <tuple>
    #include "PlayerSettings.hpp"
    #include "Models.hpp"
    #include "Core.hpp"
    #include "Textures.hpp"
    #include "map.hpp"
    #include "Bombe.hpp"
    #include "Best_Scores.hpp"

class MapGeneration;
class Player
{
    private:
        typedef enum {
        SPEED,
        BOMBE_UP,
        SHIELD
        } bonus_e;

    public:
        Player(const std::string& modelPath, const std::string& TexturePath, PlayerSettings &settings);
        Player(const Player& other) = default;
        Player(){};
        ~Player();
        void interpret_key(MapGeneration &mapClass);
  
        void manageIA(MapGeneration mapClass);
        void IAdropBomb();
        void findSafePlace(MapGeneration mapClass);
        void moveIa(MapGeneration mapClass);
        bool IsNearBomb(MapGeneration mapClass);
        bool checkIsSafe(MapGeneration mapClass);
        void goToSafePlace(MapGeneration mapClass);
        bool checkIsVeryFar(MapGeneration mapClass, int posXp, int posZp);
 
        void interpret_controller_key(MapGeneration &mapClass);
        void manageCorePlayer(Core core);
        void managePlayer(Core core, MapGeneration &map);
        void unloadPlayerScope();
        void updatePlayerAnimation();
        void movePlayerUp(MapGeneration mapClass);
        void movePlayerDown(MapGeneration mapClass);
        void movePlayerLeft(MapGeneration mapClass);
        void movePlayerRight(MapGeneration mapClass);
        void initPlayer(MapGeneration &mapClass, PlayerSettings &settings);
        void movePlayerInMap(MapGeneration &map);
        void executePlayerBonus();
        KeyboardKey get_bomb_key() {return _bomb_key;};
        bool isPlayerBonus();
        void managePlayerBonus();
        float _next_x;
        float _previous_x;
        float _next_z;
        float _previous_z;
        char _lastChar;
        PlayerSettings _settings;
        //std::unique_ptr<ModelAnimation>&& getAnimations() const { return std::move(_animations); }

        Vector3 getBombeposition() const { return this->_bombe_position; }
        void setBombeposition(Vector3 bombe_position) { this->_bombe_position = bombe_position; }
        bool getIsBombe() const { return this->_isBombe; }
        void setIsBombe(bool isBombe) { this->_isBombe = isBombe; }
        bool getIsAlive() const { return this->_is_alive; }
        void setIsAlive(bool isAlive) { this->_is_alive = isAlive; }
        bool getIsAi() const {return this->_is_ai;}
        void setIsAi(bool isAi) {this->_is_ai = isAi;}

        unsigned int getAnimsCount() const {return this->_animsCount;}
        int getRotation() const {return this->_rotation;}
        int getFrame() const {return this->_frameCounter;}
        char getPlayerchar() const {return this->_playerChar;}
        KeyboardKey getKeyboardKey() const {return this->_bomb_key;}
        Vector3 getPosition() const {return this->_position;}
        Model getModel() const {return this->_model;}
        Texture2D getTexture() const {return this->_texture;}
        Models getModels() const {return this->_models;}
        Textures getTextures() const {return this->_textures;}
        std::shared_ptr<ModelAnimation> getAnimations() const {return this->_animations;}
        Bombe getBombe() const {return this->bombe;}

        float getSpeed() const { return this->_speed; }
        void setSpeed(float speed) { this->_speed = speed; }
        bool getIsSpeed() const { return this->_isSpeed; }
        void setIsSpeed(bool isSpeed) { this->_isSpeed = isSpeed; }
        std::chrono::steady_clock::time_point getSpeedChrono() const { return this->_speedChrono; }

        int getBombeUp() const { return this->_bombeUp; }
        void setBombeUp(int bombeUp) { this->_bombeUp = bombeUp; }
        bool getIsBombeUp() const { return this->_isBombeUp; }
        void setIsBombeUp(bool isBombeUp) { this->_isBombeUp = isBombeUp; }
        std::chrono::steady_clock::time_point getBombeUpChrono() const { return this->_bombeUpChrono; }

        bool getIsShield() const { return this->_isShield; }
        void setIsShield(bool isShield) { this->_isShield = isShield; }
        std::chrono::steady_clock::time_point getShieldChrono() const { return this->_shieldChrono; }

        void set_time_alive();
        std::chrono::duration<double> get_time_alive() const;
        bool get_is_alive() const;

        void startBonusChrono(std::chrono::steady_clock::time_point startChrono, bonus_e bonus) {
            if (bonus == SPEED)
                this->_speedChrono = startChrono;
            if (bonus == BOMBE_UP)
                this->_bombeUpChrono = startChrono;
            if (bonus == SHIELD)
                this->_shieldChrono = startChrono;
        }

        Player &operator=(Player const &player)
        {
            if (this == &player)
                return *this;
            _model = player._model;
            _texture = player._texture;
            _is_ai = player._is_ai;
            _is_alive = player._is_alive;
            _position = player._position;
            _rotation = player._rotation;
            _frameCounter = player._frameCounter;
            _animsCount = player._animsCount;
            _animations = player._animations;
            return *this;
        }
        int _next_pos_ia_x = 0;
        int _next_pos_ia_z = 0;
        bool calculated_next_safe_pos = false;
    private:
        unsigned int _animsCount;
        int _rotation;
        int _frameCounter;
        bool _is_alive;
        char _playerChar;
        bool _is_ai;

        KeyboardKey _bomb_key;
        GamepadButton _c_bomb_key;
        Vector3 _position;
        int const SPEED_DOWN = 10;
        int const BOMBE_UP_DOWN = 10;
        int const SHIELD_DOWN = 10;
        Model _model;
        Models _models;
        Texture2D _texture;
        Textures _textures;
        std::shared_ptr<ModelAnimation> _animations;
        std::map<KeyboardKey, std::function<void()>> keyMethodPtr;
        std::map<GamepadButton, std::function<void()>> ControllerMethodPtr;
        Bombe bombe;
        Vector3 _bombe_position;
        bool _isBombe;
        float _speed;
        bool _isSpeed;
        std::chrono::steady_clock::time_point _speedChrono;
        int _bombeUp;
        bool _isBombeUp;
        std::chrono::steady_clock::time_point _bombeUpChrono;
        bool _isShield;
        std::chrono::steady_clock::time_point _shieldChrono;
        std::chrono::time_point<std::chrono::system_clock> _lifespan_start;
        std::chrono::duration<double> _time_alive;
        std::map<std::string, GamepadButton> const _controller_interpreter {
            {"LEFT_UP", GAMEPAD_BUTTON_LEFT_FACE_UP},
            {"LEFT_DOWN", GAMEPAD_BUTTON_LEFT_FACE_DOWN},
            {"LEFT_LEFT", GAMEPAD_BUTTON_LEFT_FACE_LEFT},
            {"LEFT_RIGHT", GAMEPAD_BUTTON_LEFT_FACE_RIGHT},
            {"RIGHT_DOWN", GAMEPAD_BUTTON_RIGHT_FACE_DOWN},
        };
        std::map<std::string, KeyboardKey> const _key_interpreter {
            {"Z", KEY_W},
            {"S", KEY_S},
            {"Q", KEY_A},
            {"D", KEY_D},
            {"SPACE", KEY_SPACE},
            {"I", KEY_I},
            {"K", KEY_K},
            {"J", KEY_J},
            {"L", KEY_L},
            {"U", KEY_U},
            {"UP_ARROW", KEY_UP},
            {"DOWN_ARROW", KEY_DOWN},
            {"LEFT_ARROW", KEY_LEFT},
            {"RIGHT_ARROW", KEY_RIGHT},
            {":", KEY_SEMICOLON},
        };
};

typedef struct {
    unsigned int _animsCount;
    int _rotation;
    int _frameCounter;
    bool _is_ai;
    bool _is_alive;
    char _playerChar;
    KeyboardKey _bomb_key;
    Vector3 _position;
    Model _model;
    Textures _textures;
    // ModelAnimation _animations;
    Models _models;
    Texture2D _texture;
    Bombe bombe;
    Vector3 _bombe_position;
    bool _isBombe;
    float _speed;
    bool _isSpeed;
    std::chrono::steady_clock::time_point _speedChrono;
    int _bombeUp;
    bool _isBombeUp;
    std::chrono::steady_clock::time_point _bombeUpChrono;
    bool _isShield;
    std::chrono::steady_clock::time_point _shieldChrono;
} playerData;

#endif /* !PLAYER_HPP_ */
