/*
** EPITECH PROJECT, 2022
** B-MAT-500-PAR-5-1-301dannon-antoine.gavira-bottari
** File description:
** Dannon
*/

#ifndef DANNON_HPP_
#define DANNON_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <iomanip>

enum Exit_states {
    FAILURE,
    SUCCESS,
};

const std::vector<std::string> _usage = {
    "USAGE\n",
    "\t./301dannon file\n",
    "DESCRIPTION\n",
    "\tfile\tfile that contains the numbers to be sorted, separated by spaces\n",
};

const std::string _delimiters = " [{(&~#$=|,;!?*+%_@)}]ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class Dannon {
    public:
        // * ctor and dtor of the Dannon class
        Dannon(std::string file);
        ~Dannon();

        // * public method of the Dannon class
        void manageFile();
        bool isFloat(const std::string &s);

    private:
        // * private method of the Dannon class
        void Selection_sort();
        void Insertion_sort();
        void Bubble_sort();
        void Quick_sort();
        void Merge_sort();

        // * Variable of the Dannon class
        std::string _file;
        std::vector<float> _elements;
        int compute();
};

#endif /* !DANNON_HPP_ */
