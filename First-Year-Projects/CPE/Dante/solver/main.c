/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "solver.h"

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
    if (buffer[0] == '\0')
        return (NULL);
    return (buffer);
}

int main(int ac, char **av)
{
    if (read_file(av) == NULL || ac != 2)
        return 84;
    my_printf("solver\n");
    return (0);
}
