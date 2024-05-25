/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** Best_Scores
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include "Core.hpp"
#include "Textures.hpp"
#include "Button.hpp"
#include "IDisplay.hpp"
#include "PlayerSettings.hpp"
#include "Best_Scores.hpp"

Best_Scores::Best_Scores(std::map<std::string, double> scores) : _scores(scores)
{
    //for (auto i : scores)
    //    std::cout << i.first << " " << i.second << std::endl;
}

Best_Scores::~Best_Scores()
{
}

void Best_Scores::write_player(std::ofstream &ofs, double const score, std::string const &place, bool const last)
{
    specific_thing(ofs, "\"" + place + "\": ");
    open_bracket(ofs);
    specific_thing(ofs, "\"lifespan\": ");
    specific_thing(ofs, "\"" + std::to_string(score) + "\"\n");
    if (last)
        close_bracket(ofs);
    else
        close_next_bracket(ofs);
}

void Best_Scores::write_in_JSON()
{
    std::ofstream ofs("../config/scores.json", std::ofstream::trunc);
    std::vector<double> sorted = in_order();
    int x = 0;
    std::string tmp;

    open_bracket(ofs);
    specific_thing(ofs, "\"scores\": ");
    open_bracket(ofs);
    for (auto i : sorted) {
        if (x == 0)
            tmp = "first";
        if (x == 1)
            tmp = "second";
        if (x == 2)
            tmp = "third";
        if (x == 3)
            tmp = "fourth";
        if (x != 3)
            write_player(ofs, i, tmp, false);
        else
            write_player(ofs, i, tmp, true);
        x++;
    }
    close_bracket(ofs);
    close_bracket(ofs);
}

std::vector<double> Best_Scores::in_order()
{
    std::vector<double> ordered;

    for (auto i : _scores)
        ordered.push_back(i.second);
    std::sort(ordered.begin(), ordered.end(), std::greater<double>());
    return ordered;
    //ordered.emplace_back(_scores[]);
}

void Best_Scores::open_bracket(std::ofstream &ofs)
{
    ofs << "{\n";
}

void Best_Scores::close_bracket(std::ofstream &ofs)
{
    ofs << "}\n";
}

void Best_Scores::specific_thing(std::ofstream &ofs, std::string const &str)
{
    ofs << str;
}

void Best_Scores::close_next_bracket(std::ofstream &ofs)
{
    ofs << "},\n";
}