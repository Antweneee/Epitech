/*
** EPITECH PROJECT, 2020
** eval_expr
** File description:
** eval_expr
*/

int first(char *str)
{
    int a = 0;

    if (str[0] == '-') {
        a++;
    }
    return (a);
}

int numb(char *str, int a)
{
    int b;

    for (b = 0; str[a] <= '9' && str[a] >= '0'; a++) {
        b = (b * 10) + (str[a] - '0');
        if (str[a + 1] > '9' && str[a + 1] < '0')
            return (b);
        else
            return (b);
    }
}


int signs(int b, int c, int cal, char *str)
{
    int resu = 0;

    if (str[cal] == '*')
        resu = b * c;
    if (str[cal] == '/')
        resu = b / c;
    if (str[cal] == '%')
        resu = b % c;
    if (str[cal] == '+')
        resu = b + c;
    if (str[cal] == '-')
        resu = b - c;
    return (resu);
}

int eval_expr(char *str)
{
    int a = first(str);
    int b = numb(str, a);
    int c = 0;
    int cal;

    for (; str[a] <= '9' && str[a] >= '0';) {
        if (str[a] <= '9' && str[a] >= '0')
            a++;
    }
    cal = a;
    if (str[a + 1] <= '9' && str[a + 1] >= '0');
    c = numb(str, (a + 1));
    a++;
    return (signs(b, c, cal, str));
}
