/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-antoine.gavira-bottari
** File description:
** put_error
*/

#include <unistd.h>
#include "my.h"

void my_put_error(char const *str)
{
    write(2, str, my_strlen(str));
}