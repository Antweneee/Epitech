/*
** EPITECH PROJECT, 2022
** zappy_server
** File description:
** error_handling
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"
#include "constant.h"
#include "server.h"

static bool is_not_number(char const *str)
{
    for (size_t i = 0; i < strlen(str); i += 1) {
        if (isdigit(str[i]) == false)
            return true;
    }
    return false;
}

static int count_flags_seen(int ac, char const *av[], const char *flag)
{
    size_t number_time_seen = 0;

    for (int j = 0; j < ac - 1; j += 1) {
        if (strcmp(flag, av[j]) == 0)
            number_time_seen += 1;
    }
    return number_time_seen;
}

static bool flags_exists(int ac, char const *av[])
{
    const char *flags[] = {
        PORT_FLAG, WIDTH_FLAG, HEIGHT_FLAG,
        NAME_FLAG, CLIENTSNB_FLAG, FREQ_FLAG
    };
    size_t number_time_seen = 0;

    for (size_t i = 0; i < sizeof_arr(flags); i += 1) {
        number_time_seen = count_flags_seen(ac, av, flags[i]);
        if (number_time_seen != 1)
            return false;
    }
    return true;
}

static bool is_values_not_available(uint32_t width, uint32_t height,
uint32_t clients_nb, uint32_t freq)
{
    if (width < MIN_WIDTH || width > MAX_WIDTH
    || height < MIN_HEIGHT || height > MAX_HEIGHT)
        return true;
    if (clients_nb == MIN_CLIENTS_NB)
        return true;
    if (freq < MIN_FREQ || freq > MAX_FREQ)
        return true;
    return false;
}

bool error_handling(int ac, char const *av[])
{
    int i = 0;

    if (ac < NUMBER_MAX_ARGS)
        return true;
    if (flags_exists(ac, av) == false)
        return true;
    if (strcmp(av[P], PORT_FLAG) != 0 || is_not_number(av[PORT]) == true
    || strcmp(av[X], WIDTH_FLAG) != 0 || is_not_number(av[WIDTH]) == true
    || strcmp(av[Y], HEIGHT_FLAG) != 0 || is_not_number(av[HEIGHT]) == true
    || strcmp(av[N], NAME_FLAG) != 0)
        return true;
    for (i = 5; i < ac && strcmp(av[i], CLIENTSNB_FLAG); i += 1);
    if (strcmp(av[C(i)], CLIENTSNB_FLAG) != 0
    || is_not_number(av[CLIENTSNB(i)]) || strcmp(av[F(i)], FREQ_FLAG)
    || (!av[FREQ(i)] || is_not_number(av[FREQ(i)])))
        return true;
    if (is_values_not_available(atoi(av[WIDTH]), atoi(av[HEIGHT]),
    atoi(av[CLIENTSNB(i)]), atoi(av[FREQ(i)])))
        return true;
    return false;
}
