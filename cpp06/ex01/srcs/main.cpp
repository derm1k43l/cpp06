#include "Serializer.hpp"
#include <iostream>

int main()
{
    // create a Data object
    Data og;
    og.index = 42;
    og.string = "Mihai!";

    // store the addres of og in serialized and print it
    uintptr_t serialized = Serializer::serialize(&og);
    std::cout << "Serialized: " << serialized << std::endl;

    // turn back the serialized address into a Data* and print its members
    Data* deserialized = Serializer::deserialize(serialized);

    // check if the deserialized pointer points to the same address as og
    // since we took the address made it a type of int and turn back, this should be true
    if (deserialized == &og)
    {
        std::cout << "Deserialized successfully" << std::endl;
        std::cout << "Data.index: " << deserialized->index << std::endl;
        std::cout << "Data.string: " << deserialized->string << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed" << std::endl;
    }
    return 0;
}
