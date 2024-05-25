/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-305construction-antoine.gavira-bottari
** File description:
** Task
*/

#include "Task.hpp"

Task::Task(std::string name, uint64_t duration, std::vector<std::string> prerequisites)
    : _name(name), _duration(duration), _prerequisites(prerequisites)
{
    for (std::size_t i = 0; i < 3; i++)
        _infos.emplace_back(0);
}

Task::~Task()
{
}
