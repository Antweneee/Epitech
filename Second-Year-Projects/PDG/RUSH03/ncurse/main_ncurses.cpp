/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGRUSH3-illyas.chihi
** File description:
** main
*/

#include "includes/ncurses.hpp"
#include <cstring>
#include <unistd.h>

void print_network()
{
    Network network;

    attron(COLOR_PAIR(4));
    for (int i = 0; i != COLS; i++){
        mvprintw(LINES - 9, i, " ");
        mvprintw(LINES - 8, i, " ");
    }
    mvprintw(LINES - 8, 5, "Network :");
    attroff(COLOR_PAIR(4));
    mvprintw(LINES - 6, 5, "nom du network:");
    mvprintw(LINES - 6, 32, "%s", network.getName().c_str());
    mvprintw(LINES - 5, 5, "adresse ip:");
    mvprintw(LINES - 5, 32, "%s", network.getAdress().c_str());
    mvprintw(LINES - 4, 5, "packets receptionnés:");
    mvprintw(LINES - 4, 32, "%d", network.getRxBytes());
    mvprintw(LINES - 3, 5, "packets envoyés:");
    mvprintw(LINES - 3, 32, "%d", network.getTxBytes());
}

void print_cpu()
{
    IMonitorModule cpu;
    auto percent = ((cpu.VirtualMem_used * 100) / cpu.VirtualMem_tot);

    attron(COLOR_PAIR(4));
    mvprintw(1, 5, "CPU :");
    attroff(COLOR_PAIR(4));

    mvprintw(4, 5, "Total Virtual Memory:");
    mvprintw(4, 40, "%lld bytes", cpu.VirtualMem_tot);
    mvprintw(8, 5, "Virtual memory usage:");
    mvprintw(9, 6, "[");
    mvprintw(9, 106, "]");

    mvprintw(9, COLS / 2 + 50, "nombre de coeur : %d", cpu.nbr_core);


    for (int i = 0; i != 99; i++) {
        attron(COLOR_PAIR(8));
        mvprintw(9, i + 7, "I");
        attroff(COLOR_PAIR(8));
    }

    for (int i = 0; i != percent; i++)
    {
        if (i < 25) {
            attron(COLOR_PAIR(7));
            mvprintw(9, 108, "%lld%%", percent);
            attroff(COLOR_PAIR(7));

            attron(COLOR_PAIR(6));
            mvprintw(9, i + 7, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 25 && i < 60) {
            attron(COLOR_PAIR(9));
            mvprintw(9, 108, "%lld%%", percent);
            attroff(COLOR_PAIR(9));

            attron(COLOR_PAIR(5));
            mvprintw(9, i + 7, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(3));
            mvprintw(9, 108, "%lld%%", percent);
            attroff(COLOR_PAIR(3));

            attron(COLOR_PAIR(1));
            mvprintw(9, i + 7, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    mvprintw(5, 5, "Virtual Memory Used:");
    mvprintw(5, 40, "%lld bytes", cpu.VirtualMem_used);

    mvprintw(12, 5, "Memory still available:");
    mvprintw(12, 40, "%lld097 bytes", cpu.memAvailable);
}

void print_all_cpu()
{
    IMonitorModule cpu;

    attron(COLOR_PAIR(4));
    for (int i = 0; i != COLS; i++)
        mvprintw(1, i, " ");
    mvprintw(16, 5, "CPU's cores :");
    attroff(COLOR_PAIR(4));

    cpu.get_info();
    attron(COLOR_PAIR(9));
    mvprintw(19, 110, "%lld%%", int(cpu.cpu0));
    mvprintw(22, 110, "%lld%%", int(cpu.cpu1));
    mvprintw(25, 110, "%lld%%", int(cpu.cpu2));
    mvprintw(28, 110, "%lld%%", int(cpu.cpu3));
    attroff(COLOR_PAIR(9));
    attron(COLOR_PAIR(7));
    mvprintw(31, 110, "%lld%%", int(cpu.cpu4));
    mvprintw(34, 110, "%lld%%", int(cpu.cpu5));
    mvprintw(37, 110, "%lld%%", int(cpu.cpu6));
    mvprintw(40, 110, "%lld%%", int(cpu.cpu7));
    attroff(COLOR_PAIR(7));
    mvprintw(18, 5, "CPU core 1:");
    mvprintw(19, 4, "[");
    mvprintw(19, 104, "]");
    mvprintw(21, 5, "CPU core 2:");
    mvprintw(22, 4, "[");
    mvprintw(22, 104, "]");
    mvprintw(24, 5, "CPU core 3:");
    mvprintw(25, 4, "[");
    mvprintw(25, 104, "]");
    mvprintw(27, 5, "CPU core 4:");
    mvprintw(28, 4, "[");
    mvprintw(28, 104, "]");
    mvprintw(30, 5, "CPU core 5:");
    mvprintw(31, 4, "[");
    mvprintw(31, 104, "]");
    mvprintw(33, 5, "CPU core 6:");
    mvprintw(34, 4, "[");
    mvprintw(34, 104, "]");
    mvprintw(36, 5, "CPU core 7:");
    mvprintw(37, 4, "[");
    mvprintw(37, 104, "]");
    mvprintw(39, 5, "CPU core 8:");
    mvprintw(40, 4, "[");
    mvprintw(40, 104, "]");

    for (int i = 0; i != int(cpu.cpu0); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(19, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(19, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(19, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu1); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(22, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(22, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(22, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu2); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(25, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(25, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(25, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu3); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(28, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(28, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(28, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu4); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(31, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(31, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(31, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu5); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(34, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(34, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(34, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu6); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(37, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(37, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(37, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
    for (int i = 0; i != int(cpu.cpu7); i++) {
        if (i < 35) {
            attron(COLOR_PAIR(6));
            mvprintw(40, i + 5, "I");
            attroff(COLOR_PAIR(6));
        }
        else if (i >= 35 && i < 60) {
            attron(COLOR_PAIR(5));
            mvprintw(40, i + 5, "I");
            attroff(COLOR_PAIR(5));
        }
        else if (i >= 60) {
            attron(COLOR_PAIR(1));
            mvprintw(40, i + 5, "I");
            attroff(COLOR_PAIR(1));
        }
    }
}

void print_sys_info()
{
    Sys_infos sys_info;

    attron(COLOR_PAIR(4));
    for (int i = 0; i != COLS; i++){
        mvprintw(15, i, " ");
        mvprintw(16, i, " ");
    }

    for (int i = 0; i != 17; i++){
        mvprintw(i, COLS / 2 + 20, " ");
        mvprintw(i, COLS / 2 + 19, " ");
        mvprintw(i, COLS / 2 + 18, " ");
    }
    mvprintw(1, COLS / 2 + 24, "Infos système :");
    attroff(COLOR_PAIR(4));
    mvprintw(3, COLS / 2 + 48, "Hy");
    attron(COLOR_PAIR(3));
    mvprintw(3, COLS / 2 + 51, "%s", sys_info.getUserName().c_str());
    attroff(COLOR_PAIR(3));
    mvprintw(5, COLS / 2 + 24, "How are you on this %s", sys_info.getDate().c_str());
    mvprintw(7, COLS / 2 + 24, "machine name : %s", sys_info.getMachineName().c_str());
    mvprintw(9, COLS / 2 + 24, "os : %s", sys_info.getOperating_Sys().c_str());
    mvprintw(11, COLS / 2 + 24, "kernel version : %s", sys_info.getKernel().c_str());
    mvprintw(13, COLS / 2 + 24, "time : %s", sys_info.getHour().c_str());
    mvprintw(25, COLS / 2 + 47, "CPU temp : %s", sys_info.getTemp().c_str());
}

void print_options()
{
    attron(COLOR_PAIR(10));
    mvprintw(LINES - 7, COLS - 16, "Disable");
    attroff(COLOR_PAIR(10));
    attron(COLOR_PAIR(3));
    mvprintw(LINES - 6, COLS - 21, "C-Core Monitoring");
    mvprintw(LINES - 5, COLS - 19, "S-Systeme info");
    mvprintw(LINES - 4, COLS - 17, "I-CPU info");
    mvprintw(LINES - 3, COLS - 17, "N-Network");
    attroff(COLOR_PAIR(3));
}


void print_alerts()
{
    Sys_infos sys_info;
    IMonitorModule cpu;
    auto percent = ((cpu.VirtualMem_used * 100) / cpu.VirtualMem_tot);

    if (std::stoi(sys_info.getTemp().c_str()) > 92)
    {
        attron(COLOR_PAIR(4));
        mvprintw(LINES / 2 + 3, COLS / 2 + 43, "!!!!!!!!!!!!!!!!!!!!!!!!!!");
        mvprintw(LINES / 2 + 4, COLS / 2 + 43, "!! Votre CPU surchauffe !!");
        mvprintw(LINES / 2 + 5, COLS / 2 + 43, "!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attroff(COLOR_PAIR(4));
        refresh();
        napms(5000);
        clear();
    }

    if (percent == 93)
    {
        attron(COLOR_PAIR(4));
        mvprintw(LINES / 2 + 3, COLS / 2 + 32, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        mvprintw(LINES / 2 + 4, COLS / 2 + 32, "!! Votre pc est presque a cours de mémoire vive !!");
        mvprintw(LINES / 2 + 5, COLS / 2 + 32, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        attroff(COLOR_PAIR(4));
        refresh();
        napms(5000);
        clear();
    }
}


int main_ncurses(void)
{
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_BLACK, COLOR_RED);

    int a = 0;
    keypad(stdscr, TRUE);
    refresh();
    int x;
    int y;
    int x_map = 35;
    int y_map = 125;
    getmaxyx(stdscr, x, y);

    while (x < x_map || y < y_map) {
        getmaxyx(stdscr, x, y);
        clear();
        attron(COLOR_PAIR(3));
        mvprintw(LINES / 2, COLS / 2 - (strlen("ANGRANDI LA FENETRE") / 2), "ANGRANDI LA FENETRE");
        attron(COLOR_PAIR(3));
        refresh();
    }
    while (1) {

        attron(COLOR_PAIR(1));
        box(stdscr, '*', '*');
        attroff(COLOR_PAIR(1));

        refresh();
        print_network();
        print_all_cpu();
        print_sys_info();
        print_options();
        print_cpu();
        print_alerts();

    }

    endwin();
    return 0;
}