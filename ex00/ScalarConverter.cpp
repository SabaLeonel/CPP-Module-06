#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) 
{
    std::cout << "Default constructor called" << std::endl;
}


void ScalarConverter::toChar(char litteral)
{
    std::cout << "char: " << litteral << std::endl;
    std::cout << "int: " << static_cast<int>(litteral[0]) << std::endl;
    std::cout << "float: " << static_cast<float>(litteral[0]) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(litteral[0]) << ".0" << std::endl;
}

void ScalarConverter::toInt(int litteral)
{
    try 
    {
        if (litteral < std::numeric_limits<char>::min() || litteral > std::numeric_limits<char>::max())
            throw std::exception();
        
        std::cout << "char: " << static_cast<char>(i) << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
    }catch (std::exception &e) {
        std::cout << "impossible" << std::endl;
    }
}

void ScalarConverter::toFloat(float litteral)
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

void ScalarConverter::toDouble(double litteral)
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


bool ScalarConverter::isChar(std::string litteral)
{
    if (litteral.empty()) 
		return false;
	if (litteral.length() == 1 && std::isprint(litteral[0]) && !std::isdigit(litteral[0]))
		return true;
	if (litteral.length() == 3 && litteral[0] == '\'' && litteral[2] == '\'')
	{
		if (std::isprint(litteral[1]) && !std::isdigit(litteral[1]))
			return true;
	}
	return false;
}

bool ScalarConverter::isInt(std::string litteral)
{
    if (litteral.empty()) 
        return false;
    if (litteral.length() == 1 && std::isdigit(litteral[0]))
        return true;
    if (litteral.length() > 1 && (litteral[0] == '+' || litteral[0] == '-'))
    {
        if (std::isdigit(litteral[1]))
            return true;
    }
    return false;
}

bool ScalarConverter::isDouble(std::string litteral)
{
    if (str.empty()) 
        return false;
    if (str.length() == 1 && std::isdigit(litteral[0]))
        return true;
    if (str.length() > 1 && (str[0] == '+' || str[0] == '-'))
    {
        if (std::isdigit(str[1]))
            return true;
    }
    if (str.length() > 2 && str[0] == '.' && std::isdigit(str[1]))
        return true;
    if (str.length() > 2 && (str[0] == '+' || str[0] == '-') && str[1] == '.' && std::isdigit(str[2]))
        return true;
    return false;
}




void ScalarConverter::convert(std::string const &str)
{
    if (str.length() == 1 && !std::isprint(str[0]))
        toChar(str);
    else if (isInt(str))
        toInt(str);
    else if (isFloat(str))
        toFloat(str);
    else if (isDouble(str))
        toDouble(str);
    else
        std::cout << "It's impossible to convert" << std::endl;
}

