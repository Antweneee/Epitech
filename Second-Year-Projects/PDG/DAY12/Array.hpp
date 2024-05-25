/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD12-antoine.gavira-bottari
** File description:
** Array
*/

#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include <functional>

template<typename T, std::size_t Size>
class Array
{
    public:
        T _array[Size];
        size_t _size = Size;

        /******* Function *******/
        std::size_t size() const
        {
            return _size;
        }
        void forEach(const std::function<void(const T&)> &task) const
        {
            for (size_t i = 0; i < _size; ++i)
                task(_array[i]);
        }
        template <typename A>
        Array<A, Size> convert(const std::function <A(const T&)> &converter) const
        {
            Array<A, Size> cpy;
            for (size_t i = 0; i < _size; ++i)
                cpy[i] = converter(_array[i]);
            return cpy;
        }

        /******* Operator *******/
        T &operator[](std::size_t i)
        {
            (i >= _size ? throw std::out_of_range("Out of range") : 0);
            return _array[i];
        }
        const T &operator[](std::size_t i) const
        {
            (i >= _size ? throw std::out_of_range("Out of range") : 0);
            return _array[i];
        }
};

template <typename T, std::size_t Size>
std::ostream &operator<<(std::ostream &stream, const Array<T, Size> &array)
{
    stream << "[";
    for (size_t i = 0; i < array.size(); i++)
        (i + 1 == array._size ? stream << array._array[i] << "]" : stream << array._array[i] << ", ");
    return stream;
}

#endif /* !ARRAY_HPP_ */