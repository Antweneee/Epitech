/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD07pm-antoine.gavira-bottari
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();

        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();

        void ping();
        void locateSquad();

    private:
        int m_serial;
        int _x;
        int _y;
        KreogCom *_next;
};

#endif /* !KREOGCOM_HPP_ */
