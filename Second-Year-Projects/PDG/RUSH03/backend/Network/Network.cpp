/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** Network
*/

#include "Network.hpp"
#include <iostream>

Network::Network()
{
    tx_bytes = initTxBytes();
    rx_bytes = initRxbytes();
    _adress = initAdress();
    _name = initName();
}

Network::~Network()
{
}

int Network::initTxBytes()
{
    struct ifaddrs *ifaddr;
    struct rtnl_link_stats *stats;
    int i = 0;

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    for (struct ifaddrs *ifa = ifaddr; i < 2; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
            continue;
        if (ifa->ifa_addr->sa_family == AF_PACKET && ifa->ifa_data != NULL)
            stats = (struct rtnl_link_stats *)ifa->ifa_data;
        if (i == 1) break;
        i += 1;
    }
    freeifaddrs(ifaddr);
    return stats->tx_bytes;
}

int Network::initRxbytes()
{
    struct ifaddrs *ifaddr;
    struct rtnl_link_stats *stats;
    int i = 0;

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    for (struct ifaddrs *ifa = ifaddr; i < 2; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr == NULL)
            continue;
        if (ifa->ifa_addr->sa_family == AF_PACKET && ifa->ifa_data != NULL)
            stats = (struct rtnl_link_stats *)ifa->ifa_data;
        if (i == 1) break;
        i += 1;
    }
    freeifaddrs(ifaddr);
    return stats->rx_bytes;
}

std::string Network::initAdress()
{
    struct ifaddrs *ifaddr;
    int family;
    char host[NI_MAXHOST];
    int i = 0;

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    for (struct ifaddrs *ifa = ifaddr; i < 2; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;
        if (ifa->ifa_addr->sa_family == AF_INET || ifa->ifa_addr->sa_family == AF_INET6) {
            getnameinfo(ifa->ifa_addr,
                (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6),
                host, NI_MAXHOST,
                NULL, 0, NI_NUMERICHOST);
            if (i == 1) break;
            i += 1;
        }
    }
    freeifaddrs(ifaddr);
    return host;
}

std::string Network::initName()
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;
    std::string str;
    int i = 0;

    if (getifaddrs(&ifaddr) == -1)
    {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }
    for (ifa = ifaddr; i < 2; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            i -= 1;
            continue;
        }
        str = ifa->ifa_name;
        //freeifaddrs(ifaddr);
        if (i == 1)
            return str;
        i += 1;
    }
    return NULL;
}