/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** data
*/

#ifndef MYDATA_H_
    #define MYDATA_H_

    #define SIZE 1024

typedef struct send_data_s
{
    char msg[SIZE];
    int status;
    char response[SIZE];
    char user_name[SIZE];
    char user_uuid[SIZE];
    char use[SIZE];
} send_data_t;

#endif /* !MYDATA_H_ */