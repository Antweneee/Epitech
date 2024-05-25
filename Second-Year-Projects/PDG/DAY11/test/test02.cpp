#include <criterion/criterion.h>
#include <iostream>
#include "../ex03/Toy.hpp"
#include "../ex03/Buzz.hpp"
#include "../ex03/Woody.hpp"

Test(ex02, test01)
{
    Buzz buzz("buzz");
    std ::cout << "buzz: " << buzz.getName() << std ::endl << buzz.getAscii() << std ::endl;
}