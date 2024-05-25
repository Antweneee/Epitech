/*
** EPITECH PROJECT, 2022
** B-PSU-400-PAR-4-1-nmobjdump-antoine.gavira-bottari
** File description:
** getChar
*/

#include "nm.h"

static bool undefined(char c)
{
    return (c == ' ');
}

void check_more_symbols(Elf64_Shdr *shdr, Elf64_Sym sym, char *c)
{
    if (sym.st_shndx == SHN_UNDEF && undefined(*c))
        *c = 'U';
    if (sym.st_shndx == SHN_ABS && undefined(*c))
        *c = 'A';
    if (sym.st_shndx == SHN_COMMON && undefined(*c))
        *c = 'C';
    if (shdr[sym.st_shndx].sh_type == SHT_DYNAMIC && undefined(*c))
        *c = 'D';
    if ((shdr[sym.st_shndx].sh_type == SHT_NOBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) && undefined(*c))
        *c = 'B';
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == SHF_ALLOC) && undefined(*c))
        *c = 'R';
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) && undefined(*c))
        *c = 'D';
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
        shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) && undefined(*c))
        *c = 'T';
}

void check_last_symbols(Elf64_Shdr *shdr, Elf64_Sym sym, char *c)
{
    if ((shdr[sym.st_shndx].sh_type == SHT_DYNAMIC
        || ELF64_ST_TYPE(sym.st_info) == STT_OBJECT
        || ELF64_ST_TYPE(sym.st_info) == STT_NOTYPE) && undefined(*c))
        *c = 'D';
}

char get_symbols(Elf64_Shdr *shdr, Elf64_Sym sym)
{
    char c = ' ';

    if (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE && undefined(c))
        c = 'u';
    else if (ELF64_ST_BIND(sym.st_info) == STB_WEAK && undefined(c))
        c = 'W';
    else if ((ELF64_ST_BIND(sym.st_info) == STB_WEAK && ELF64_ST_TYPE(sym.st_info) == STT_OBJECT) && undefined(c))
        c = 'V';
    if (sym.st_shndx == SHN_UNDEF && (c == 'W' || c == 'V'))
        c += 32;
    check_more_symbols(shdr, sym, &c);
    check_last_symbols(shdr, sym, &c);
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && undefined(c) == false)
        c += 32;
    return c;
}