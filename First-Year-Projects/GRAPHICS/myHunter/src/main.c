/* MY_H_ */ /*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "my.h"
#include "use.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' &&
    av[1][1] == 'h' && av[1][2] == '\0')
    {
        my_putstr("Little video game\nClick to kill the lion\n");
        my_putstr("Press esc for quit the game!\n");
        return (0);
    } else
    {
        gestion();
    }
    return (0);
}