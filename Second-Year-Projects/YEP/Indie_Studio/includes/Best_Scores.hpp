/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-antoine.gavira-bottari
** File description:
** best_Scores
*/

#ifndef BEST_SCORES_HPP_
#define BEST_SCORES_HPP_

    #include <vector>
    #include "Parser.hpp"

class Best_Scores
{
    public:
        Best_Scores(std::map<std::string, double> scores);
        ~Best_Scores();

        void write_in_JSON();
    private:
        void write_player(std::ofstream &ofs, double const score, std::string const &place, bool const last);
        std::vector<double> in_order();
        void open_bracket(std::ofstream &);
        void close_bracket(std::ofstream &);
        void close_next_bracket(std::ofstream &);
        void specific_thing(std::ofstream &, std::string const &);
        //void ()
        std::map<std::string, double> _scores;
};

#endif /* !BEST_SCORES_HPP_ */
