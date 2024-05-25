#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <iostream>

int main()
{

    // UTSNAME
    utsname utsname_test;
    uname(&utsname_test);

    std::cout << "\n" << std::endl;
    std::cout << "UTSNAME :" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "sys name = " << utsname_test.sysname << std::endl;
    std::cout << "node name = " << utsname_test.nodename << std::endl;
    std::cout << "domain name = " << utsname_test.domainname << std::endl;
    std::cout << "machine = " << utsname_test.machine << std::endl;
    std::cout << "release = " << utsname_test.release << std::endl;
    std::cout << "version = " << utsname_test.version << std::endl;

    struct sysinfo sysinfo_test;
    sysinfo(&sysinfo_test);

    std::cout << "\n" << std::endl;
    std::cout << "SYSINFO :" << std::endl;
    std::cout << "\n" << std::endl;

    std::cout << "temps écoulé depuis le boot = " << sysinfo_test.uptime << std::endl;

    std::cout << "mémoire total du systeme = " << sysinfo_test.totalram << std::endl;
    std::cout << "mémoire dispo = " << sysinfo_test.freeram << std::endl;
    std::cout << "mémoire utilisée par les tampons = " << sysinfo_test.bufferram << std::endl;

    std::cout << "taille total du swap = " << sysinfo_test.totalswap << std::endl;
    std::cout << "espace dispo dans le swap = " << sysinfo_test.freeswap << std::endl;
    std::cout << "nombre de process actuels = " << sysinfo_test.procs << std::endl;

    /**************************** a ************************************/
    std::cout << "\n" << std::endl;
    std::cout << "TEST :" << std::endl;
    std::cout << "\n" << std::endl;

}