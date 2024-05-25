/*
** EPITECH PROJECT, 2021
** sound
** File description:
** sound
*/

#include "my.h"

struct sound create(void)
{
    struct sound music;

    music.game_mus = sfMusic_createFromFile("assets/music.ogg");
    sfMusic_play(music.game_mus);
    sfMusic_setLoop(music.game_mus, sfTrue);
    return (music);
}

struct jump setJ_sound(void)
{
    struct jump J_sound;

    J_sound.Jump = sfMusic_createFromFile("assets/jump_sound.ogg");
    sfMusic_play(J_sound.Jump);
    sfMusic_setLoop(J_sound.Jump, sfFalse);
    return(J_sound);
}
