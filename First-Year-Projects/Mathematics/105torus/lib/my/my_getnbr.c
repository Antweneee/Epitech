/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** getnbr
*/

int my_getnbr(char const *str)
{
    {
        long r = 0;
        int c = 0;
        int s = 1;

        while (str[c] == '+' || str[c] == '-') {
            if (str[c] == '-') {
                s = s * -1;
            }
            c = c + 1;
        }
        while (str[c] >= '0' && str[c] <= '9') {
            r = (r * 10) + str[c] - 48;
            c = c + 1;
        }
        if (r > 2147483647 || r < -2147483648) {
            return (0);
        }
        return (r * s);
    }
}
