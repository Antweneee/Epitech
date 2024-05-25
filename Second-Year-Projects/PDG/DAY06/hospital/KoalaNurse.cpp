/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD06-antoine.gavira-bottari
** File description:
** KoalaNurse
*/


#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(unsigned int id) : _id(id), _isworking(true)
{
}

KoalaNurse::~KoalaNurse()
{
    std :: cout << "Nurse " << _id << ": Finally some rest!"<< std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file;
    std::string::size_type pose = filename.find('.');
    std::string name = filename.substr(0, pose);
    std::string medic;

    file.open(filename);
    if (file.is_open())
    {
        getline(file, medic);
        file.close();
    } else
        return "";
    std::cout << "Nurse " << _id << ": Kreog! Mr." << name << " needs a " << medic << "!" << std::endl;
    return medic;
}

void KoalaNurse::timeCheck(void)
{
    if (_isworking == true)
        std::cout << "Nurse " << _id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse "
        << _id << ": Time to go home to my eucalyptus forest!" << std::endl;
    _isworking = !_isworking;
}