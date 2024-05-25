/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** sys_info
*/

#include "sys_info.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <limits.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <algorithm>

Sys_infos::Sys_infos()
{
    char host[1020];
    char login[1020];
    struct utsname buffer;
    uname(&buffer);

    this->date = splitDate();
    this->hour = getHour();
    gethostname(host, HOST_NAME_MAX);
    this->hostName = host;
    getlogin_r(login, LOGIN_NAME_MAX);
    this->userName = login;
    this->operating_Sys = buffer.sysname;
    this->kernel = buffer.release;
    this->temp = getTemp();
}

Sys_infos::~Sys_infos()
{
}

std::string Sys_infos::getMachineName() const
{
    return (this->hostName);
}
std::string Sys_infos::getUserName() const
{
    return (this->userName);
}
std::string Sys_infos::getOperating_Sys() const
{
    return (this->operating_Sys);
}
std::string Sys_infos::getKernel() const
{
    return (this->kernel);
}
std::string Sys_infos::getDate() const
{
    return (this->date);
}

 std::string getYear()
{
    time_t r = time(0);

    std::string ptr = ctime(&r);
    return ptr.substr(20);
}

std::string Sys_infos::splitDate()
{
    time_t r = time(0);

    std::string str = ctime(&r);
    std::string ptr;
    reverse(str.begin(), str.end());
    ptr = str.substr(15);
    reverse(ptr.begin(), ptr.end());
    std::string sstr = ptr + " " + getYear();
    return sstr;
}

std::string Sys_infos::getHour()
{
    time_t news = time(0);

    std::string str = ctime(&news);
    std::string ptr;
    reverse(str.begin(), str.end());
    ptr = str.substr(5);
    reverse(ptr.begin(), ptr.end());
    ptr = ptr.substr(11);
    std::string sstr = ptr;
    return sstr;
}

std::string Sys_infos::getTemp()
{
    float i = 0;
    std::ifstream indata;
    indata.open("/sys/class/thermal/thermal_zone5/temp");
    if(!indata)
        exit(1);
    indata >> i;
    while (!indata.eof()) {
      indata >> i;
    }
   indata.close();
   return std::to_string(int(i / 1000)) + "°C";
}