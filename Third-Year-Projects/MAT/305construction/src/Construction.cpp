/*
** EPITECH PROJECT, 2022
** 305construction
** File description:
** Construction
*/

#include <unistd.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <array>
#include "Error.hpp"
#include "Construction.hpp"

Construction::Construction()
{
}

Construction::~Construction()
{
}

void Construction::print_usage()
{
    for (const std::string &usg : _USAGE) {
        std::cout << usg << std::endl;
    }
}

std::vector<std::vector<std::string>> Construction::handlePaths(std::string name, std::string elem, std::vector<std::string> paths = {})
{
    paths.emplace_back(name);
    if (name == elem)
        return {paths};
    bool ok = false;
    for (const auto &[ch, _] : this->_content) {
        if (name == ch)
            ok = true;
    }
    if (ok == false)
        return {};
    std::vector<std::vector<std::string>> llpaths;
    std::vector<std::string> prerequisites;
    for (const auto &[ch, content] : this->_content) {
        if (name == ch)
            prerequisites = content->getPrerequisites();
    }
    for (std::size_t i = 0; i < prerequisites.size(); i++) {
        ok = false;
        for (const auto &ch : paths) {
            if (prerequisites[i] == ch)
                ok = true;
        }
        if (ok == false) {
            std::vector<std::vector<std::string>> tmp = this->handlePaths(prerequisites[i], elem, paths);
            for (std::size_t j = 0; j < tmp.size(); j++)
                llpaths.emplace_back(tmp[j]);
        }
    }
    return llpaths;
}

void printvec(std::vector<std::string> vector)
{
    std::cout << "\nSTART OF PRINT\n";
    for (std::size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << "-";
    }
    std::cout << "\nEND OF PRINT\n";
}

uint64_t Construction::durationFormula(std::string name)
{
    uint64_t duration = 0;
    std::vector<std::vector<std::string>> _paths;

    for (const auto &elem : this->_names) {
        _paths = this->handlePaths(name, elem);
    }
    for (std::size_t i = 0; i < _paths.size(); i++) {
        uint64_t temporary = 0;
        for (std::size_t j = 1; j < _paths[i].size(); j++) {
            for (const auto &[name, content] : this->_content) {
                if (name == _paths[i][j])
                    temporary += content->getDuration();
            }
        }
        if (temporary > duration)
            duration = temporary;
    }
    return duration;
}

void Construction::compute()
{
    uint64_t total = 0;

    for (const auto &[name, content] : this->_content) {
        content->setInfo(durationFormula(name), 0);
        content->setInfo(content->getDuration() + content->getInfo(0), 1);
        if (content->getInfo(1) > total)
            total = content->getInfo(1);
    }
    for (const auto &_old : this->_content) {
        uint64_t duration = total;
        for (const auto &_new : this->_content) {
            bool ok = false;
            std::vector<std::string> prerequisites = _new.second->getPrerequisites();
            for (std::size_t i = 0; i < prerequisites.size(); i++) {
                if (prerequisites[i] == _old.first)
                    ok = true;
            }
            if (ok == true && duration > _new.second->getInfo(0))
                duration = _new.second->getInfo(0);
        }
        _old.second->setInfo(duration - _old.second->getInfo(1), 2);
    }
    std::cout << "Total duration of construction: " << total << (total == 1 ? " week" : " weeks") << std::endl << std::endl;
    std::vector<std::pair<std::string, std::array<uint64_t, 3>>> elements;
    for (const auto &[name, content] : this->_content) {
        elements.push_back({name, {content->getInfo(0), content->getDuration(), content->getInfo(2)}});
    }
    auto __sort = [&]() {
        for (std::size_t i = 0; i < elements.size() - 1; i++) {
            for (std::size_t j = 0; j < elements.size() - i - 1; j++) {
                if ((elements[j].second[0] > elements[j + 1].second[0])
                || (elements[j].second[0] == elements[j + 1].second[0] && elements[j].second[1] > elements[j + 1].second[1])
                || (elements[j].second[0] == elements[j + 1].second[0] && elements[j].second[1] == elements[j + 1].second[1] && elements[j].second[2] > elements[j + 1].second[2])) {
                    std::pair<std::string, std::array<uint64_t, 3>> tmp = elements[j];
                    elements[j] = elements[j + 1];
                    elements[j + 1] = tmp;
                }
            }
        }
    };
    __sort();
    for (const auto &elem : elements) {
        std::cout << elem.first << " must begin " << (elem.second[2] ? "between" : "at") << " t=" << elem.second[0] << (elem.second[2] ? " and t=" + std::to_string(elem.second[0] + elem.second[2]) : "") << std::endl;
    }
    std::cout << std::endl;
    for (const auto &elem : elements) {
        std::cout << elem.first << "\t" << "(" << elem.second[2] << ")" << "\t";
        for (std::size_t i = 0; i < elem.second[0]; i++)
            std::cout << " ";
        for (std::size_t i = 0; i < elem.second[1]; i++)
            std::cout << "=";
        std::cout << std::endl;
    }
}

int Construction::handle_file(const std::string filename)
{
    if (filename.empty()) {
        Error(std::cerr, "No file given");
        return STATUS_FAIL;
    }
    std::ifstream openFile;
    openFile.open(filename, std::ios::in);
    if (false == openFile.is_open()) {
        Error(std::cerr, std::strerror(errno));
        return STATUS_FAIL;
    }
    if (EXIT_ERROR_FUNCTION == access(filename.c_str(), F_OK)) {
        Error(std::cerr, std::strerror(errno));
        return STATUS_FAIL;
    }
    if (openFile.peek() == std::ifstream::traits_type::eof()) {
        Error(std::cerr, "Empty file");
        return STATUS_FAIL;
    }
    std::string line = "";
    while (std::getline(openFile, line)) {
        if (line.find(";") == std::string::npos) {
            Error(std::cerr, "[" + line + "] doesn't contain \";\"");
            return STATUS_FAIL;
        }
        std::vector<std::string> v_line = split(line, ";");
        if (v_line.size() < 3) {
            Error(std::cerr, "Bad line: " + line);
            return STATUS_FAIL;
        }
        if (v_line.size() < 4) {
            this->_names.emplace_back(v_line[0]);
        }
        std::vector<std::string> prerequisites;
        for (std::size_t i = 3; i < v_line.size(); i++)
            prerequisites.emplace_back(v_line[i]);
        for (const auto &[name, _] : this->_content) {
            if (v_line[0] == name) {
                Error(std::cerr, "Repeated task.");
                return STATUS_FAIL;
            }
        }
        this->_content.emplace_back(std::make_pair(v_line[0], new Task(v_line[1], std::stoul(v_line[2]), prerequisites)));
    }
    try {
        this->compute();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        exit(0);
    }
    return STATUS_SUCCESS;
}
