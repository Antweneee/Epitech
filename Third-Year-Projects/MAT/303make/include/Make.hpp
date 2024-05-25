/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-303make-antoine.gavira-bottari
** File description:
** Make
*/

#ifndef MAKE_HPP_
#define MAKE_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <sstream>

enum Exit_states {
    FAILURE,
    SUCCESS,
};

const std::vector<std::string> _usage = {
    "USAGE\n",
    "\t./303make makefile [file]\n",
    "DESCRIPTION\n",
    "\tmakefile\tname of the makefile\n",
    "\tfile\tname of a recently modified file\n",
};

static inline std::vector<std::string> split(std::string s, const std::string delimiter)
{
    std::stringstream sstream(s);
    std::string line;
    std::vector<std::string> r_vector = {};

    while (std::getline(sstream, line))  {
        std::size_t prev = 0, pos = 0;
        while ((pos = line.find_first_of(delimiter, prev)) != std::string::npos) {
            if (pos > prev) {
                r_vector.push_back(line.substr(prev, pos - prev));
            }
            prev = pos + 1;
        }
        if (prev < line.length()) {
            r_vector.push_back(line.substr(prev, std::string::npos));
        }
    }
    return r_vector;
}

static inline void printgraph(const std::vector<std::vector<std::string>> graph)
{
    std::cout << "------- START OF GRAPH PRINT -------------" << std::endl;
    for (std::size_t i = 0; i < graph.size(); i += 1) {
        for (std::size_t j = 0; j < graph[i].size(); j += 1) {
            std::cout << graph[i][j] << ";";
        }
        std::cout << std::endl;
    }
    std::cout << "------- END OF GRAPH PRINT -------------" << std::endl;
}

static inline void printmatrix(const std::vector<std::vector<int>> graph)
{
    std::cout << "------- START OF MATRIX PRINT -------------" << std::endl;
    for (std::size_t i = 0; i < graph.size(); i += 1) {
        for (std::size_t j = 0; j < graph[i].size(); j += 1) {
            std::cout << graph[i][j] << ";";
        }
        std::cout << std::endl;
    }
    std::cout << "------- END OF MATRIX PRINT -------------" << std::endl;
}

class Make {
    public:
        Make(int ac, const char **av);
        ~Make();
        void manageFile();
        bool isInGraph(const std::string string);
        void handleGraph(const std::string parent_node, const std::string child_node);
        ssize_t nodePosition(const std::string node);
        void getComplementarity(std::string key, std::vector<std::string> &values);
        bool handleContent();
        void compute();

    private:
        void remove_occurences(std::vector<std::string> &vect, std::string &target);
        void find_executable();
        void adjacency_order();
        void sortGraph();
        void createAdjacency();
        void printAdjacency();
        void pretty_print();
        void bfs();
        void dfs();
        void dfs_algorithm(int pos);
        void correspondances();
        void multiple_correspondances(int row, int pos);

        using func_method = void (Make::*)();
        static const inline func_method func_ptr[] =
        {
                &Make::sortGraph,
                &Make::createAdjacency,
                &Make::printAdjacency,
                &Make::bfs,
                &Make::dfs,
            };
    private:
        std::map<std::string, std::string> _complements;
        std::map<std::string, std::vector<std::string>> _dictionary;
        std::vector<std::string> _params;
        std::vector<std::string> _rules;
        std::vector<std::vector<int>> _adjacency;

        std::map<int ,bool> _visited;
        std::map<int, std::list<int>> _correspondances;

        std::vector<std::string> _adjacency_order;
        std::string _executable;
        int _executable_pos;
        std::vector<std::vector<std::string>> _graph;

};

#endif /* !MAKE_HPP_ */
