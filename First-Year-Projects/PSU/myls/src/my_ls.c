/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls function
*/

#include "my.h"
#include "my_ls.h"

void basic_ls(DIR *dir, struct stat sinfo)
{
    struct dirent *info;

    while ((info = readdir(dir)) != 0) {
        if (info->d_name[0] == '.')
            continue;
        stat(info->d_name, &sinfo);
        my_printf("%s  ", info->d_name);
    }
    my_printf("\n");
}

char *get_path(int ac, char **av)
{
    char *path = malloc(sizeof(char) * 1000);

    if (ac == 1 || (ac == 2 && av[1][0] == '-'))
        path = my_strdup("./");
    if (ac == 2 && av[1][0] != '-')
        path = my_strcat(av[1], "/");
    if (ac == 3 && av[1][0] == '-')
        path = my_strcat(av[2], "/");
    if (!opendir(path))
        exit(84);
    return (path);
}

void gestion(int ac, char **av, struct stat sinfo)
{
    char *path = get_path(ac, av);

    if (ac == 2 && av[1][0] != '-') {
        basic_ls(opendir(path), sinfo);
    }
    if (av[1][0] == '-' && av[1][1] == 'l') {
        ls_l(path, sinfo, ac , av);
    }
    if (av[1][0] == '-' && av[1][1] == 'a') {
        ls_a(opendir(path), sinfo);
    }
}
