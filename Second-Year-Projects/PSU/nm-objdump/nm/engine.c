/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
** File description:
** engine
*/

#include "nm.h"

char *my_strrchr(char const *str, char c)
{
    char *tmp = malloc(sizeof(char) * strlen(str));
    char *cmp = (char *)str;
    int check = 0;

    if (!str)
        return NULL;
    for (size_t i = 0; i < strlen(str); i++)
        if (str[i] == c)
            check++;
    if (check == 0)
        return (char *)str;
    for (; *cmp != '\0'; cmp++)
        if (*cmp == c)
            strcpy(tmp, cmp);
    tmp++;
    return tmp;
}

void display(char *str, Elf64_Shdr *symtab, Elf64_Sym *sym, Elf64_Shdr *shdr)
{
    char *tmp = NULL;
    char c;

    for (size_t i = 0; i < symtab->sh_size / symtab->sh_entsize; i++) {
        tmp = my_strrchr(str + sym[i].st_name, '/');
        if (strcmp(tmp, "") == 0 || sym[i].st_info == STT_FILE)
            continue;
        else {
            c = get_symbols(shdr, sym[i]);
            if (sym[i].st_value)
                printf("%016lx", sym[i].st_value);
            else {
                if (c == 'w' || c == 'U')
                    printf("                ");
                else
                    printf("0000000000000000");
            }
            printf(" %c ", c);
            printf("%s\n", tmp);
        }
    }
}

void extract_data(void *file_data)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr *)(file_data);
    Elf64_Shdr *shdr = (Elf64_Shdr *) (file_data + elf->e_shoff);
    Elf64_Shdr *symtab;
    Elf64_Shdr *strtab;
    Elf64_Sym *sym;
    char *str = (char *) (file_data + shdr[elf->e_shstrndx].sh_offset);

    for (int i = 0; i < elf->e_shnum; i++) {
        if (shdr[i].sh_size) {
            if (strcmp(&str[shdr[i].sh_name], ".symtab") == 0)
                symtab = (Elf64_Shdr *) &shdr[i];
            if (strcmp(&str[shdr[i].sh_name], ".strtab") == 0)
                strtab = (Elf64_Shdr *) &shdr[i];
        }
    }
    sym = (Elf64_Sym *) (file_data + symtab->sh_offset);
    str = (char*) (file_data + strtab->sh_offset);
    display(str, symtab, sym, shdr);
}

int get_info_file(char const *file)
{
    int fd = 0;
    int size = 0;
    void *data = NULL;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return EXIT_FAILURE;
    size = lseek(fd, 0, SEEK_END);
    data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0);
    if (data)
        extract_data(data);
    else
        perror("mmap");
    return 0;
}

int engine(char const *str)
{
    get_info_file(str);
    return 0;
}
