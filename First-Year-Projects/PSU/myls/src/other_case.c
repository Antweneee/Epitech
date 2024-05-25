/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** other flag of my_ls
*/

#include "my_ls.h"
#include "my.h"

void right(struct stat sinfo, char *name)
{
    my_putchar(S_ISDIR(sinfo.st_mode) ? 'd' : '-');
    my_putchar((S_IRUSR & sinfo.st_mode) ? 'r' : '-');
    my_putchar((S_IWUSR & sinfo.st_mode) ? 'w' : '-');
    my_putchar((S_IXUSR & sinfo.st_mode) ? 'x' : '-');
    my_putchar((S_IRGRP & sinfo.st_mode) ? 'r' : '-');
    my_putchar((S_IWGRP & sinfo.st_mode) ? 'w' : '-');
    my_putchar((S_IXGRP & sinfo.st_mode) ? 'x' : '-');
    my_putchar((S_IROTH & sinfo.st_mode) ? 'r' : '-');
    my_putchar((S_IWOTH & sinfo.st_mode) ? 'w' : '-');
    my_putchar((S_IXOTH & sinfo.st_mode) ? 'x' : '-');
}

void function_time(char *f_time)
{
    for (int x = 4; x != 16; x++) {
        my_printf("%c", f_time[x]);
    }
    my_printf(" ");
}

void ls_a(DIR *dir, struct stat sinfo)
{
    struct dirent *info;

    while ((info = readdir(dir)) != 0) {
        stat(info->d_name, &sinfo);
        my_printf("%s  ", info->d_name);
    }
    my_printf("\n");
}

void ls_l(char *path, struct stat sinfo, int ac, char **av)
{
    struct dirent *info;
    char *time_f = NULL;
    struct passwd *uid;
    struct group *grp;
    DIR *dir = opendir(path);

    while ((info = readdir(dir)) != 0) {
        if (info->d_name[0] == '.')
            continue;
        stat(my_strcat(path, info->d_name), &sinfo);
        right(sinfo, info->d_name);
        uid = getpwuid(sinfo.st_uid);
        grp  = getgrgid(uid->pw_gid);
        time_f = ctime(&sinfo.st_mtime);
        my_printf(" %d %s %s %d ", sinfo.st_nlink, uid->pw_name, grp->gr_name,
        sinfo.st_size);
        function_time(time_f);
        my_printf(" %s\n", info->d_name);
    }
}
