/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "my_ls.h"
#include "my.h"

int main(int ac, char **av)
{
    struct stat sinfo;

    if (ac == 1) {
        basic_ls(opendir("./"), sinfo);
        return (0);
    }
    gestion(ac, av, sinfo);
    return (0);
}
