/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"
#include "use.h"

int main(int ac, char const **av, char const **env)
{
    enti_t enti;
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    if (env == NULL || env[0] == NULL) {
        return (84);
    }
    if (ac == 2 && av[1][0] == '-' &&
    av[1][1] == 'h' && av[1][2] == '\0')
    {
        my_putstr("Little video game\nBuild your own defend to win!\n");
        my_putstr("Press esc to pause the game, return to menu or quit!\n");
        return (0);
    }
    window = sfRenderWindow_create(video_mode, "my_defender", sfDefaultStyle
    , NULL);
    enti = initialize(enti);
    draw_menu(&enti, window);
    loop(&enti, window);
    return (0);
}