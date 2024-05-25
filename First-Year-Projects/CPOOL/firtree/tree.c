/*
** EPITECH PROJECT, 2020
** fir tree
** File description:
** display a tree
*/

void tree(int size)
{
    if (size <= 0) {
        return;
    }
    write(1,"   *\n",5);
    write(1,"  ***\n",6);
    write(1," *****\n",7);
    write(1,"*******\n",8);
    write(1,"   |\n",5);
}
