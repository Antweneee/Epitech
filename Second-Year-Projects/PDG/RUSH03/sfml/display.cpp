/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** display
*/

#include "includes/Display.hpp"
#include "../backend/CPU/cpu_info.hpp"
#include <string>
#include <iostream>

Display::Display()
{
}

Display::~Display()
{
}

void Display::setCpu0(const std::string& text)
{
    _pourcentCpu0.setString(text);
}

void Display::setCpu1(const std::string& text)
{
    _pourcentCpu1.setString(text);
}

void Display::setCpu2(const std::string& text)
{
    _pourcentCpu2.setString(text);
}

void Display::setCPu3(const std::string& text)
{
    _pourcentCpu3.setString(text);
}

std::string Display::convertFloat()
{
    IMonitorModule disp;

    std::string cpu0 = std::to_string(disp.cpu0);
    return cpu0;
}