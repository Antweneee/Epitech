/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** cpu_info
*/

#include "cpu_info.hpp"

IMonitorModule::IMonitorModule()
{
    struct sysinfo info;
    sysinfo(&info);
    utsname utsname_test;
    uname(&utsname_test);

    VirtualMem_tot = info.totalram;
    VirtualMem_used = info.totalram - info.freeram;
    memAvailable = get_mem_used("MemAvailable:", "/proc/meminfo", 13);
    model_name = get_line("model name", "/proc/cpuinfo", 10);
    cpu0 = (float) get_mem_used2("cpu0", "/proc/stat", 4) / 1000;
    cpu1 = (float) get_mem_used2("cpu1", "/proc/stat", 4) / 1000;
    cpu2 = (float) get_mem_used2("cpu2", "/proc/stat", 4) / 1000;
    cpu3 = (float) get_mem_used2("cpu3", "/proc/stat", 4) / 1000;
    cpu4 = (float) get_mem_used2("cpu4", "/proc/stat", 4) / 1000;
    cpu5 = (float) get_mem_used2("cpu5", "/proc/stat", 4) / 1000;
    cpu6 = (float) get_mem_used2("cpu6", "/proc/stat", 4) / 1000;
    cpu7 = (float) get_mem_used2("cpu7", "/proc/stat", 4) / 1000;
    nbr_core = std::thread::hardware_concurrency();
}

IMonitorModule::~IMonitorModule()
{
}

void IMonitorModule::get_info()
{
    struct sysinfo info;
    sysinfo(&info);
    utsname utsname_test;
    uname(&utsname_test);

    VirtualMem_tot = info.totalram;
    VirtualMem_used = info.totalram - info.freeram;
    memAvailable = get_mem_used("MemAvailable:", "/proc/meminfo", 13);
    model_name = get_line("model name", "/proc/cpuinfo", 10);
    cpu0 = (float) get_mem_used2("cpu0", "/proc/stat", 4) / 1000;
    cpu1 = (float) get_mem_used2("cpu1", "/proc/stat", 4) / 1000;
    cpu2 = (float) get_mem_used2("cpu2", "/proc/stat", 4) / 1000;
    cpu3 = (float) get_mem_used2("cpu3", "/proc/stat", 4) / 1000;
    cpu4 = (float) get_mem_used2("cpu4", "/proc/stat", 4) / 1000;
    cpu5 = (float) get_mem_used2("cpu5", "/proc/stat", 4) / 1000;
    cpu6 = (float) get_mem_used2("cpu6", "/proc/stat", 4) / 1000;
    cpu7 = (float) get_mem_used2("cpu7", "/proc/stat", 4) / 1000;
    /*
    sys_name = utsname_test.sysname;
    node_name = utsname_test.nodename;
    domain_name = utsname_test.domainname;
    machine = utsname_test.machine;
    release = utsname_test.release;
    version = utsname_test.version;
    free_high = info.freehigh;
    */
}

char *parse2(std::string to_parse)
{
    char *get = (char *) to_parse.c_str();

    for (; *get != ':'; get++);
    get++; get++;
    return get;
}

char *IMonitorModule::get_line(std::string check, std::string path, int size)
{
    std::ifstream my_file(path);
    std::string line;
    char *res = NULL;

    if (my_file.is_open()) {
        while (getline(my_file, line)) {
            if (std::strncmp(line.c_str(), check.c_str(), size) == 0) {
                res = strdup(parse2(line));
                break;
            }
        }
    }
    my_file.close();
    return res;
}

int IMonitorModule::parse3(std::string to_parse)
{
    const char *get = to_parse.c_str();

    for (; *get < '0' || *get > '9'; get++);
    get++; get++;
    return std::atoi(get);
}

int IMonitorModule::get_mem_used2(std::string check, std::string path, int size)
{
    std::ifstream my_file(path);
    std::string line;
    int res = -1;

    if (my_file.is_open()) {
        while (getline(my_file, line)) {
            if (std::strncmp(line.c_str(), check.c_str(), size) == 0) {
                res = parse3(line);
                break;
            }
        }
    }
    my_file.close();
    return res;
}

int IMonitorModule::parse(std::string to_parse)
{
    const char *get = to_parse.c_str();

    for (; *get < '0' || *get > '9'; get++);
    return std::atoll(get);
}

int IMonitorModule::get_mem_used(std::string check, std::string path, int size)
{
    std::ifstream my_file(path);
    std::string line;
    int res = -1;

    if (my_file.is_open()) {
        while (getline(my_file, line)) {
            if (std::strncmp(line.c_str(), check.c_str(), size) == 0) {
                res = parse(line);
                break;
            }
        }
    }
    my_file.close();
    return res;
}

void IMonitorModule::print()
{
    std::cout << "Total Virtual Memory: " << VirtualMem_tot << std::endl;
    std::cout << "Virtual Memory Used: " << VirtualMem_used << std::endl;
    std::cout << "memAvailable: " << memAvailable << std::endl;
    std::cout << "model name: " << model_name << std::endl;
    std::cout << "cpu0: " << cpu0 << std::endl;
    std::cout << "cpu1: " << cpu1 << std::endl;
    std::cout << "cpu2: " << cpu2 << std::endl;
    std::cout << "cpu3: " << cpu3 << std::endl;
    std::cout << "cpu4: " << cpu4 << std::endl;
    std::cout << "cpu5: " << cpu5 << std::endl;
    std::cout << "cpu6: " << cpu6 << std::endl;
    std::cout << "cpu7: " << cpu7 << std::endl;
    /*
    std::cout << sys_name << std::endl;
    std::cout << node_name << std::endl;
    std::cout << domain_name << std::endl;
    std::cout << machine << std::endl;
    std::cout << release << std::endl;
    std::cout << version << std::endl;
    std::cout << free_high << std::endl;
    */
}