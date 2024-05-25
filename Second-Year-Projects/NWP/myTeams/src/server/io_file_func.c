/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** IO_file_func
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "server.h"
#include "client.h"

char *read_file(int fd, const char *path)
{
    char *string;
    struct stat buf;

    if (stat(path, &buf) < 0)
        return NULL;
    string = malloc(sizeof(char) * (buf.st_size + 1));
    if (read(fd, string, buf.st_size) == -1)
        return NULL;
    string[buf.st_size] = '\0';
    return string;
}

int open_fd(const char *path)
{
    int fd = open(path, O_RDWR);

    if (fd == -1)
        return ERROR;
    return fd;
}

char *open_read_file(const char *path)
{
    int file_fd = open_fd(path);
    char *file_string;

    if (file_fd == -1)
        return NULL;
    file_string = read_file(file_fd, path);
    close(file_fd);
    return file_string;
}

void write_new_client(const char *path, char *name, char *uuid)
{
    FILE *file = fopen(path, "a+");
    char *tmp = malloc(sizeof(char) * SIZE);
    char *client_string = NULL;

    strcpy(tmp , "[");
    strcat(tmp , strdup(name));
    client_string = strcat(tmp , "] ");
    strcat(client_string, strdup(uuid));
    if (!open_read_file(path)[0])
        fprintf(file, "%s" , client_string);
    else
        fprintf(file, "\n%s" , client_string);
    fclose(file);
}

char *check_client_file(char *name)
{
    char *file_string = open_read_file(CLIENT_LIST_PATH);
    char **string = parse_str(file_string, 0, 1);
    char *name_tmp = malloc(sizeof(char) * SIZE);

    if (!string || !string[0])
        return NULL;
    for (int i = 0; string[i]; i++) {
        strcpy(name_tmp, strdup(strsep(&string[i], "]")) + 1);
        if (strcmp(name_tmp, name) == 0)
            return (strdup(string[i]) + 1);
    }
    return NULL;
}