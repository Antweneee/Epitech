/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "../include/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void basic_draw(sfRenderWindow *Window, struct texture text)
{
    sfRenderWindow_drawSprite(Window, text.image1, NULL);
    sfRenderWindow_drawSprite(Window, text.button_sprite, NULL);
    sfRenderWindow_drawSprite(Window, text.start_sprite, NULL);
    sfRenderWindow_display(Window);
}

void cleanup(sfRenderWindow *Window, struct texture text)
{
    sfSprite_destroy(text.start_sprite);
    sfSprite_destroy(text.button_sprite);
    sfSprite_destroy(text.image1);
    sfRenderWindow_destroy(Window);
}

char *readmap(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = NULL;
    int size = 0;
    struct stat info;

    stat(av[1], &info);
    size = info.st_size;
    if (size == -1 || fd == -1 || size == 0)
        return (NULL);
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}

int parameter(int ac, char **av, struct movement *move)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Little video game\nPress the space bar to jump!\nPress esc for quit the game!\n");
        return (0);
    }
    if (ac != 2)
        return (1);
    else
        move->map = readmap(av);
    if (move->map == NULL)
        return (1);
    move->indi = get_obstacle(move);
    return (0);
}

int main(int ac, char **av)
{
    sfRenderWindow *Window;
    sfVector2i mousepos;
    struct movement move = setvar();
    struct texture text = fill_text();
    text = fill_pre();
    text = structure();
    set(text);
    second_set(text, move);

    if (parameter(ac, av, &move) == 1)
        return (84);
    Window = sfRenderWindow_create(text.video_mode, "~my_runner~", sfDefaultStyle, NULL);
    while (sfRenderWindow_isOpen(Window)) {
        boucle(Window, mousepos, text, move);
        basic_draw(Window, text);
    }
    cleanup(Window, text);
    return (0);
}
