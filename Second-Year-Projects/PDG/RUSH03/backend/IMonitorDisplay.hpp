/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** IMonitorDisplay
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include <iostream>
#include <string>

class IMonitorDisplay {
    public:
        IMonitorDisplay();
        virtual ~IMonitorDisplay() = default;
            std::string getMonitor() const {return _cpuname;}
    std::string getCore() const {return _adress;}
    int getCpuUsage() const {return cpu_bytes;}
    int getCPUBytes() const {return rcpu_bytes;}
    int initCpu0Bytes();
    int initCpu1bytes();
    long long int initBytes();
    std::string initAdress();
    std::string initName();
protected:
private:
    std::string _cpuname;
    std::string _adress;
    int cpu_bytes;
    int rcpu_bytes;
};

#endif /* !IMONITORDISPLAY_HPP_ */