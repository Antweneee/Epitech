/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD08-antoine.gavira-bottari
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>

class Droid {
    public:
        //constructor

        Droid(std::string id = "");
        Droid(Droid const&);
        ~Droid();

        //function

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus()const;
        void setId(std::string id);
        void setEnergy(size_t engergy);
        void setStatus(std::string *status);

        //operator
        Droid &operator=(Droid const &cpy);
        bool operator==(Droid const &check) const;
        bool operator!=(Droid const &check) const;
        Droid &operator<<(size_t &energy);
    protected:
    private:
        //variables

        std::string _id;
        size_t _Energy;
        const size_t _Attack;
        const size_t _Toughness;
        std::string *_Status;
};

std::ostream &operator<<(std::ostream &print, Droid const &droid);

#endif /* !DROID_HPP_ */
