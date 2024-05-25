/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** music
*/

#include "my.h"

void play_music(enti_t *enti)
{
    if (enti->song.mute % 2 == 0)
        sfMusic_pause(enti->song.music);
    else
        sfMusic_play(enti->song.music);
}