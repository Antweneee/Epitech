/*
** EPITECH PROJECT, 2020
** my get number
** File description:
** return a number sent to a function as a string
*/

int my_getnbr(char const *str)
{
    int i = 0;
    long result = 0;
    int s = 1;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            s = s * -1;
        }
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
            result = (result * 10) + str[i] - 48;
        }
    if (result > 2147483647 || result < -2147483648) {
        return (0);
    }
    return (result * s);
}
