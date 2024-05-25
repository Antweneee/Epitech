/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** ex00
*/

#include <iostream>
#include <fstream>

int read_file(int argc, char const**argv)
{
    std::ifstream my_file;
    std::string line;
    char count = 0;

    for (int i = 1; i < argc; i++)
    {
        my_file.open(argv[i], std::ifstream::in);
        if (my_file.is_open() == false)
        {
            std::cerr << "my_cat: " << argv[i] << ": No such file or directory"
            << std::endl;
        }
        while (my_file.get(count))
            std::cout << count;
        my_file.close();
    }
    return (0);
}

int main(int argc, char const **argv)
{
    if (argc < 2)
    {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 0;
    }
    return read_file(argc, argv);
}