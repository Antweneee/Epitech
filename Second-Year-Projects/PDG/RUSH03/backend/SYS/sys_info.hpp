/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** sys_info
*/

#include <ctime>
#include <string>
#include <iostream>

#ifndef SYS_INFO_HPP_
#define SYS_INFO_HPP_

class Sys_infos {
    public:
        Sys_infos();
        ~Sys_infos();
        std::string	getMachineName() const;
        std::string	getUserName() const;
        std::string	getOperating_Sys() const;
        std::string	getKernel() const;
        std::string	getDate() const;
        std::string splitDate();
        std::string splitHour();
        std::string getHour();
        std::string getTemp();
    private:
        std::string	hostName;
        std::string	userName;
        std::string	operating_Sys;
        std::string	kernel;
        std::string	date;
        std::string hour;
        std::string temp;
};

#endif