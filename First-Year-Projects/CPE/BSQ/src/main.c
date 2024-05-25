/*
** EPITECH PROJECT, 2020
** main
** File description:
** main fuction of bsq
*/

#include "../include/my.h"
#include "../include/bsq.h"

char *read_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char *buffer = NULL;
    int size = 0;
    struct stat info;

    stat(av[1], &info);
    size = info.st_size;
    if (size == -1 || fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    return (buffer);
}

int errors(char *buffer)
{
    int nb = my_getnbr(buffer);
    int x = 0;

    for (; buffer[0] != '\n'; buffer++);
    buffer++;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            x++;
        }
        if (buffer[i] != '.' && buffer[i] != 'o' && buffer[i] != '\n') {
            return (1);
        }
    }
    if (x != nb) {
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    char *buffer = NULL;

    if (ac != 2)
        return (84);
    buffer = read_file(av);
    if (buffer == NULL)
        return (84);
    if (errors(buffer) == 1)
        return (84);
    bsq(buffer);
    return (0);
}
