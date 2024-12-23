#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string& input)
{
    double value;

    if (isSpecial(input))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (input == "-inff" || input == "-inf")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else if (input == "+inff" || input == "+inf")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;
    }
    try
    {
        //single char
        if (input.size() == 1 && !std::isdigit(input[0]))
        {
            value = static_cast<double>(input[0]);
            printScalar(value);
            return;
        }
        if (!isValidNum(input)) // check if valid number after 1 char
        {
            std::cerr << "Invalid input" << std::endl;
            return;
        }
        // float
        else if (input.find('f') != std::string::npos)
        {
            value = std::stof(input);
            printScalar(value);
            return;
        }
        else
        {
            value = std::stod(input);
            printScalar(value);
        }
    }
    catch(...)
    {
        std::cerr << "Invalid input" << std::endl;
        return;
    }
}

// some way to check if the input is a valid number
bool ScalarConverter::isValidNum(const std::string& input)
{
    size_t fcount = 0;
    for (size_t i = 0; i <input.size(); i++)
    {
        if (std::isalpha(input[i]))
        {
            if (input[i] == 'f' && i == input.size() - 1)
                fcount++;
            else
                return false; 
        }
    }
    return fcount <= 1;
}

bool ScalarConverter::isSpecial(const std::string& input)
{
    return input == "nan" || input == "+inf" || input == "-inf"
            || input == "+inff" || input == "-inff";
}

void ScalarConverter::printScalar(double value)
{
    // Print char
    std::cout << "char: ";
    if (std::isnan(value) || value < 32 || value > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    // Print int
    std::cout << "int: ";
    if (std::isnan(value) || value < static_cast<double>(std::numeric_limits<int>::min()) || value > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    // Print float
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    
    // Print double
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}