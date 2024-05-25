/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** bombe
*/

#include "Bombe.hpp"

Bombe::Bombe()
{
}

Bombe::~Bombe()
{
}

void Bombe::Activate()
{
    _modelbombe = _models.loadModel("../source/assets/Bomb.obj");
    _texturebombe = _textures.loadTexture("../source/assets/Albedo.png");
    _models.setMaterialTexture(_modelbombe.materials[0], MATERIAL_MAP_DIFFUSE, _texturebombe);
}

void Bombe::Unload()
{
    _textures.unloadTexture(_texturebombe);
    _models.unloadModel(_modelbombe);
}

void Bombe::drawTexture()
{
    _models.drawModelEx(_modelbombe, _position, {1.0f, 0.0f, 0.0f}, 0.0f, {20.0f, 4.0f, 20.0f}, RED);
}

bool Bombe::checkChrono()
{
    std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - this->getStart();

    if (elapsed.count() > BOMBE_EXPLODE)
        return true;
    return false;
}
