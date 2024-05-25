/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-305construction-antoine.gavira-bottari
** File description:
** Task
*/

#ifndef TASK_HPP_
#define TASK_HPP_

#include <string>
#include <vector>

class Task
{
private:
    std::string _name;
    std::vector<std::string> _prerequisites;
    std::vector<uint64_t> _infos;
    uint64_t _duration;
public:
    Task(std::string name, uint64_t duration, std::vector<std::string> prerequisites);
    ~Task();
    std::string getName() const { return this->_name; };
    std::vector<std::string> getPrerequisites() const { return this->_prerequisites; };
    uint64_t getDuration() const { return this->_duration; };
    uint64_t getInfo(int index) const { return this->_infos[index]; };
    void setDuration(uint64_t duration) { this->_duration = duration; };
    void setInfo(uint64_t info, int index) { this->_infos[index] = info; };
    void setName(std::string name) { this->_name = name; };
    void setPrerequisites(std::vector<std::string> prerequisites) { this->_prerequisites = prerequisites; };
};

#endif /* !TASK_HPP_ */
