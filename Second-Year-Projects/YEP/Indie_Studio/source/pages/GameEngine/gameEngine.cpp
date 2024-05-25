/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** gameEngine
*/

#include <sstream>
#include "GameEngine.hpp"
#include "VictoryScreen.hpp"
#include "map.hpp"
#include "SaveGame.hpp"

GameEngine::GameEngine()
{
    this->_mapClass.firstGene();
    this->_camera = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, 0.0f, 0};
    this->_camera.position = { 80.0f, 100.0f, 80.0f };
    this->_camera.target = { 80.0f, 0.0f, 70.0f };
    this->_camera.up = { 0.0f, 100.0f, 0.0f };
    this->_camera.fovy = 72.0f;
    this->_firstpos = {0.0f, 0.0f, 0.0f};
    this->_camera.projection = CAMERA_PERSPECTIVE;
    this->_is_paused = IInfo::PaueScenes::RESUME;
}

GameEngine::~GameEngine()
{

}

void GameEngine::init(std::vector<PlayerSettings> &settings)
{
    this->_modelwall = _models.loadModel("../assets/images/cube.fbx");
    this->_modelwood = _models.loadModel("../assets/images/cube.fbx");
    this->_modelwoodbonus = _models.loadModel("../assets/images/cube.fbx");
    this->_modelsol = _models.loadModel("../assets/source/impossiblebox.fbx");
    this->_modelSpeedBonus = _models.loadModel("../assets/source/impossiblebox.fbx");
    this->_modelBombeUpBonus = _models.loadModel("../assets/source/impossiblebox.fbx");
    this->_modelShieldBonus = _models.loadModel("../assets/source/impossiblebox.fbx");
    this->_texturewall = _textures.loadTexture("../assets/images/wall.png");
    this->_texturewood = _textures.loadTexture("../assets/images/wood.png");
    this->_texturewoodbonus = _textures.loadTexture("../assets/images/woodbonus.png");
    this->_textureSpeedbonus = _textures.loadTexture("../assets/images/speedbonus.png");
    this->_textureBombeUpbonus = _textures.loadTexture("../assets/images/bombeupbonus.png");
    this->_textureShieldbonus = _textures.loadTexture("../assets/images/shieldbonus.png");
    this->_texturesol = _textures.loadTexture("../assets/images/grass.png");
    p1 = Player("../source/assets/player.iqm", "../source/assets/blue.png", settings[0]);
    p1.initPlayer(_mapClass, settings[0]);
    p2 = Player("../source/assets/player.iqm", "../source/assets/blue.png", settings[1]);
    p2.initPlayer(_mapClass, settings[1]);
    p3 = Player("../source/assets/player.iqm", "../source/assets/blue.png", settings[2]);
    p3.initPlayer(_mapClass, settings[2]);
    p4 = Player("../source/assets/player.iqm", "../source/assets/blue.png", settings[3]);
    p4.initPlayer(_mapClass, settings[3]);
    this->_pause.init();
}

void GameEngine::engine(std::vector<PlayerSettings> &settings)
{
    bool is_running = true;
    bool win_loose = false;
    VictoryScreen victor;
    victor.init();

    this->init(settings);
    _core.setCameraMode(_camera, CAMERA_FREE);
    _models.setMaterialTexture(_modelwall.materials[0], MATERIAL_MAP_DIFFUSE, _texturewall);
    _models.setMaterialTexture(_modelwood.materials[0], MATERIAL_MAP_DIFFUSE, _texturewood);
    _models.setMaterialTexture(_modelwoodbonus.materials[0], MATERIAL_MAP_DIFFUSE, _texturewoodbonus);
    _models.setMaterialTexture(_modelsol.materials[0], MATERIAL_MAP_DIFFUSE, _texturesol);
    _models.setMaterialTexture(_modelSpeedBonus.materials[0], MATERIAL_MAP_DIFFUSE, _textureSpeedbonus);
    _models.setMaterialTexture(_modelBombeUpBonus.materials[0], MATERIAL_MAP_DIFFUSE, _textureBombeUpbonus);
    _models.setMaterialTexture(_modelShieldBonus.materials[0], MATERIAL_MAP_DIFFUSE, _textureShieldbonus);
    while (is_running) {
        if (win_loose == true) {
            victor.draw(true);
            continue;
        }
        if (_core.isKeyPressed(KEY_ESCAPE)) {
            SCENES = IInfo::GameScenes::EXIT;
            is_running = false;
        }
        if (_core.isKeyPressed(KEY_P))
            this->_is_paused = IInfo::PaueScenes::IS_PAUSED;
        if (this->_is_paused == IInfo::PaueScenes::IS_PAUSED) {
            this->pause();
        } else if (_is_paused == IInfo::PaueScenes::RESUME) {
            _core.updateCamera(_camera);
            win_loose = this->draw();
        }
        else if (_is_paused == IInfo::PaueScenes::EXIT_PAUSE) {
            SCENES = IInfo::GameScenes::EXIT;
            break;
        }
    }
    _textures.unloadTexture(_texturewall);
     _textures.unloadTexture(_texturewood);
     _textures.unloadTexture(_texturesol);
     _models.unloadModel(_modelwall);
     _models.unloadModel(_modelwood);
     _models.unloadModel(_modelsol);
}

static bool isPlayerTookBonus(char c)
{
    return c == '1' || c == '2' || c == '3';
}

void GameEngine::findDeletedPlayer(const std::string &deleted_player)
{
    for (size_t i = 0; i < deleted_player.length(); ++i) {
        if (deleted_player[i] == p1._settings.get_map_char()) {
            p1.setIsAlive(false);
            p1.set_time_alive();
        }
        if (deleted_player[i] == p2._settings.get_map_char()) {
            p2.setIsAlive(false);
            p2.set_time_alive();
        }
        if (deleted_player[i] == p3._settings.get_map_char()) {
            p3.setIsAlive(false);
            p3.set_time_alive();
        }
        if (deleted_player[i] == p4._settings.get_map_char()) {
            p4.setIsAlive(false);
            p4.set_time_alive();
        }
    }
}

void GameEngine::draw(char c, float x, float z)
{
    if (c == '1')
        _models.drawModelEx(this->_modelSpeedBonus, {x, -10.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 11.0f, 11.0f, 11.0f }, WHITE);
    if (c == '2')
        _models.drawModelEx(this->_modelBombeUpBonus, {x, -10.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 11.0f, 11.0f, 11.0f }, WHITE);
    if (c == '3')
        _models.drawModelEx(this->_modelShieldBonus, {x, -10.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 11.0f, 11.0f, 11.0f }, WHITE);
}

bool GameEngine::draw()
{
    std::vector<std::string> map = this->_mapClass.readMap();
    std::string deleted_player = "";
    float x = 0;
    float z = 0;
    bool ok = false;

    //if (!p1.get_is_alive()) {
    //    double tmp = p1.get_time_alive().count();
    //    std::cout <<  << std::endl;
    //}
    _core.beginDrawing();
        this->_core.clearBackground(BEIGE);
        _core.beginMode3D(_camera);
            p1.managePlayer(_core, _mapClass);
            if (isPlayerTookBonus(p1._lastChar) == true)
                p1._lastChar = ' ';
            p2.managePlayer(_core, _mapClass);
            if (isPlayerTookBonus(p2._lastChar) == true)
                p2._lastChar = ' ';
            p3.managePlayer(_core, _mapClass);
            if (isPlayerTookBonus(p3._lastChar) == true)
                p3._lastChar = ' ';
            p4.managePlayer(_core, _mapClass);
            if (isPlayerTookBonus(p4._lastChar) == true)
                p4._lastChar = ' ';
            for (int i = 0; i != (int)map.size(); i++) {
                for (int y = 0; map[i].c_str()[y]; y++) {
                    x += 10.0;
                    if (map[i][y] == '#')
                        _models.drawModelEx(_modelwall, {x, 0.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 10.0f, 10.0f, 10.0f }, WHITE);
                    else if (map[i][y] == 'X')
                        _models.drawModelEx(_modelwood, {x, 0.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 10.0f, 10.0f, 10.0f }, WHITE);
                    else if (this->_mapClass.getInfoMap(map[i][y], this->_mapClass.getEnumBonus()) == true)
                        this->draw(map[i][y], x, z);
                    else if (this->_mapClass.getInfoMap(map[i][y], this->_mapClass.getEnumBonusModel()) == true)
                        _models.drawModelEx(_modelwoodbonus, {x, 0.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 10.0f, 10.0f, 10.0f }, WHITE);
                    else if ((map[i][y] == 'b' || p1._lastChar == 'b') && p1.getIsBombe() == true) {
                        map[i][y] = ' ';
                        this->_mapClass.deleteWoodInMap(map, i, y, deleted_player, p1);
                        p1.setIsBombe(false);
                        ok = true;
                    } else if ((map[i][y] == 'b' || p2._lastChar == 'b') && p2.getIsBombe() == true) {
                        map[i][y] = ' ';
                        this->_mapClass.deleteWoodInMap(map, i, y, deleted_player, p2);
                        p2.setIsBombe(false);
                        ok = true;
                    } else if ((map[i][y] == 'b' || p3._lastChar == 'b') && p3.getIsBombe() == true) {
                        map[i][y] = ' ';
                        this->_mapClass.deleteWoodInMap(map, i, y, deleted_player, p3);
                        p3.setIsBombe(false);
                        ok = true;
                    } else if ((map[i][y] == 'b' || p4._lastChar == 'b') && p4.getIsBombe() == true) {
                        map[i][y] = ' ';
                        this->_mapClass.deleteWoodInMap(map, i, y, deleted_player, p4);
                        p4.setIsBombe(false);
                        ok = true;
                    } else
                        _models.drawModelEx(_modelsol, {x, -10.0f, z}, { 1.0f, 0.0f, 0.0f }, -90.0f, { 11.0f, 11.0f, 11.0f }, WHITE);
                }
                z += 10.0;
                x = 0;
            }
            if (ok == true) {
                this->findDeletedPlayer(deleted_player);
                this->_mapClass.writeToFile(map);
            }
            _core.updateCamera(this->_camera);
        _core.endMode3D();
    _core.endDrawing();
    _scores = get_winner();
    if (!_scores.empty()) {
        Best_Scores score(_scores);
        score.write_in_JSON();
        return true;
    }
    return false;
}

void GameEngine::pause()
{
    this->_pause.draw(_is_paused);
}

std::map<std::string, double> GameEngine::get_winner()
{
    std::map<std::string, double> players_scores;
    int lives = 4;

    if (!p1.get_is_alive())
        lives--;
    if (!p2.get_is_alive())
        lives--;
    if (!p3.get_is_alive())
        lives--;
    if (!p4.get_is_alive())
        lives--;
    if (lives == 1) {
        if (p1.get_is_alive())
            p1.set_time_alive();
        if (p2.get_is_alive())
            p2.set_time_alive();
        if (p3.get_is_alive())
            p3.set_time_alive();
        if (p4.get_is_alive())
            p4.set_time_alive();
        players_scores.emplace(std::pair<std::string, double>(p1._settings.get_name(), p1.get_time_alive().count()));
        players_scores.emplace(std::pair<std::string, double>(p2._settings.get_name(), p2.get_time_alive().count()));
        players_scores.emplace(std::pair<std::string, double>(p3._settings.get_name(), p3.get_time_alive().count()));
        players_scores.emplace(std::pair<std::string, double>(p4._settings.get_name(), p4.get_time_alive().count()));
    }
    return players_scores;
}

