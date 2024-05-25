/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-303make-antoine.gavira-bottari
** File description:
** Make
*/

#include <unistd.h>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include "Make.hpp"
#include "Error.hpp"

Make::Make(int ac, const char **av)
{
    for (int i = 1; i < ac; i++) {
        _params.emplace_back(av[i]);
    }
}

Make::~Make()
{
}

void Make::compute()
{
    for (const auto &fn : this->func_ptr) {
        (this->*fn)();
    }
}

void Make::sortGraph()
{
    std::sort(this->_graph.begin(), this->_graph.end(),
        [](const std::vector<std::string> &a, const std::vector<std::string> &b) {
            return a[0] < b[0];
    });
    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        std::sort(this->_graph[i].begin() + 1, this->_graph[i].end());
    }
}

ssize_t Make::nodePosition(const std::string node)
{
    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        if (this->_graph[i][0] == node)
            return i;
    }
    return -1;
}

void Make::createAdjacency()
{
    std::size_t n = this->_graph.size();
    std::vector<std::vector<int>> adjacency(n, std::vector<int>(n, 0));

    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        for (std::size_t j = 1; j < this->_graph[i].size(); j += 1) {
            ssize_t position = this->nodePosition(this->_graph[i][j]);
            if (position != -1)
                adjacency[i][position] = 1;
        }
    }
    this->_adjacency = adjacency;
}

void Make::printAdjacency()
{
    if (this->_params.size() == 2) return;
    for (std::size_t i = 0; i < this->_adjacency.size(); i += 1) {
        std::cout << "[";
        for (std::size_t j = 0; j < this->_adjacency[i].size(); j += 1)
            (j != this->_adjacency[i].size() - 1 ? std::cout << this->_adjacency[i][j] << " " : std::cout << this->_adjacency[i][j]);
        std::cout << "]" << std::endl;
    }
}

void Make::bfs()
{
    std::vector<std::string> findElem;
    std::vector<std::string> searchComplement;

    if (this->_params.size() != 2) return;
    this->getComplementarity(this->_params[1], searchComplement);
    for (const auto &elem : searchComplement) {
        this->getComplementarity(elem, searchComplement);
    }
    for (const auto &elem : searchComplement) {
        findElem.emplace_back(this->_complements.find(elem)->second);
    }
    std::sort(findElem.begin(), findElem.end());
    for (const auto &elem : findElem) {
        std::cout << elem << std::endl;
    }
}

void Make::dfs()
{
    if (this->_params.size() == 2) return;
    std::cout << std::endl;
    this->adjacency_order();
    this->find_executable();
    this->correspondances();

    //for (size_t i = 0; i < _correspondances.size(); i++) {
    //    for (auto &row : _correspondances[i]) {
    //        std::cout << _adjacency_order[i] << i << ": correpond: " << row << " "<< _adjacency_order[row] << "\t";
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;std::cout << std::endl;
    int x = 0;
    for (size_t i = 0; i < _correspondances.size(); i++) {
        for (auto const &j: _correspondances[i]) {
            if (x != 0) {
                multiple_correspondances(i, j);
                std::cout << std::endl;
            }
            dfs_algorithm(i);
            x++;
        }
        x = 0;
        _visited.clear();
        if (_correspondances[i].size() != 0)
        std::cout << std::endl;
    }
}

void Make::correspondances()
{
    for (size_t i = 0; i < _adjacency.size(); i++) {
        for (size_t j = 0; j < _adjacency.size(); j++) {
            if (_adjacency[i][j] == 1) {
                _correspondances[i].push_back(j);
            }
        }
    }
}

void Make::multiple_correspondances(int row, int pos)
{
    _visited[pos] = false;
    _visited[_executable_pos] = false;
}

void Make::dfs_algorithm(int pos)
{
    _visited[pos] = true;
    if (pos == _executable_pos) {
        std::cout << _adjacency_order[pos];
        return;
    } else {
        std::cout << _adjacency_order[pos] << " -> ";
    }

    std::list<int>::iterator i;
    for (i = _correspondances[pos].begin(); i != _correspondances[pos].end(); ++i) {
        if (_visited[_executable_pos] == true)
            break;
        if (!_visited[*i])
            dfs_algorithm(*i);
    }
}

bool Make::isInGraph(const std::string string)
{
    for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
        if (this->_graph[i][0] == string)
            return true;
    }
    return false;
}

void Make::handleGraph(const std::string parent_node, const std::string child_node)
{
    if (this->isInGraph(parent_node) == true) {
        for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
            for (std::size_t j = 0; j < this->_graph[i].size(); j += 1) {
                if (this->_graph[i][j] == parent_node && j == 0) {
                    this->_graph[i].emplace_back(child_node);
                }
            }
        }
    } else {
        if (this->isInGraph(child_node) == false)
            this->_graph.push_back({child_node});
        this->_graph.push_back({parent_node, child_node});
    }
}

bool Make::handleContent()
{
    for (std::size_t i = 0; i < this->_rules.size(); i += 1) {
        std::string variable = this->_rules[i];
        for (std::size_t j = 0; j < this->_rules.size(); j += 1) {
            if ((i != j) && (variable == this->_rules[j]))
                return true;
        }
    }
    for (const auto &[_, elements] : this->_dictionary) {
        for (std::size_t i = 0; i < elements.size(); i += 1) {
            std::string variable = elements[i];
            for (std::size_t j = 0; j < elements.size(); j += 1) {
                if ((i != j) && (variable == elements[j]))
                    return true;
            }
        }
    }
    if (this->_params.size() == 2) {
        std::string file = this->_params[1];
        for (std::size_t i = 0; i < this->_graph.size(); i += 1) {
            for (std::size_t j = 0; j < this->_graph[i].size(); j += 1) {
                if (file == this->_graph[i][j])
                    return false;
            }
        }
        return true;
    }
    return false;
}

void Make::getComplementarity(std::string key, std::vector<std::string> &values)
{
    for (const auto &[str, elements] : this->_dictionary) {
        for (const auto &elem : elements)
            if (key == elem)
                values.emplace_back(str);
    }
    std::sort(values.begin(), values.end());
}

void Make::manageFile()
{
    std::ifstream openFile;

    if (EXIT_ERROR_FUNCTION == access(this->_params[0].c_str(), F_OK)) {
        throw Error(std::cerr, std::strerror(errno));
    }
    openFile.open(this->_params[0], std::ios::in);
    if (false == openFile.is_open()) {
        throw Error(std::cerr, std::strerror(errno));
    }
    if (openFile.peek() == std::ifstream::traits_type::eof()) {
        throw Error(std::cerr, "Empty file");
    }
    std::string line;
    std::string binary;
    while (std::getline(openFile, line)) {
        if (line.find(":") == std::string::npos) {
            this->_complements.insert(std::pair<std::string, std::string>(binary, line));
            continue;
        }
        std::vector<std::string> line_v = split(line, "\t ");
        std::string child_node = line_v[0].substr(0, line_v[0].length() - 1);
        for (std::size_t i = 1; i < line_v.size(); i += 1) {
            this->handleGraph(line_v[i], child_node);
        }
        binary = child_node;
        line_v.erase(line_v.begin());
        this->_rules.emplace_back(child_node);
        this->_dictionary.insert(std::pair<std::string, std::vector<std::string>>(child_node, line_v));
    }
    if (true == this->handleContent()) {
        throw Error(std::cerr, "Error of inconsistent content / nonsensical arguments");
    }
    this->compute();
}

void Make::remove_occurences(std::vector<std::string> &vect, std::string &target)
{
    bool first_time = true;

    for (size_t i = 0; i < vect.size(); ++i) {
        if (vect[i].compare(target) == 0 && first_time == true) {
            first_time = false;
        } else if (vect[i].compare(target) == 0 && first_time == false) {
            vect.erase(vect.begin() + i);
        }
    }
}

void Make::adjacency_order()
{
    std::vector<std::string> tmp;

    for (size_t i = 0; i < _graph.size(); ++i) {
        for (size_t j = 0; j < _graph[i].size(); ++j) {
            tmp.emplace_back(_graph[i][j]);
        }
    }
    for (size_t i = 0; i < tmp.size(); ++i) {
        remove_occurences(tmp , tmp[i]);
    }
    std::sort(tmp.begin(), tmp.end());
    _adjacency_order = tmp;
}

void Make::find_executable()
{
    std::string tmp;

    for (size_t i = 0; i < _adjacency_order.size(); i++) {
        std::string temp = _adjacency_order[i];
        std::reverse(temp.begin(), temp.end());
        if (std::strncmp(temp.c_str(), "c.", 2) == 0) {
            continue;
        } else if (std::strncmp(temp.c_str(), "o.", 2) == 0) {
            continue;
        } else {
            std::reverse(temp.begin(), temp.end());
            tmp = temp;
            _executable_pos = i;
        }
    }
    _executable = tmp;
}

void Make::pretty_print()
{
    std::cout << std::endl;

    for (size_t i = 0; i < _adjacency_order.size(); i++) {
        if (_adjacency_order[i].compare(_executable) == 0)
            continue;
        for (size_t j = 0; j < _adjacency_order.size(); j++) {
            if (_adjacency[i][j] == 1) {
                std::cout << _adjacency_order[i] << " -> ";
                if (_adjacency_order[j] == _executable)
                    std::cout << _executable << std::endl;
                else
                    std::cout << _adjacency_order[j] << " -> " << _executable << std::endl;
            }
        }
    }
}