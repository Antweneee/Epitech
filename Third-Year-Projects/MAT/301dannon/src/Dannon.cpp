/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-301dannon-antoine.gavira-bottari
** File description:
** Dannon
*/

#include <unistd.h>
#include <cerrno>
#include <cmath>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <iterator>
#include "Error.hpp"
#include "Dannon.hpp"

Dannon::Dannon(std::string file) : _file(file)
{
    //_list = {2, 12, 24, 432, 34.4, 21.01, 22, 1, 32, 11.1, 22.2, 34.3, 3234, 4444, 2, 4, 25};
}

Dannon::~Dannon()
{
}

int Dannon::compute()
{
    std::cout << _elements.size() << " ";
    if (_elements.size() == 1)
        std::cout << "element" << std::endl;
    else
        std::cout << "elements" << std::endl;
    this->Selection_sort();
    this->Insertion_sort();
    this->Bubble_sort();
    this->Quick_sort();
    this->Merge_sort();
    return SUCCESS;
}

void Dannon::Selection_sort()
{
    int comparisons = 0;
    std::vector<float> temp_elements = _elements;

    for (size_t j = 0; j < temp_elements.size(); j++) {
        int min = j;
        for(size_t i = j + 1; i < temp_elements.size(); i++) {
            comparisons++;
            if(temp_elements[i] < temp_elements[min]) {
                min = i;
            }
        }
        std::swap(temp_elements[j], temp_elements[min]);
    }
    std::cout << "Selection sort: " << comparisons;
    if (comparisons == 1)
        std::cout << " comparison" << std::endl;
    else
        std::cout << " comparisons" << std::endl;
}

void Dannon::Insertion_sort()
{
    uint64_t comparisons = 0;
    std::vector<float> copy = this->_elements;

    for (std::size_t i = 1; i < copy.size(); i += 1) {
        uint32_t j = i;
        while (j > 0)
        {
            comparisons++;
            if (copy[j - 1] <= copy[j]) {
                float tmp = copy[j];
                copy[j] = copy[j - 1];
                copy[j - 1] = tmp;
                j -= 1;
            } else
                break;
        }
    }
    std::cout << "Insertion sort: " << comparisons << (comparisons == 1 ? " comparison" : " comparisons") << std::endl;
}

void Dannon::Bubble_sort()
{
    float tmp = 0;
    int comparisons = 0;
    std::vector<float> temp_elements = _elements;

    for (size_t i = 0; i < temp_elements.size(); i++) {
        for (size_t j = i + 1; j < temp_elements.size(); j++) {
            comparisons++;
            if (temp_elements[j] < temp_elements[i]) {
                tmp = temp_elements[i];
                temp_elements[i] = temp_elements[j];
                temp_elements[j] = tmp;
            }
        }
    }
    std::cout << "Bubble sort: " << comparisons;
    if (comparisons == 1)
        std::cout << " comparison" << std::endl;
    else
        std::cout << " comparisons" << std::endl;
}

static std::tuple<std::vector<float>, uint64_t> quick(std::vector<float> &elements, uint64_t &total)
{
    uint64_t comparisons = 0;

    if (elements.size() <= 1) {
        return std::make_tuple(elements, comparisons);
    }
    float pivot = elements[0];
    std::vector<float> left;
    std::vector<float> right;
    for (std::size_t i = 1; i < elements.size(); i += 1) {
        comparisons += 1;
        if (elements[i] < pivot) {
            left.emplace_back(elements[i]);
        } else {
            right.emplace_back(elements[i]);
        }
    }
    total += comparisons;
    auto [_left, lcompt] = quick(left, total);
    auto [_right, rcompt] = quick(right, total);
    comparisons += lcompt + rcompt;
    _left.emplace_back(pivot);
    _left.insert(_left.end(), _right.begin(), _right.end());
    return std::make_tuple(_left, comparisons);
}

void Dannon::Quick_sort()
{
    uint64_t comparisons = 0;
    std::vector<float> copy = this->_elements;

    quick(copy, comparisons);
    std::cout << "Quicksort: " << comparisons << (comparisons == 1 ? " comparison" : " comparisons") << std::endl;
}

static void merge(std::vector<float> &elements, uint64_t &comparisons)
{
    if (elements.size() > 1) {
        uint64_t ln = (elements.size() / 2);
        std::vector<float> left;
        for (std::size_t i = 0; i < ln; i++)
            left.emplace_back(elements[i]);
        std::vector<float> right;
        for (std::size_t i = ln; i < elements.size(); i++)
            right.emplace_back(elements[i]);
        merge(left, comparisons);
        merge(right, comparisons);
        uint64_t i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size())
        {
            comparisons++;
            if (left[i] < right[j]) {
                elements[k] = left[i];
                i += 1;
            } else {
                elements[k] = right[j];
                j += 1;
            }
            k += 1;
        }
        while (i < left.size())
        {
            elements[k] = left[i];
            i += 1;
            k += 1;
        }
        while (j < right.size())
        {
            elements[k] = right[j];
            j += 1;
            k += 1;
        }
    }
}

void Dannon::Merge_sort()
{
    uint64_t comparisons = 0;
    std::vector<float> copy = this->_elements;

    merge(copy, comparisons);
    std::cout << "Merge sort: " << comparisons << (comparisons == 1 ? " comparison" : " comparisons") << std::endl;
}

bool Dannon::isFloat(const std::string &s)
{
    std::istringstream iss(s);
    float f(0);

    iss >> std::noskipws >> f;
    return !iss.fail() && iss.eof();
}

std::vector<std::string> v_split(std::string s, const std::string delimiter)
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

void Dannon::manageFile()
{
    std::ifstream openFile;

    if (EXIT_ERROR_FUNCTION == access(this->_file.c_str(), F_OK)) {
        throw Error(std::cerr, std::strerror(errno));
    }
    openFile.open(this->_file, std::ios::in);
    if (false == openFile.is_open()) {
        throw Error(std::cerr, std::strerror(errno));
    }
    if (openFile.peek() == std::ifstream::traits_type::eof()) {
        throw Error(std::cerr, "Empty file");
    }
    std::string line = "";
    while (std::getline(openFile, line)) {
        std::vector<std::string> lv_line = v_split(line, _delimiters);
        for (std::size_t i = 0; i < lv_line.size(); i += 1) {
            if (false == this->isFloat(lv_line[i])) {
                throw Error(std::cerr, lv_line[i] + " is not a valid number.");
            }
            this->_elements.emplace_back(std::stof(lv_line[i]));
        }
    }
    this->compute();
}
