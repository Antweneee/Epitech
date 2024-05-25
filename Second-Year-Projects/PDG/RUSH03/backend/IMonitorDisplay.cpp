/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** IMonitorDisplay
*/

#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay()
{
}

IMonitorDisplay::~IMonitorDisplay()
{
}

int IMonitorDisplay::initCpu0Bytes()
{
    _adress = "";
}

int IMonitorDisplay::initCpu1bytes()
{
    cpu_bytes = 0;
}

long long int IMonitorDisplay::initBytes()
{
    cpu_bytes = 1;
}

std::string IMonitorDisplay::initAdress()
{
    _adress = nullptr;
}

std::string IMonitorDisplay::initName()
{
    time_t time = 0;
}