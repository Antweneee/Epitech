/*
** EPITECH PROJECT, 2022
** 305construction
** File description:
** Construction
*/

#ifndef CONSTRUCTION_HPP_
#define CONSTRUCTION_HPP_

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "Task.hpp"

#define STATUS_FAIL (-1)
#define STATUS_SUCCESS (0)
#define EXIT_ERROR (84)

const std::vector<std::string> _USAGE = {
    "USAGE",
    "\t./305construction file",
    "DESCRIPTION",
    "\tfile\tfile describing the tasks",
};

static inline std::vector<std::string> split(std::string s, const std::string delimiter = " ")
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

class Construction {
    public:
        Construction();
        ~Construction();

        void print_usage();
        int handle_file(const std::string filename = "");
        uint64_t durationFormula(std::string name);
        std::vector<std::vector<std::string>> handlePaths(std::string name, std::string elem, std::vector<std::string> paths);
        void compute();

    private:
        std::string _filename;
        std::vector<std::string> _names;
        std::vector<std::pair<std::string, Task *>> _content;
};

#endif /* !CONSTRUCTION_HPP_ */
