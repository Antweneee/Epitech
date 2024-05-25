/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : _name(name), _isworking(false)
{
    std::cout << "Dr." << _name << ": I'm Dr." << _name << "! How do you kreog?"
     << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string medics[5] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};
    std::string file_name = patient->_name + ".report";
    int index = random() % 5;
    std::ofstream file(file_name);

    std::cout << "Dr." << _name << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();
    if (file.is_open())
        file << medics[index];
}

void KoalaDoctor::timeCheck(void)
{
    if (_isworking)
        std::cout <<  "Dr." << _name << ": Time to get to work!" << std::endl;
    else
        std::cout <<  "Dr." << _name << ": Time to go home to my eucalyptus forest!" << std::endl;
    _isworking = !_isworking;
}
