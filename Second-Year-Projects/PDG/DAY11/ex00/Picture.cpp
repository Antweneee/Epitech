/*
** EPITECH PROJECT, 2022
** $
** File description:
** Picture
*/

#include <fstream>
#include <sstream>
#include "Picture.hpp"

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream my_file;
    std::stringstream tmp;

    my_file.open(file, std::ifstream::in);
    if (my_file.is_open() == false)
    {
        data = "ERROR";
        return false;
    }
    tmp << my_file.rdbuf();
    data = tmp.str();
    return true;
}
