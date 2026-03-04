#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <cstdint>

typedef struct Data
{
    int nbr;
} Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif