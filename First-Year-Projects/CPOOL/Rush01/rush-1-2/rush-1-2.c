/*
** EPITECH PROJECT, 2020
** rush
** File description:
** display a square
*/

int first_line(int x, int y)
{
    for (int x2 = x - 1; x2 >= 1; x2--) {
        my_putchar('/');
        if (x >= 3) {
            for (; x2 != 1; x2--) {
                my_putchar('*');
            }
        }
        my_putchar(92);
        my_putchar('\n');
    }
}

int last_line(int x, int y)
{
    for (int x2 = x - 1; x2 >= 1; x2--) {
        my_putchar(92);
        if (x >= 3) {
            for (; x2 != 1; x2--) {
                my_putchar('*');
            }
        }
        my_putchar('/');
        my_putchar('\n');
    }
}

int other_line(int x, int y)
{

    for(int y2 = y - 1; y2 != 1; y2--) {
        for (int x3 = x - 1; x3 >= 1; x3--) {
            my_putchar('*');
            for (x3= x - 1; x3 != 1; x3--) {
                my_putchar(' ');
            }
            my_putchar('*');
            my_putchar('\n');
        }
    }
}

int line(int x, int y)
{
    if (y == 1) {
        for (int x2 = x - 1; x2 >= 1; x2--) {
            my_putchar('*');
            if (x >= 3) {
                for (; x2 != 1; x2--) {
                    my_putchar('*');
                }
                my_putchar('*');
                my_putchar('\n');
            }
        }
    } else {
        first_line(x, y);
        other_line(x, y);
        last_line(x, y);
    }
}

int column(int x, int y)
{
    if (x == 1) {
        my_putchar('*');
        my_putchar('\n');
        for(int y3 = y - 1; y3 != 1; y3--) {
            my_putchar('*');
            my_putchar('\n');
        }
        my_putchar('*');
    }
    my_putchar('\n');
    return (0);
}

void rush(int x, int y)
{
    if (x == 1 && y == 1) {
        my_putchar('*');
        my_putchar('\n');
        return;
    }
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    if (x == 1) {
        column(x, y);
        return;
    }
    line(x, y);
}
