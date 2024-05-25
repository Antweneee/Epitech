/*
** EPITECH PROJECT, 2021
** sound
** File description:
** sound
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"

struct sound create(void)
{
    struct sound music;

    music.game_mus = sfMusic_createFromFile(
    "assets/courage-the-legend-of-zelda-twilight-princess.ogg");
    sfMusic_play(music.game_mus);
    sfMusic_setLoop(music.game_mus, sfTrue);
    return (music);
}
