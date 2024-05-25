/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-antoine.gavira-bottari
** File description:
** create
*/

#include <stdio.h>
#include "client_commands.h"
#include "client.h"
#include "../libs/myteams/logging_client.h"

void handle_404_client_create(char *data)
{
    char **args = parse_str(data, 1, 0);

    if (strcmp(args[0], "team") == 0)
        client_error_unknown_team(args[1]);
    if (strcmp(args[0], "channel") == 0)
        client_error_unknown_channel(args[1]);
    if (strcmp(args[0], "thread") == 0)
        client_error_unknown_thread(args[1]);
}

void handle_301_client_create(char *data, bool event)
{
    char *team_uuid = malloc(sizeof(char) * SIZE);
    char *team_name = malloc(sizeof(char) * SIZE);
    char *team_description = malloc(sizeof(char) * SIZE);

    strcpy(team_uuid, strsep(&data, " "));
    strcpy(team_name, (strsep(&data, "]") + 1));
    strcpy(team_description, (strsep(&data, "]") + 2));
    if (event == false)
        client_print_team_created(team_uuid, team_name, team_description);
    else
        client_event_team_created(team_uuid, team_name, team_description);
    free(team_uuid);
    free(team_name);
    free(team_description);
}

void handle_311_client_create(char *data, bool event)
{
    char *uuid = malloc(sizeof(char) * SIZE);
    char *channel_name = malloc(sizeof(char) * SIZE);
    char *channel_description = malloc(sizeof(char) * SIZE);

    strcpy(uuid, strsep(&data, " "));
    strcpy(channel_name, (strsep(&data, "]") + 1));
    strcpy(channel_description, (strsep(&data, "]") + 2));
    if (event == false)
        client_print_channel_created(uuid, channel_name, channel_description);
    else
        client_event_channel_created(uuid, channel_name, channel_description);
    free(uuid);
    free(channel_name);
    free(channel_description);
}

void handle_321_client_create(char *data, bool event)
{
    char *t_uid = malloc(sizeof(char) * SIZE);
    char *u_uuid = malloc(sizeof(char) * SIZE);
    char *t_time = malloc(sizeof(char) * SIZE);
    char *t_title = malloc(sizeof(char) * SIZE);
    char *t_body = malloc(sizeof(char) * SIZE);

    strcpy(t_uid, strsep(&data, " "));
    strcpy(u_uuid, (strsep(&data, "]") + 1));
    strcpy(t_time, (strsep(&data, "]") + 2));
    strcpy(t_title, (strsep(&data, "]") + 2));
    strcpy(t_body, (strsep(&data, "]") + 2));
    if (event == false)
        client_print_thread_created(t_uid, u_uuid, atoi(t_time), t_title,
        t_body);
    else
        client_event_thread_created(t_uid, u_uuid, atoi(t_time), t_title,
        t_body);
    free(t_uid);
    free(u_uuid);
    free(t_time);
}

void handle_331_client_create(char *data)
{
    char *t_uid = malloc(sizeof(char) * SIZE);
    char *u_uid = malloc(sizeof(char) * SIZE);
    char *r_ti = malloc(sizeof(char) * SIZE);
    char *r_body = malloc(sizeof(char) * SIZE);

    strcpy(t_uid, strsep(&data, " "));
    strcpy(u_uid, (strsep(&data, "]") + 1));
    strcpy(r_ti, (strsep(&data, "]") + 2));
    strcpy(r_body, (strsep(&data, "]") + 2));
    client_print_reply_created(t_uid, u_uid, atoi(r_ti), r_body);
    free(t_uid);
    free(u_uid);
    free(r_ti);
    free(r_body);
}

void handle_331_client_create_call_all(char *data)
{
    char *t_uid = malloc(sizeof(char) * SIZE);
    char *u_uid = malloc(sizeof(char) * SIZE);
    char *r_ti = malloc(sizeof(char) * SIZE);
    char *r_body = malloc(sizeof(char) * SIZE);

    strcpy(t_uid, strsep(&data, " "));
    strcpy(u_uid, (strsep(&data, "]") + 1));
    strcpy(r_ti, (strsep(&data, "]") + 2));
    strcpy(r_body, (strsep(&data, "]") + 2));
    client_event_thread_reply_received(t_uid, u_uid, r_ti, r_body);
    free(t_uid);
    free(u_uid);
    free(r_ti);
    free(r_body);
}

void create_2(send_data_t data)
{
    if (data.status == 501)
        handle_301_client_create(strdup(data.response) + 7, true);
    if (data.status == 511)
        handle_311_client_create(strdup(data.response) + 7, true);
    if (data.status == 521)
        handle_321_client_create(strdup(data.response) + 7, true);
    if (data.status == 531)
        handle_331_client_create_call_all(strdup(data.response) + 7);
}

void create(send_data_t data, client_t *clients)
{
    if (data.status == 401)
        client_error_unauthorized();
    if (data.status == 403)
        client_error_already_exist();
    if (data.status == 404)
        handle_404_client_create(strdup(data.response) + 7);
    if (data.status == 301)
        handle_301_client_create(strdup(data.response) + 7, false);
    if (data.status == 311)
        handle_311_client_create(strdup(data.response) + 7, false);
    if (data.status == 321)
        handle_321_client_create(strdup(data.response) + 7, false);
    if (data.status == 331)
        handle_331_client_create(strdup(data.response) + 7);
    create_2(data);
    (void) clients;
}