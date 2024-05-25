/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD12-antoine.gavira-bottari
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template <typename T>
void swap(T &a, T &b)
{
    T c = b;
    b = a;
    a = c;
}
template<typename T>
T min(T a, T b)
{
    if (b < a)
        return b;
    return a;
}
template<typename T>
T max(T a, T b)
{
    if (b < a)
        return a;
    return b;
}
template<typename T>
T clamp(T val, T a, T b)
{
    if (val < a)
        return a;
    else if (val < b)
        return val;
    else
        return b;
}

#endif /* !ALGORITHM_HPP_ */
