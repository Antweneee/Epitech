/*
** EPITECH PROJECT, 2022
** lkz,ef
** File description:
** ze
*/

#include "../object.h"
#include "../int.h"
#include "../float.h"
#include "../char.h"
#include "../new.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
void test01(Object *a, Object *b)
{
    char *aa = str(a);
    char *bb = str(b);
    Object *dd = division(a, b);
    char *cc = str(dd);

    printf("%s / %s = %s\n", aa, bb, cc);
    free(aa);
    free(bb);
    free(cc);
    delete(dd);
}

void test02(Object *a, Object *b)
{
    char *aa = str(a);
    char *bb = str(b);
    Object *dd = addition(a, b);
    char *cc = str(dd);

    printf("%s / %s = %s\n", aa, bb, cc);
    free(aa);
    free(bb);
    free(cc);
    delete(dd);
}

void test03(Object *a, Object *b)
{
    char *aa = str(a);
    char *bb = str(b);
    Object *dd = subtraction(a, b);
    char *cc = str(dd);

    printf("%s / %s = %s\n", aa, bb, cc);
    free(aa);
    free(bb);
    free(cc);
    delete(dd);
}
*/


int main(int argc, char **argv)
{
    char *string_para = argv[argc - 1];

    if (string_para[0] == '1')
    {
        Object *i1 = new(Char, '&');
        Object *i2 = new(Char, '7');

        char *aa = str(i1);
        char *bb = str(i2);
        Object *dd = division(i1, i2);
        char *cc = str(dd);

        printf("%s / %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(i1);
        delete(i2);
        return 0;
    }
    else if (string_para[0] == '2')
    {
        Object *f1 = new(Char, '&');
        Object *f2 = new(Char, '&');

        char *aa = str(f1);
        char *bb = str(f2);
        Object *dd = addition(f1, f2);
        char *cc = str(dd);

        printf("%s + %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(f1);
        delete(f2);
        return 0;
    }
    else if (string_para[0] == '3')
    {
        Object *c1 = new(Char, 'v');
        Object *c2 = new(Char, '&');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = subtraction(c1, c2);
        char *cc = str(dd);

        printf("%s - %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
    else if (string_para[0] == '4')
    {
        Object *c1 = new(Char, 'v');
        Object *c2 = new(Char, '&');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = subtraction(c1, c2);
        char *cc = str(dd);

        printf("%s - %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
    else if (string_para[0] == '5')
    {
        Object *c1 = new(Char, '.');
        Object *c2 = new(Char, '&');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = addition(c1, c2);
        char *cc = str(dd);

        printf("%s + %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
    else if (string_para[0] == '6')
    {
        Object *c1 = new(Char, '&');
        Object *c2 = new(Char, '7');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = division(c1, c2);
        char *cc = str(dd);

        printf("%s / %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
    else if (string_para[0] == '7')
    {
        Object *c1 = new(Char, '2');
        Object *c2 = new(Char, '6');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = addition(c1, c2);
        char *cc = str(dd);

        printf("%s + %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
    else if (string_para[0] == '8')
    {
        Object *c1 = new(Char, 's');
        Object *c2 = new(Char, '2');

        char *aa = str(c1);
        char *bb = str(c2);
        Object *dd = subtraction(c1, c2);
        char *cc = str(dd);

        printf("%s - %s = %s\n", aa, bb, cc);
        free(aa);
        free(bb);
        free(cc);
        delete(dd);
        delete(c1);
        delete(c2);
        return 0;
    }
}