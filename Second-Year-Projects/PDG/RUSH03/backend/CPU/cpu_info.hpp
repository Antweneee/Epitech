/*
** EPITECH PROJECT, 2022
** cpu
** File description:
** cpu_info
*/

#ifndef CPU_INFO_HPP_
#define CPU_INFO_HPP_

#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/types.h>
#include <sys/utsname.h>
#include <thread>
#include <sys/sysinfo.h>

class IMonitorModule {
    public:
        // c/dtor
        IMonitorModule();
        ~IMonitorModule();

        //function
        void get_info();
        void print();
        long long VirtualMem_tot;
        long long VirtualMem_used;
        int memAvailable;
        int nbr_core;
        char *model_name;
        float cpu0;
        float cpu1;
        float cpu2;
        float cpu3;
        float cpu4;
        float cpu5;
        float cpu6;
        float cpu7;
    protected:
    private:
        // variable
        /*
        char *sys_name;
        char *node_name;
        char *domain_name;
        char *machine;
        char *release;
        char *version;
        long free_high;
        */

        //function
        int parse(std::string);
        int parse3(std::string);
        int get_mem_used(std::string, std::string, int);
        int get_mem_used2(std::string, std::string, int);
        char *get_line(std::string, std::string, int);
};


#endif /* !CPU_INFO_HPP_ */