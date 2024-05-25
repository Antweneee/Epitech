/*
** EPITECH PROJECT, 2021
** main
** File description:
** main function
*/

#include "my.h"
#include "use.h"

int helper(void)
{
    my_putstr("Little video game\nBuild your own defend to win!\n");
    my_putstr("Press esc to pause the game, return to menu or quit!\n");
    return 0;
}

int main(int ac, char const **av, char const **env)
{
    enti_t enti = initialize(enti);
    sfVideoMode video_mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(video_mode,
    "my_defender", sfDefaultStyle, NULL);

    if (!env || !env[0])
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return (helper());
    game_loop(&enti, window);
    destroy_music(&enti);
    return (0);
}