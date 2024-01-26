#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) 
{
    std::cout << "Default constructor called" << std::endl;
}


void ScalarConverter::toChar(std::string litteral)
{
    std::cout << "char: " << litteral << std::endl;
    std::cout << "int: " << static_cast<int>(litteral[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(litteral[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(litteral[0]) << ".0" << std::endl;
}

void ScalarConverter::toInt(std::string litteral)
{
    int i = std::stoi(litteral);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (litteral == "nan" || litteral == "-inf" || litteral == "+inf" || litteral == "nanf" || litteral == "-inff" || litteral == "+inff")
        std::cout << "char: impossible" << std::endl;
    else if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;    
}

void ScalarConverter::toFloat(std::string litteral)
{

    
}

void ScalarConverter::toDouble(std::string litteral)
{
    try
    {
        if (litteral < std::numeric_limits<char>::min() || litteral > std::numeric_limits<char>::max())
            throw std::exception();
        std::cout << "char: " << static_cast<char>(i) << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


enum Type{
    Char,
    Int,
    Float,
    Double,
    Invalid
};

static Type checkType(std::string const &litteral)
{
    if (litteral.length() == 3 && litteral[0] == '\'' && litteral[2] == '\'')
        return Char;
    if (std::regex_match(litteral, std::regex("[-+]?[0-9]+")))
        return Int;
    if (std::regex_match(litteral, std::regex("[-+]?[0-9]+.[0-9]+")) || litteral == "nanf" || litteral == "+inff" || litteral == "-inff")
        return Double;
    if (std::regex_match(litteral, std::regex("[-+]?[0-9]+.[0-9]+f")) || litteral == "nan" || litteral == "+inf" || litteral == "-inf")
        return Float;
    return Invalid;
}


void ScalarConverter::convert(std::string const &litteral)
{
    switch (checkType(litteral))
    {
        case Char:
            toChar(litteral);
            break;
        case Int:
            toInt(litteral);
            break;
        case Float:
            toFloat(litteral);
            break;
        case Double:
            toDouble(litteral);
            break;
        default:
            std::cout << "Error: Invalid type" << std::endl;
            break;
    }
}


// static void ScalarConverter::convert(std::string const &litteral)
// {
//     if (litteral.length() == 1 && !std::isprint(litteral[0]))
//         toChar(litteral);
//     else if (isInt(litteral))
//         toInt(litteral);
//     else if (isFloat(litteral))
//         toFloat(litteral);
//     else if (isDouble(litteral))
//         toDouble(litteral);
//     else
//         std::cout << "It's impossible to convert" << std::endl;
// }

