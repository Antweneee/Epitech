/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "my.h"
#include <stdio.h>
#include <math.h>

int error_handling(int ac, char **av)
{
    int j = 0;

    if (ac != 9) {
        return (1);
    } else {
        if (atof(av[8]) < 0 || atof(av[8]) == 0 )
            return (1);
    }
    for (int i = 1; i != 9; j++) {
        if (av[i][j] == '\0') {
            j = -1;
            i += 1;
            continue;
        }
        if (av[i][j] == '-') {
            continue;
        }
        if (av[i][j] < '0' || av[i][j] > '9') {
            printf("error at i = %d\n", i);
            printf("j = %d\n", j);
            return (1);
        }
        if (atof(av[1]) < 1 || atof(av[1]) > 3)
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 1)
        return (84);
    int opt = atof(av[1]);
    int xp = atof(av[2]);
    int yp = atof(av[3]);
    int zp = atof(av[4]);
    int xv = atof(av[5]);
    int yv = atof(av[6]);
    int zv = atof(av[7]);
    int p = atof(av[8]);

// detect cases

    if (opt == 1)
        printf("Sphere of radius %d\n", p);
    if (opt == 2)
        printf("Cylinder of radius %d\n", p);
    if (opt == 3)
        printf("Cone with a %d degree angle\n", p);
    
//end

//Sentences

    printf("Line passing through the point (%d, %d, %d) and parallel to the vector (%d, %d, %d)\n", xp, yp, zp, xv, yv, zv);

//end

//solve

    float a = 0;
    float b = 0;
    float c = 0;
    float delta = 0;

    if (opt == 1) { //sphere
        a = pow(xv, 2) + pow(yv, 2) + pow(zv, 2);
        b = (2 * xp * xv) + (2 * yp * yv) + (2 * zp * zv);
        c = pow(xp, 2) + pow(yp, 2) + pow(zp, 2) - pow(p, 2);
        delta = pow(b, 2) - 4 * a * c;
    }
    if (opt == 2) { //cylinder
        a = pow(xv, 2) + pow(yv, 2);
        b = (2 * xp * xv) + (2 * yp *yv);
        c = pow(xp, 2) + pow(yp, 2) - pow(p, 2);
        delta = pow(b, 2) - 4 * a * c;
    }
    if (opt == 3) { //cone
        p = (p * M_PI) / 180;        
        a = pow(xv, 2) + pow(yv, 2) - (pow(zv, 2) / pow(tan(p), 2));
        b = (2 * xp * xv) + (2* yv * yp) - ((2 * zv *zp) / pow(tan(p), 2));
        c = pow(xp, 2) + pow(yp, 2) - (pow(zp, 2) / pow(tan(p), 2));
        delta = pow(b, 2) - 4 * a * c;
    }
    if (delta < 0)
        printf("No intersection point\n");
    if (delta == 0) {
        printf("1 intersection point\n");
    }
    if (delta > 0) {
        printf("2 intersection points\n");
    }

//end
    
    return (0);
}

/*     printf("~~~~~~~~~~~~~~~~~~\n"); */
/* // */

/*     int a = xp + xv; */
/*     int b = yp + yv; */
/*     int c = zp + zv; */

/* //calcul delta */

/*     int delta=0; */
/*     int result=0; */
    
/*     delta = ((pow(b, 2)) - (4*(a*c))); */
/*     printf("delta = %d\n", delta); */
    
/* //end */

/*     printf("~~~~~~~~~~~~~~~~~~\n"); */
    
/* //number of solution */
    
    /* if (delta < 0) */
    /*     printf("No solution\n"); */
    /* if (delta == 0) { */
    /*     printf("one solution\n"); */
    /*     result = (-(-b/(2*a))); */
    /*     printf("x0 = %.3f\n", result); */
    /* } */
    /* if (delta > 0) { */
    /*     printf("two solution\n"); */
    /*     result = ((-b - sqrt(delta))/2*a); */
    /*     printf("x1 = %.3f\n", result); */
    /*     result = ((-b + sqrt(delta))/2*a); */
    /*     printf("x2 = %.3f\n", result); */
    /* } */
    
/* //end */

/* //end */
