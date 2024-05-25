/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>

class Picture {
    public:
        Picture(const std::string &file) { getPictureFromFile(file);}
        Picture() {data ="";}
        ~Picture() {}

        bool getPictureFromFile(const std::string &file);
        std::string data;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */