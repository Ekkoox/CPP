#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

class Serialization
{
    private :
        Serialization();
        Serialization(const Serialization &src);
        ~Serialization();
        Serialization &operator=(const Serialization &rhs);

    public :
        static uintptr_t  serialize(Data* ptr);
        static Data*      deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif