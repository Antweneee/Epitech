/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "my.h"
#include <stdio.h>
#include <math.h>

struct key_matrix
{
    int x;
    int y;
    int **matrix;
};

struct message_matrix
{
    int x;
    int y;
    int **matrix;
};

int matrix_column_size(int len)
{
    if (len <= 2)
        return (1);
    if (len <= 6)
        return (2);
    if (len <= 9)
        return (3);
    if (len <= 16)
        return (4);
    if (len <= 25)
        return (5);
    if (len <= 36)
    return (6);
    return (84);
}

int matrix_line_size(int len, int column)
{
    if (column == 1 && len == 1)
        return (1);
    if (column == 1 && len == 2)
        return (2);
    if (column == 2 && len <= 4)
        return (2);
    if (column == 2 && len <= 6)
        return (3);
    if (column == 3 && len <= 9)
        return (3);
    if (column == 4 && len <= 12)
        return (3);
    if (column == 4 && len <= 16)
        return (4);
    return (84);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] =='h') {
        printf("DESCRIPTION\n\tmessage\t\ta message, made of ASCII characters\n\tkey\t\tthe encryption key, made of ASCII characters\n\tflag\t\t0 for the message to be encrypted, 1 to be decrypted\n");
        return (0);
    }
    if (ac != 4)
        return (0);
    struct key_matrix k_matrix;
    struct message_matrix m_matrix;
    char *msg = malloc(sizeof(char) * (my_strlen(av[1]) + 1));
    char *key = malloc(sizeof(char) * (my_strlen(av[2]) + 1));
    int flag = 0;

    if (msg == NULL || key == NULL)
        return (84);
    msg = av[1];
    key = av[2];
    if (msg[0] == '\0' || key[0] == '\0')
        return (84);
    if (atof(av[3]) < 0 || atof(av[3]) > 1)
        return (84);
    else
        flag = atof(av[3]);
    k_matrix.x = matrix_column_size(my_strlen(key));
    k_matrix.y = matrix_line_size(my_strlen(key), k_matrix.x);

//Key matrix
    
    //memory allocation key matrix
    k_matrix.matrix = malloc(sizeof(int *) * (k_matrix.x));
    for (int i = 0; i != k_matrix.y; i++)
        k_matrix.matrix[i] = malloc(sizeof(int) * (k_matrix.x + 1));
    //end of memory allocation
    
    //fill && printf key matrix
    if (flag == 0)
        printf("Key matrix:\n");
    int z = 0;
    for (int x = 0; x != k_matrix.y; x++) {
        for (int o = 0; o != k_matrix.x; o++) {
            if (z >= my_strlen(key)) {
                k_matrix.matrix[x][o] = 0;
            } else {
                k_matrix.matrix[x][o] = key[z];
            }
            if (o == (k_matrix.x - 1))
                printf("%d\n", k_matrix.matrix[x][o]);
            else
                printf("%d\t", k_matrix.matrix[x][o]);
            z++;
        }
        //printf("\n");
    }    
    //end
    
//end

//Message matrix

    //memory allocation msg matrix
    m_matrix.x = k_matrix.x;
    m_matrix.y = (my_strlen(msg) / m_matrix.x);
    m_matrix.matrix = malloc(sizeof(int *) * (m_matrix.y));
    for (int i = 0; i != (m_matrix.y + 1); i++)
        m_matrix.matrix[i] = malloc(sizeof(int) * (m_matrix.x + 1));
    //end of memory allocation


    //fill && printf msg matrix
    if (flag == 0) {
        z = 0;
        for (int x = 0; x != (m_matrix.y + 1); x++) {
            for (int o = 0; o != m_matrix.x; o++) {
                if (z > my_strlen(msg)) {
                    m_matrix.matrix[x][o] = 0;
                } else {
                    m_matrix.matrix[x][o] = msg[z];
                }
                //printf("%d\t", m_matrix.matrix[x][o]);
            z++;
            }
        }
    }
    printf("\n");
    //end

//end
    
//encrypting message

    int result = 0;
    if (flag == 0) {
        printf("Encrypted message:\n");
        for (int i = 0; i != (m_matrix.y + 1); i++) {
            for (int j = 0; j != m_matrix.x; j++) {
                if (k_matrix.x == 2) {
                    result = ((k_matrix.matrix[0][j] * m_matrix.matrix[i][0]) + (k_matrix.matrix[1][j] * m_matrix.matrix[i][1]));
                    printf("%d ", result);
                    result = 0;
                }
                if (k_matrix.x == 3) {
                    result = ((k_matrix.matrix[0][j] * m_matrix.matrix[i][0]) + (k_matrix.matrix[1][j] * m_matrix.matrix[i][1]) + (k_matrix.matrix[2][j] * m_matrix.matrix[i][2]));
                    printf("%d ", result);
                    result = 0;
                }
                if (k_matrix.x == 4) {
                    result = ((k_matrix.matrix[0][j] * m_matrix.matrix[i][0]) + (k_matrix.matrix[1][j] * m_matrix.matrix[i][1]) + (k_matrix.matrix[2][j] * m_matrix.matrix[i][2]) + (k_matrix.matrix[3][j] * m_matrix.matrix[i][3]));
                    printf("%d ", result);
                    result = 0;
                }
                if (k_matrix.x == 5) {
                    result = ((k_matrix.matrix[0][j] * m_matrix.matrix[i][0]) + (k_matrix.matrix[1][j] * m_matrix.matrix[i][1]) + (k_matrix.matrix[2][j] * m_matrix.matrix[i][2]) + (k_matrix.matrix[3][j] * m_matrix.matrix[i][3]) + (k_matrix.matrix[4][j] * m_matrix.matrix[i][4]));
                    printf("%d ", result);
                    result = 0;
                }
            }
        }
    }
    printf("\n");

//end

//Decriptin message

    if (flag == 1)
        printf("Decrypted message:\n");
    
//end
    return (0);
}

/* printf("%s\n", key); */
/* printf("len of the key = %d\n", my_strlen(key)); */
/* printf("nbr de clonne = %d\n", k_matrix.x); */
/* printf("nbr de ligne = %d\n", k_matrix.y); */


/* int hn = 3; */
/* int ta = 0; */
/* printf("\n"); */
/* for (int u = 0; msg[u] != '\0'; u++) { */
/*     printf("%d ", msg[u]); */
/*     ta++; */
/*     if (ta == hn) { */
/*         printf("\n"); */
/*         ta = 0; */
/*     } */
/* } */
