/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-302separation-antoine.gavira-bottari
** File description:
** Separation
*/

#include <unistd.h>
#include <cerrno>
#include <cstring>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include "Separation.hpp"
#include "Error.hpp"

Separation::Separation(int ac, const char **av)
    : _ac(ac)
{
    if (_ac == 3) {
        this->_filepath = av[1];
        if (!isDigit(av[2]))
            throw Error(std::cerr, "Maximum length of the paths isn't a valid number.");
        this->_maximum_length = std::stoi(av[2]);
    } else {
        this->_filepath = av[1];
        this->_p1 = av[2];
        this->_p2 = av[3];
    }
}

Separation::~Separation()
{
}

void Separation::create_adjacency_correspondences()
{
    for (size_t i = 0; i < _graph.size(); i++) {
        _adjacency_correspondences.emplace(std::pair<int, std::string>(i, _graph[i][0]));
    }
}

void Separation::print_vector(const std::vector<int> vect)
{
    for (size_t i = 0; i < vect.size(); i++)
        (i != vect.size() - 1 ? std::cout << vect[i] << " " : std::cout << vect[i] << std::endl);
}

void Separation::create_adjacency_matrix()
{
    for (size_t i = 0; i < _graph.size(); i++) {
        _adjacency_matrix.emplace_back();
        bool found = false;
        for (size_t j = 0; j < _graph.size(); j++) {
            if (j == i) {
                _adjacency_matrix[i].emplace_back(0);
                continue;
            }
            for (size_t k = 0; k < _graph[i].size(); k++) {
                if (_graph[i][k].compare(_adjacency_correspondences.at(j)) == 0) {
                    _adjacency_matrix[i].emplace_back(1);
                    found = true;
                    break;
                }
            }
            if (found == false)
                _adjacency_matrix[i].emplace_back(0);
            else
                found = false;
        }
    }
}

void Separation::floyd_warshall_algorithm()
{
    std::size_t n = this->_adjacency_matrix.size();
    std::size_t m = this->_adjacency_matrix[0].size();
    std::vector<std::vector<int>> vl_algo(n, std::vector<int>(m, (UINT16_MAX * 16)));

    for (std::size_t i = 0; i < n; i += 1) {
        for (std::size_t j = 0; j < n; j += 1) {
            if (this->_adjacency_matrix[i][j] > 0)
                vl_algo[i][j] = 1;
        }
        vl_algo[i][i] = 0;
    }
    for (std::size_t k = 0; k < n; k += 1) {
        for (std::size_t i = 0; i < n; i += 1) {
            for (std::size_t j = 0; j < n; j += 1) {
                if (vl_algo[i][j] > vl_algo[i][k] + vl_algo[k][j]) {
                    vl_algo[i][j] = vl_algo[i][k] + vl_algo[k][j];
                }
            }
        }
    }
    for (std::size_t i = 0; i < vl_algo.size(); i += 1) {
        for (std::size_t j = 0; j < vl_algo[i].size(); j += 1) {
            if (vl_algo[i][j] > this->_maximum_length)
                vl_algo[i][j] = 0;
        }
    }
    this->_vl_algo = vl_algo;
}

void Separation::compute()
{
    for (const auto &fn : this->func_ptr) {
        (this->*fn)();
    }
    this->_ac == 3 ? this->printMatrix() : this->printSeparation();
}

void Separation::printMatrix()
{
    for (const auto &name : this->_vl_name) {
        std::cout << name << std::endl;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < _adjacency_matrix.size(); i++) {
        print_vector(_adjacency_matrix[i]);
    }
    std::cout << std::endl;
    for (size_t i = 0; i < this->_vl_algo.size(); i++) {
        print_vector(this->_vl_algo[i]);
    }
}

void Separation::printSeparation()
{
    int degree = -2;
    int p1_position = 0;
    int p2_position = 0;

    for (std::size_t i = 0; i < this->_vl_name.size(); i += 1) {
        if (this->_vl_name[i] == this->_p1) {
            p1_position = i;
            degree += 1;
        }
        if (this->_vl_name[i] == this->_p2) {
            p2_position = i;
            degree += 1;
        }
    }
    if (degree == -1) {
        std::cout << "Degree of separation between " << this->_p1 << " and " << this->_p2 << ": " << degree << std::endl;
    } else {
        std::cout << "Degree of separation between " << this->_p1 << " and " << this->_p2 << ": "
            << this->_vl_algo[p1_position][p2_position] << std::endl;
    }
}

void Separation::peopleList()
{
    std::unordered_set<std::string> _uvl_list(this->_vl_name.begin(), this->_vl_name.end());
    this->_vl_name.assign(_uvl_list.begin(), _uvl_list.end());
    std::sort(this->_vl_name.begin(), this->_vl_name.end());
}

void Separation::manageGraph()
{
    std::sort(this->_graph.begin(), this->_graph.end(),
        [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
            return a[0] < b[0];
    });
    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        std::sort(this->_graph[i].begin() + 1, this->_graph[i].end());
    }
    //printgraph(this->_graph);
}

int Separation::isInGraph(const std::string fst_name, const std::string snd_name)
{
    int cnt = 0;

    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        for (std::size_t j = 0; j < this->_graph[i].size(); j += 1) {
            if (this->_graph[i][j] == fst_name && j == 0) {
                this->_graph[i].emplace_back(snd_name);
                cnt = cnt == 2 || cnt == 3 ? 3 : 1;
            }
            if (this->_graph[i][j] == snd_name && j == 0) {
                this->_graph[i].emplace_back(fst_name);
                cnt = cnt == 1 || cnt == 3 ? 3 : 2;
            }
        }
    }
    return cnt;
}

void Separation::manageFile()
{
    std::ifstream openFile;

    if (EXIT_ERROR_FUNCTION == access(this->_filepath.c_str(), F_OK)) {
        throw Error(std::cerr, std::strerror(errno));
    }
    openFile.open(this->_filepath, std::ios::in);
    if (false == openFile.is_open()) {
        throw Error(std::cerr, std::strerror(errno));
    }
    if (openFile.peek() == std::ifstream::traits_type::eof()) {
        throw Error(std::cerr, "Empty file");
    }
    std::string line;
    while (std::getline(openFile, line)) {
        if (line.find(" is friends with ") == std::string::npos) {
            throw Error(std::cerr, line + " doesn't contain \" is friends with \".");
        }
        std::vector<std::string> v_list = split(line, " is friends with ");
        this->_vl_name.emplace_back(v_list[0]);
        this->_vl_name.emplace_back(v_list[1]);
        int cnt = this->isInGraph(v_list[0], v_list[1]);
        if (cnt == 0) {
            this->_graph.push_back({v_list[0], v_list[1]});
            this->_graph.push_back({v_list[1], v_list[0]});
        }
        else if (cnt == 1)
            this->_graph.push_back({v_list[1], v_list[0]});
        else if (cnt == 2)
            this->_graph.push_back({v_list[0], v_list[1]});
        else
            continue;
    }
    this->compute();
}
