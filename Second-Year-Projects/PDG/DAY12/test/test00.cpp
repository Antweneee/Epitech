/*
** EPITECH PROJECT, 2022
** B-PDG-300-PAR-3-1-PDGD10am-antoine.gavira-bottari
** File description:
** test
*/

#include <criterion/criterion.h>
#include <iostream>
#include "../Algorithm.hpp"
#include "../Array.hpp"

Test(ex00, test01)
{
    int a = 42;
    int b = 21;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min (a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max (a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp (0 , a, b) = " << ::clamp(0, a, b) << std::endl;
    std::string c = "ghi";
    std::string d = "abc";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min (c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max (c, d) = " << ::max(c, d) << std::endl;
    std::cout << "clamp (\" def \" , c, d) = " << ::clamp(std::string("def"), c, d) << std ::endl;
}

Test(ex00, test02)
{
    int a = 42;
    int b = 21;
    std::cout << "min (a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max (a, b) = " << ::max(a, b) << std::endl;
    std::cout << "clamp (0 , a, b) = " << ::clamp(0, a, b) << std::endl;
}

Test(ex01, test01)
{
        Array <int , 3 > array ;
    try {
        array [0] = 21;
        array [1] = 42;
        array [2] = 84;
        array [3] = 84;
    }
    catch ( const std :: exception & e ) {
        std::cout << e . what () << std::endl ;
    }
    std::cout << array << std::endl ;
    array
    .convert<float>([](const int &v) {return static_cast <float >( v ) / 10.f;})
    .forEach([](const float &v) { std :: cout << v << std::endl;});
}