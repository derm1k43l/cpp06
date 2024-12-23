#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cfloat>
class ScalarConverter
{
    public:

        static void convert(const std::string& input);

    private:
        ScalarConverter();
        ~ScalarConverter();
        // delete copy constructor and assignment operator
        ScalarConverter(const ScalarConverter& other) = delete;
        ScalarConverter& operator=(const ScalarConverter& other) = delete;
    
        static bool isSpecial(const std::string& input);
        static bool isValidNum(const std::string& input);
        static void printScalar(double value);
};