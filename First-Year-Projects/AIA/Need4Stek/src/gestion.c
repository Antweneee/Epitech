/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** gestion
*/

#include "n4s.h"
#include "const.h"

int rotation_degree(double angle, const char *rotation)
{
    char *line = NULL;

    dprintf(1, "%s", WHEEL);
    if (angle < 0)
        dprintf(1, "-");
    dprintf(1, "%s", rotation);
    if ((line = readline()) == NULL)
        return (3);
    if (end(line) == 1)
        return (1);
    return (3);
}

int manage_rotation(char **data, double direction)
{
    double angle = atof(data[1]) - atof(data[31]);
    int success = 3;

    if (direction >= 1500)
        success = rotation_degree(angle, "0.005\n");
    else if (direction >= 800)
        success = rotation_degree(angle, "0.05\n");
    else if (direction >= 600)
        success = rotation_degree(angle, "0.1\n");
    else if (direction >= 400)
        success = rotation_degree(angle, "0.2\n");
    else if (direction >= 200)
        success = rotation_degree(angle, "0.3\n");
    else
        success = rotation_degree(angle, "0.5\n");
    return (success);
}

int get_direction(void)
{
    char *line = NULL;
    char **info = NULL;
    double direction;

    dprintf(1, "%s", LIDAR);
    line = readline();
    if (line == NULL)
        return (2);
    end(line);
    line = get_car_status(line);
    info = my_str_to_word_array(line, ':');
    if (info == NULL)
        return (2);
    direction = atof(info[15]);
    if (manage_rotation(info, direction) == 1)
        return (1);
    return (3);
}

int speed_manage(double distance)
{
    double value;
    int speed;

    if (distance >= 2000)
        value = 0.8;
    else if (distance >= 1500)
        value = 0.6;
    else if (distance >= 0)
        value = 0.2;
    speed = car_forward(value);
    return (speed);
}

int get_speed(void)
{
    char *line = NULL;
    char **data = NULL;
    double speed;

    dprintf(1, "%s", LIDAR);
    line = readline();
    if (line == NULL)
        return (2);
    end(line);
    line = get_car_status(line);
    data = my_str_to_word_array(line, ':');
    speed = atof(data[15]);
    if (speed_manage(speed) == 1)
        return (1);
    return (3);
}