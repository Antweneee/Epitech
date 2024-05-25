/*
** EPITECH PROJECT, 2020
** ls.h
** File description:
** .h for my_ls
*/

#ifndef ls_H_
#define ls_H_

#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stddef.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
void basic_ls(DIR *dir, struct stat sinfo);
void gestion(int ac, char **av, struct stat sinfo);
void ls_a(DIR *dir, struct stat sinfo);
void right(struct stat sinfo, char *name);
void function_time(char *f_time);
void ls_l(char *path, struct stat sinfo, int ac, char **av);

#endif /* ls_H_ */
