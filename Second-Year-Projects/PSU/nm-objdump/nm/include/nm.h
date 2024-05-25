/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
** File description:
** nm
*/

#ifndef NM_H_
    #define NM_H_

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <elf.h>
    #include <zconf.h>
    #include <sys/mman.h>

int engine(char const *str);
char get_symbols(Elf64_Shdr *symtab, Elf64_Sym sym);

#endif /* !NM_H_ */
