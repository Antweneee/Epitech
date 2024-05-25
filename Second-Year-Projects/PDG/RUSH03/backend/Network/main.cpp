/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** main
*/

#include "Network.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Network network;

    std::cout << network.getName() << std::endl;
    std::cout << network.getAdress() << std::endl;
    std::cout << network.getRxBytes() << std::endl;
    std::cout << network.getTxBytes() << std::endl;
    return 0;
}