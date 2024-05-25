/*
** EPITECH PROJECT, 2022
** Preprocess
** File description:
** Preprocess
*/

#include "Preprocess.hpp"
#include <dirent.h>
#include <cstring>
#include <chrono>
#include <thread>
#include "Error.hpp"

Preprocessor::Loader::Loader(const std::string &file)
{
    void *libDisplay = dlopen(file.c_str(), RTLD_NOW | RTLD_LOCAL);
    if (!libDisplay) {
        std::cerr << "error dlopen" << std::endl;
        std::exit (84);
    }

    void *displayClass = dlsym(libDisplay, "get_class");
    if (dlerror() != NULL) {
        std::cerr << "error dlsym" << std::endl;
        std::exit (84);
    }

    std::unique_ptr<IDisplay>tmp_class_display(reinterpret_cast<IDisplay * (*)()>(displayClass)());
    if (!tmp_class_display) {
        std::cerr << "error fill struct dlsym" << std::endl;
        std::exit (84);
    }

    this->_class_display = std::move(tmp_class_display);

    if (!this->_class_display)
        std::cerr << "error fill struct dlsym" << std::endl;

    this->_lib_game = NULL;
    this->_lib_graphics = NULL;
    this->_class_display.get()->get_lib_name();
    this->_initial_lib = this->_class_display.get()->get_lib_name();
}

Preprocessor::Loader::~Loader()
{
    if (this->_lib_game != NULL)
        dlclose(this->_lib_game);
    if (this->_lib_graphics != NULL)
        dlclose(this->_lib_graphics);
}

// Preprocessor::engine()
// {
//     Sfml display;
//     Pacman game;
//     Arcade::KEYS KEY;
//     IInfo::GameData data;

//     while (1) {
//         KEY = display.get_key()
//         game.engine(key);
//         data = game.get_game_data();
//         display.draw(data);
//     }
// }

void Preprocessor::Loader::StartGame(Arcade::PROTO lib_graphique, Arcade::PROTO lib_game)
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./lib/");
    std::string file;

    this->_loaded_graphics = lib_graphique;
    this->_loaded_game = lib_game;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            file = (std::string)dir->d_name;
            LoadGraphics("./lib/" + file, _loaded_graphics);
            LoadGame("./lib/" + file, _loaded_game);
        }
    }
    closedir(d);
}

void *Preprocessor::Loader::LoadGame(std::string lib, Arcade::PROTO cible)
{
    Arcade::PROTO game;

    void *libGame = dlopen(lib.c_str(), RTLD_NOW | RTLD_LOCAL);
    if (!libGame)
        return NULL;

    void *gameClass = dlsym(libGame, "get_game");
    if (dlerror() != NULL)
        return NULL;

    std::unique_ptr<IGame>tmp_class_game(reinterpret_cast<IGame * (*)()>(gameClass)());

    if (!tmp_class_game) {
        std::cerr << "error fill struct dlsym" << std::endl;
        std::exit (84);
    }

    game = tmp_class_game->get_lib_name();

    if (game == cible) {
        if (this->_lib_game != NULL)
            dlclose(this->_lib_game);
        this->_lib_game = libGame;
        this->_class_game = std::move(tmp_class_game);
        return gameClass;
    }
    return NULL;
}

void *Preprocessor::Loader::LoadGraphics(std::string lib, Arcade::PROTO cible)
{
    Arcade::PROTO graph;

    void *libDisplay = dlopen(lib.c_str(), RTLD_NOW | RTLD_LOCAL);
    if (!libDisplay)
        return NULL;

    void *displayClass = dlsym(libDisplay, "get_class");
    if (dlerror() != NULL)
        return NULL;

    std::unique_ptr<IDisplay>tmp_class_graphic(reinterpret_cast<IDisplay * (*)()>(displayClass)());

    if (!tmp_class_graphic) {
        std::cerr << "error fill struct dlsym" << std::endl;
        std::exit (84);
    }

    graph = tmp_class_graphic->get_lib_name();

    if (graph == cible) {
        if (this->_lib_graphics != NULL)
            dlclose(this->_lib_graphics);
        this->_lib_graphics = libDisplay;
        this->_class_display = std::move(tmp_class_graphic);
        return displayClass;
    }
    return NULL;
}

void Preprocessor::Loader::startChange(Arcade::PROTO cible, int game)
{
    DIR *d;
    struct dirent *dir;
    d = opendir("./lib/");
    std::string file;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            file = (std::string)dir->d_name;
            if (game == 0)
                LoadGraphics("./lib/" + file, cible);
            if (game == 1)
                LoadGame("./lib/" + file, cible);
        }
    }
    closedir(d);
}

bool Preprocessor::Loader::LibChange(Arcade::KEYS KEY)
{
    int game = (int)_loaded_game;
    int graph = (int)_loaded_graphics;

    if (KEY == Arcade::KEYS::F1) {
        graph--;
    } else if (KEY == Arcade::KEYS::F2) {
        graph++;
    } else if (KEY == Arcade::KEYS::F3) {
        game--;
    } else if (KEY == Arcade::KEYS::F4) {
        game++;
    }

    if (game > 4 || game < 3)
        return false;

    if (graph > 2 || graph < 0)
        return false;

    if (graph != (int)_loaded_graphics) {
        startChange(Arcade::PROTO(graph), 0);
        _loaded_graphics = Arcade::PROTO(graph);
        _class_display->init();
        return true;
    }
    else if (game != (int)_loaded_game) {
        startChange(Arcade::PROTO(game), 1);
        _loaded_game = Arcade::PROTO(game);
        return true;
    }
    return false;
}

void Preprocessor::Loader::engine()
{
    Arcade::KEYS KEY;
    IInfo::GameData data;
    bool is_running = true;

    _class_display->init();

    while (is_running) {
        KEY = _class_display->get_key();
        if (KEY == Arcade::KEYS::ESC)
            break;
        if (LibChange(KEY)) {
            data._score = 0;
            continue;
        }
        _class_game->engine(KEY);
        data = _class_game->get_game_data();
        _score = data._score;
        if (data._win == true || data._loose == true)
            is_running = false;
        _class_display->draw(data);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    save_score(data);
}

void Preprocessor::Loader::save_score(IInfo::GameData data)
{
    if (_loaded_game == Arcade::PROTO::PACMAN) {
        std::fstream file("config/pacman_hs.txt", std::ios::out | std::ios::app);
        _name.erase(_name.begin());
        file << _name + " " + std::to_string(_score) << std::endl;
        file.close();
    } else {
        std::fstream file("config/nibbler_hs.txt", std::ios::out | std::ios::app);
        _name.erase(_name.begin());
        file << _name + " " + std::to_string(_score) << std::endl;
        file.close();
    }
}