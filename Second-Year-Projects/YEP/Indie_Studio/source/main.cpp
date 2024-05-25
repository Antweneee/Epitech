/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** main
*/

#include <raylib.h>
#include "game.hpp"
#include "Player.hpp"
#include <string>
#include <iostream>


int main(void)
{
    Game game;
    game.init();
    game.engine();
    /*Core core;
    core.initWindow(1280, 720, "Indie");
    Camera camera = {{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0};
    core.setCameraMode(camera, CAMERA_FREE);
    Player player("../source/assets/player.iqm", "../source/assets/blue.png", true, false, (Vector3) {.x = 0.0f, 0.0f, 0.0f});
    player.managePlayer(core, camera);

    core.closeWindow();*/
    return 0;
}
