#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

#define TYPE_DOUBLE 0
#define TYPE_FLOAT 1
#define TYPE_CHAR 2
#define TYPE_INT 3
#define TYPE_INVALID 4
// enum Type { TYPE_DOUBLE, TYPE_FLOAT, TYPE_CHAR, TYPE_INT, TYPE_INVALID };

struct Values
{
    char c;
    int i;
    float f;
    double d;
};

class ScalarConverter
{
    public:
        static void convert(const std::string &literal);
};

#endif