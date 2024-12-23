#pragma once
#include <iostream>
#include <cstdlib>

struct Data
{
    int             index;
    std::string     string;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer() = delete;
        Serializer(const Serializer& other) = delete;
        Serializer& operator=(const Serializer& other) = delete;
        ~Serializer() = delete;
};

