/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>
#include <string>

class Network
{
public:
    Network();
    ~Network();
    std::string getName() const {return _name;}
    std::string getAdress() const {return _adress;}
    int getTxBytes() const {return tx_bytes;}
    int getRxBytes() const {return rx_bytes;}
    int initTxBytes();
    int initRxbytes();
    long long int initBytes();
    std::string initAdress();
    std::string initName();
protected:
private:
    std::string _name;
    std::string _adress;
    int tx_bytes;
    int rx_bytes;
};

#endif /* !NETWORK_HPP_ */
