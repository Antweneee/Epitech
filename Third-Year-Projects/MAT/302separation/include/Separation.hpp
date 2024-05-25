/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-302separation-antoine.gavira-bottari
** File description:
** Separation
*/

#ifndef SEPARATION_HPP_
#define SEPARATION_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <utility>

enum Exit_states {
    FAILURE,
    SUCCESS,
};

const std::vector<std::string> _usage = {
    "USAGE\n",
    "\t./302separation file [n | p1 p2]\n",
    "DESCRIPTION\n",
    "file\tfile that contains the list of Facebook connections\n",
    "n\tmaximum length of the paths\n",
    "pi\tname of someone in the file\n",
};

static inline std::vector<std::string> split(std::string s, const std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

static inline void printgraph(const std::vector<std::vector<std::string>> graph)
{
    std::cout << "------- START OF PRINT -------------" << std::endl;
    for (std::size_t i = 0; i < graph.size(); i += 1) {
        for (std::size_t j = 0; j < graph[i].size(); j += 1) {
            std::cout << graph[i][j] << ";";
        }
        std::cout << std::endl;
    }
    std::cout << "------- END OF PRINT -------------" << std::endl;
}

static inline bool isDigit(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

class Separation {
    public:
        Separation(int ac, const char **av);
        ~Separation();
        void manageFile();
        int isInGraph(const std::string fst_name, const std::string snd_name);

    protected:
    private:
        void compute();
        void create_adjacency_matrix();
        void create_adjacency_correspondences();
        void floyd_warshall_algorithm();
        void print_vector(const std::vector<int> vect);

        std::string _filepath;
        int _maximum_length = (UINT16_MAX * 16);
        std::string _p1;
        std::string _p2;

        int _ac;

        std::vector<std::vector<std::string>> _tmp;

        std::map<int, std::string> _adjacency_correspondences;
        std::vector<std::vector<int>> _adjacency_matrix;
        std::vector<std::vector<int>> _shortest_path_matrix;
        std::vector<std::string> _vl_name;
        std::vector<std::vector<std::string>> _graph;
        std::vector<std::vector<int>> _vl_algo;
    private:
        void peopleList();
        void manageGraph();
    private:
        using func_method = void (Separation::*)();
        static const inline func_method func_ptr[] =
            {
                &Separation::peopleList,
                &Separation::manageGraph,
                &Separation::create_adjacency_correspondences,
                &Separation::create_adjacency_matrix,
                &Separation::floyd_warshall_algorithm,
            };
        void printMatrix();
        void printSeparation();
};

#endif /* !SEPARATION_HPP_ */
