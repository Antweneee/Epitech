/*
** EPITECH PROJECT, 2020
** main
** File description:
** main fuction of bsq
*/

#include <ncurses.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "sokoban.h"

char *read_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = NULL;
    int size = 0;
    int check = 0;
    struct stat info;

    check = stat(av[1], &info);
    size = info.st_size;
    if (check == -1 || size == -1 || fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (size + 1));
    if (!buffer)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}

int check_map(char *buffer)
{
    for (int i = 0 ; buffer[i] != '\0' ; i++) {
        if (buffer[i] == '\n' || buffer[i] == 'X' || buffer[i] == 'O'
        || buffer[i] == ' ' || buffer[i] == 'P' || buffer[i] == '#') {
            continue;
        } else {
            exit(84);
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    char *get = NULL;
    char **map = NULL;

    if (ac != 2)
        return (84);
    get = read_file(av);
    if (get == NULL)
        return (84);
    if (check_map(get) == 84)
        return (84);
    map = turn_to_array(get, '\n');
    set_window(map, get);
    return (0);
}
