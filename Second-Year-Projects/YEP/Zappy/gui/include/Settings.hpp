/*
** EPITECH PROJECT, 2022
** B-YEP-410-PAR-4-1-zappy-thomas.willson
** File description:
** Settings
*/

#ifndef SETTINGS_HPP_
    #define SETTINGS_HPP_

    #include <vector>
    #include <utility>
    #include <SFML/Config.hpp>
    #include <SFML/Window/Keyboard.hpp>
    #include <SFML/Graphics.hpp>
    #include <SFML/Window/Window.hpp>
    #include <SFML/Audio.hpp>
    #include <memory>

    #include "scenes.hpp"
    #include "enums.hpp"

class Settings {
    public:
        Settings(std::string machine) : _machine(machine)
        {
            _scene = Scenes::MENU;
            _volume = 20;
            _mousePosition = std::make_pair(0, 0);
            _event = EVENTS::DEFAULTEVENT;
            _musics.push_back(std::make_shared<sf::Music>());
            _musics.at(0)->openFromFile("gui/assets/one_piece_music.ogg");
        }
        ~Settings() {}

        float getVolume() const { return _volume; }
        void setVolume(float volume) { _volume = volume; }

        // std::vector<std::shared_ptr<sf::Sound>> getSoundList() const;

        std::vector<std::shared_ptr<sf::Music>> getMusicList() const { return _musics; }

        // void playSound(int id) { _sounds.at(id)->play(); }
        void playMusic(int id) { _musics.at(id)->play(); }

        void setMousePosition(const std::pair<int, int> &mousePosition) { _mousePosition = mousePosition; }
        std::pair<int, int> getMousePosition() const { return _mousePosition; }

        EVENTS getEvent() const { return _event; }
        void setEvent(EVENTS event) { _event = event; }

        Scenes getScene() const { return _scene; }
        void setScene(Scenes scene) { _scene = scene; }

        std::string getMachine() const { return _machine; }
        void setScene(std::string machine) { _machine = machine; }

    protected:
    private:
        float _volume;
        // std::vector<std::shared_ptr<sf::Sound>> _sounds;
        std::vector<std::shared_ptr<sf::Music>> _musics;
        std::pair<int, int> _mousePosition;
        std::string _machine;
        EVENTS _event;
        Scenes _scene;
};

#endif /* !SETTINGS_HPP_ */