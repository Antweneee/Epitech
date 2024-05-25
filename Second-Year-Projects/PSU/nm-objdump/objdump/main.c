/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
** File description:
** main
*/

#include "objdump.h"

bool file_isexecutable(char const*str)
{
    int fd = 0;
    int filesize = 0;
    void *data = NULL;
    Elf64_Ehdr *elf = NULL;

    fd = open(str, O_RDONLY);
    if (fd == -1) {
        perror("open :");
        return 84;
    }
    filesize = lseek(fd, 0, SEEK_END);
    data = mmap(NULL, filesize, PROT_READ, MAP_SHARED, fd, 0);
    if (data != NULL) {
        elf = (Elf64_Ehdr *)(data);
        if (elf->e_type == ET_REL || elf->e_type == ET_EXEC|| elf->e_type == ET_DYN)
            return true;
    }
    return false;
}

int check_file(char const *str)
{
    if (file_isexecutable(str) == true)
        return 0;
    return 84;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 84;
    if (check_file(argv[1]) == 84)
        return 84;
    return 0;
}
