/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "sfml.hpp"
#include "../../backend/CPU/cpu_info.hpp"
#include "../../backend/SYS/sys_info.hpp"

class Display {
    public:
        Display();
        ~Display();

    void setupMem(const std::string&, info_t *);
    void setupCpu0(const std::string&, info_t *info);
    void setupCpu1(const std::string&, info_t *info);
    void setupCpu2(const std::string&, info_t *info);
    void setupCpu3(const std::string&, info_t *info);
    void setupCpu4(const std::string&, info_t *info);
    void setupCpu5(const std::string&, info_t *info);
    void setupCpu6(const std::string&, info_t *info);
    void setupCpu7(const std::string&, info_t *info);
    void genericsetu(sf::Text txt, std::string, int x, int y, info_t *info, sf::Color);
    std::string convertFloat(float conv);
    sf::Text _pourcentMem;
    sf::Text _pourcentCpu0;
    sf::Text _pourcentCpu1;
    sf::Text _pourcentCpu2;
    sf::Text _pourcentCpu3;
    sf::Text _pourcentCpu4;
    sf::Text _pourcentCpu5;
    sf::Text _pourcentCpu6;
    sf::Text _pourcentCpu7;
    protected:
    private:
};

#endif /* !DISPLAY_HPP_ */
