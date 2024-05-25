/*
** EPITECH PROJECT, 2022
** B-OOP-400-PAR-4-1-arcade-valentin.fouillet
** File description:
** ncurse
*/

#include "ncurse.hpp"
#include <cstring>
#include <fstream>

NCURSE::NCURSE()
{
    _key = Arcade::KEYS::NIL;
}

NCURSE::~NCURSE()
{
    endwin();
}

Arcade::KEYS NCURSE::get_key()
{
    Arcade::KEYS new_key = Arcade::KEYS::NIL;
    int a = getch();

    if (a == KEY_UP)
        new_key = Arcade::KEYS::UP;
    else if (a == KEY_DOWN)
        new_key = Arcade::KEYS::DOWN;
    else if (a == KEY_LEFT)
        new_key = Arcade::KEYS::LEFT;
    else if (a == KEY_RIGHT)
        new_key = Arcade::KEYS::RIGHT;
    else if (a == 27)
        new_key = Arcade::KEYS::ESC;
    else if (a == KEY_F(1))
        new_key = Arcade::KEYS::F1;
    else if (a == KEY_F(2))
        new_key = Arcade::KEYS::F2;
    else if (a == KEY_F(3))
        new_key = Arcade::KEYS::F3;
    else if (a == KEY_F(4))
        new_key = Arcade::KEYS::F4;
    else if (a == 'r')
        new_key = Arcade::KEYS::R;
    else if (a == 'm')
        new_key = Arcade::KEYS::M;
    else if (a == 'f')
        new_key = Arcade::KEYS::F;
    else
        new_key = Arcade::KEYS::NIL;

    if (new_key == Arcade::KEYS::NIL)
        new_key = this->_key;
    else
        this->_key = new_key;
    return new_key;
}

void put_color(const char *str, int map_size, int line)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'P' || str[i] == 'x' || str[i] == 'o') {
            attron(COLOR_PAIR(10));
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, 'C');
            attroff(COLOR_PAIR(10));
        } else if (str[i] == 'W') {
            attron(COLOR_PAIR(11));
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, str[i]);
            attroff(COLOR_PAIR(11));
        } else if (str[i] == '*' || str[i] == ',') {
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, ' ');
        } else if (str[i] == 'T') {
            attron(COLOR_PAIR(12));
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, str[i]);
            attroff(COLOR_PAIR(12));
        } else if (str[i] == 'G' || str[i] == '0') {
            attron(COLOR_PAIR(13));
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, str[i]);
            attroff(COLOR_PAIR(13));
        } else if (str[i] == 'C' || str[i] == 'a') {
            attron(COLOR_PAIR(14));
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, str[i]);
            attroff(COLOR_PAIR(14));
        } else
            mvaddch(LINES / 2 - map_size / 2 - 1 + line, COLS / 2 - strlen(str) / 2 + i, str[i]);
    }
}


void NCURSE::draw(IInfo::GameData &data)
{
    // if (stdscr != nullptr)
    //     init();
    int a = 0;
    clear();

    for (auto i = data._map.begin(); i != data._map.end(); i++) {
        a++;
        put_color(i->Content.c_str(), data._map.size(), a);
    }
    refresh();
}

void print_border(int a, int top)
{
    for (int i = 0; i != a; i++) {
        if (i == 0 && top == 1)
            addch(ACS_ULCORNER);
        else if (i == a - 1 && top == 1)
            addch(ACS_URCORNER);
        else if (i == 0 && top == 0)
            addch(ACS_LLCORNER);
        else if (i == a - 1 && top == 0)
            addch(ACS_LRCORNER);
        else
            addch(ACS_HLINE);
    }
}

void score_page(Arcade::PROTO game)
{
    int a = 0;
    int b = 0;
    std::string test;
    std::ifstream file;
    if (game == Arcade::PROTO::PACMAN)
        file.open("./config/pacman_hs.txt");
    else
        file.open("./config/nibbler_hs.txt");

    mvprintw(LINES / 2 + 4, 5, "best scores:");

    while (std::getline(file, test))
    {
        if (a > 3)
            break;
        mvprintw(LINES / 2 + 6, 18 + test.length() / 2 + b, test.c_str());
        a++;
        b+=15;
    }

    file.close();
}

void lets_play(Arcade::PROTO game)
{
    std::string play = "Let's play in";

    clear();
    mvprintw(5, COLS / 2 - play.length() / 2, play.c_str());
    score_page(game);
    attron(COLOR_PAIR(1));
    box(stdscr, 'V', '-');
    mvprintw(LINES / 2, COLS / 2, "3");
    refresh();
    sleep(1);
    mvprintw(LINES / 2, COLS / 2, "2");
    refresh();
    sleep(1);
    mvprintw(LINES / 2, COLS / 2, "1");
    refresh();
    sleep(1);
    mvprintw(LINES / 2, COLS / 2, "0");
    refresh();
    sleep(1);
    attroff(COLOR_PAIR(1));
}

Arcade::PROTO choose_lib_page(std::string name)
{
    std::string str = "|  CHOOSE A GRAPHIC LIB :  |";
    std::string ncurse = "NCURSE";
    std::string sfml = "SFML";
    std::string sdl = "SDL";
    int status = 1;

    for (int a = 'z'; a != 10; a = getch()) {
        clear();
        attron(COLOR_PAIR(2));
        box(stdscr, '?', '?');
        attroff(COLOR_PAIR(2));
        mvprintw(3, COLS / 2 - name.length() / 2 - 1, name.c_str());
        move(LINES / 2 - 2, COLS / 2 - 14);
        print_border(28, 0);
        mvprintw(LINES / 2 - 3, COLS / 2 - str.length() / 2, str.c_str());
        move(LINES / 2 - 4, COLS / 2 - 14);
        print_border(28, 1);
        mvprintw(LINES / 2 + 2, 18 - ncurse.length() / 2, ncurse.c_str());
        mvprintw(LINES / 2 + 2, COLS - 15 - sfml.length() / 2, sfml.c_str());
        mvprintw(LINES / 2 + 2, COLS / 2 - sdl.length() / 2, sdl.c_str());
        if (a == KEY_RIGHT)
            status++;
        if (a == KEY_LEFT)
            status--;
        if (status >= 10)
            status = 1;
        if (status <= 0)
            status = 9;
        if (status == 1 || status == 4 || status == 7) {
            attron(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, 18 - ncurse.length() / 2, ncurse.c_str());
            attroff(COLOR_PAIR(9));
        } if (status == 2 || status == 5 || status == 8) {
            attron(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, COLS / 2 - sdl.length() / 2, sdl.c_str());
            attroff(COLOR_PAIR(9));
        } if (status == 3 || status == 6 || status == 9) {
            attron(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, COLS - 15 - sfml.length() / 2, sfml.c_str());
            attroff(COLOR_PAIR(9));
        }
        refresh();
    }
    if (status == 1 || status == 4 || status == 7)
        return Arcade::PROTO::NCRUSES;
    if (status == 2 || status == 5 || status == 8)
        return Arcade::PROTO::SDL;
    return Arcade::PROTO::SFML;
}

Arcade::PROTO choose_game_page(std::string name)
{
    std::string str = "|  CHOOSE A GAME  |";
    std::string str2= "";
    std::string nibbler = "NIBBLER";
    std::string pacman = "PACMAN";
    int status = 1;

    for (int a = 'z'; a != 10; a = getch()) {
        clear();
        attron(COLOR_PAIR(2));
        box(stdscr, '?', '?');
        attroff(COLOR_PAIR(2));
        mvprintw(3, COLS / 2 - name.length() / 2 - 1, name.c_str());
        move(LINES / 2 - 2, COLS / 2 - 9);
        print_border(19, 0);
        mvprintw(LINES / 2 - 3, COLS / 2 - str.length() / 2, str.c_str());
        move(LINES / 2 - 4, COLS / 2 - 9);
        print_border(19, 1);
        if (a == KEY_RIGHT || a == KEY_LEFT)
            status++;
        if (status % 2 == 0) {
            attron(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, 20, nibbler.c_str());
            attroff(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, COLS - 27, pacman.c_str());
        } else {
            attron(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, COLS - 27   , pacman.c_str());
            attroff(COLOR_PAIR(9));
            mvprintw(LINES / 2 + 2, 20, nibbler.c_str());
        }
        refresh();
    }
    if (status % 2 == 0)
        return Arcade::PROTO::NIBBLER;
    return Arcade::PROTO::PACMAN;

}

std::tuple<Arcade::PROTO, Arcade::PROTO> NCURSE::my_menu()
{
    // if (stdscr != nullptr)
    //     init();
    std::string name = "How can I call you my boy ?";
    std::string player_name = "";
    char a;
    Arcade::PROTO game = Arcade::PROTO::PACMAN;
    Arcade::PROTO graphic = Arcade::PROTO::NCRUSES;

    timeout(9999999);
    for (a = ' '; a != 10; a = getch()) {
        clear();
        attron(COLOR_PAIR(2));
        box(stdscr, '|', '-');
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(9));
        mvprintw(2, COLS / 2 - std::strlen("            ") / 2, "            ");
        mvprintw(3, COLS / 2 - std::strlen("   ARCADE   ") / 2, "   ARCADE   ");
        mvprintw(4, COLS / 2 - std::strlen("            ") / 2, "            ");
        attroff(COLOR_PAIR(9));
        mvprintw(LINES / 2 - 3, COLS / 2 - std::strlen("Welcome") / 2, "Welcome");
        mvprintw(LINES / 2 - 1, COLS / 2 - name.length() / 2, name.c_str());
        player_name.push_back(a);
        attron(COLOR_PAIR(2));
        mvprintw(LINES / 2 + 3, COLS / 2 - player_name.length() / 2, player_name.c_str());
        attroff(COLOR_PAIR(2));
        refresh();
    }
    this->_name = player_name;
    game = choose_game_page(_name);
    graphic = choose_lib_page(_name);
    this->_game = game;
    this->_graphic = graphic;
    lets_play(game);
    endwin();

    return std::make_tuple(game, graphic);
}


void NCURSE::init()
{
    initscr();
    noecho();
    curs_set(0);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);

    init_pair(6, COLOR_BLACK, COLOR_GREEN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
    init_pair(8, COLOR_BLACK, COLOR_RED);
    init_pair(9, COLOR_BLACK, COLOR_YELLOW);

    init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(11, COLOR_BLUE, COLOR_BLUE);
    init_pair(12, COLOR_BLUE, COLOR_BLUE);
    init_pair(13, COLOR_RED, COLOR_RED);
    init_pair(14, COLOR_GREEN, COLOR_GREEN);
    timeout(200);
    keypad(stdscr, TRUE);
    clear();
}

void NCURSE::refreshh()
{
};

void NCURSE::clearr()
{
};

void NCURSE::window_handler()
{
}

Arcade::PROTO NCURSE::get_lib_name()
{
    return Arcade::PROTO::NCRUSES;
}
