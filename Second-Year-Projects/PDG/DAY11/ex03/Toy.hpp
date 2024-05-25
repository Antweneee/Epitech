/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD11-antoine.gavira-bottari
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"


class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };
        Toy() : type(BASIC_TOY), name("toy"), picture(Picture()) {}
        Toy(ToyType type, std::string name, std::string filname) : type(type), name(name),  picture(filname) {}
        Toy(const Toy &cpy) = default;
        virtual ~Toy() {}

        ToyType getType() const {return type;}
        std::string getName() const {return name;}
        std::string getAscii() const {return picture.data;}
        void setName(std::string set) {name = set;}
        void setAscii(std::string set) {picture.getPictureFromFile(set);}
        virtual void speak(std::string say);

        Toy &operator=(Toy const &cpy);
        Toy &operator<<(std::string const &ascii);
    protected:
        ToyType type;
        std::string name;
        Picture picture;
    private:
};

#endif /* !TOY_HPP_ */
