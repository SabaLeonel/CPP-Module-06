#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string const &str) : _str(str), _char(0), _int(0), _float(0), _double(0), _isChar(false), _isInt(false), _isFloat(false), _isDouble(false)
{
    return;
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) : _str(other._str), _char(other._char), _int(other._int), _float(other._float), _double(other._double), _isChar(other._isChar), _isInt(other._isInt), _isFloat(other._isFloat), _isDouble(other._isDouble)
{
    return;
}

ScalarConverter::~ScalarConverter(void)
{
    return;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
    this->_char = other._char;
    this->_int = other._int;
    this->_float = other._float;
    this->_double = other._double;
    this->_isChar = other._isChar;
    this->_isInt = other._isInt;
    this->_isFloat = other._isFloat;
    this->_isDouble = other._isDouble;
    this->_str = other._str;
    return (*this);
}

void ScalarConverter::convert(void)
{
    this->convertChar();
    this->convertInt();
    this->convertFloat();
    this->convertDouble();
    return;
}

void ScalarConverter::convertChar(void)
{
    if (this->_str.length() == 1 && !std::isdigit(this->_str[0]))
    {
        this->_char = this->_str[0];
        this->_isChar = true;
    }
    else if (this->_str.length() == 3 && this->_str[0] == '\'' && this->_str[2] == '\'' && !std::isdigit(this->_str[1]))
    {
        this->_char = this->_str[1];
        this->_isChar = true;
    }
    return;
}

void ScalarConverter::convertInt(void)
{
    if (this->_str.length() == 1 && std::isdigit(this->_str[0]))
    {
        this->_int = static_cast<int>(this->_str[0] - '0');
        this->_isInt = true;
    }
    else if (this->_str.length() > 1 && std::isdigit(this->_str[0]))
    {
        try
        {
            this->_int = std::stoi(this->_str);
            this->_isInt = true;
        }
        catch (std::exception const &e)
        {
            std::cerr << "int: impossible" << std::endl;
        }
    }
    return;
}

void ScalarConverter::convertFloat(void)
{
    if (this->_str.length() == 1 && std::isdigit(this->_str[0]))
    {
        this->_float = static_cast<float>(this->_str[0] - '0');
        this->_isFloat = true;
    }
    else if (this->_str.length() > 1 && std::isdigit(this->_str[0]))
    {
        try
        {
            this->_float = std::stof(this->_str);
            this->_isFloat = true;
        }
        catch (std::exception const &e)
        {
            std::cerr << "float: impossible" << std::endl;
        }
    }
    return;
}

void ScalarConverter::convertDouble(void)
{
    if (this->_str.length() == 1 && std::isdigit(this->_str[0]))
    {
        this->_double = static_cast<double>(this->_str[0] - '0');
        this->_isDouble = true;
    }
    else if (this->_str.length() > 1 && std::isdigit(this->_str[0]))
    {
        try
        {
            this->_double = std::stod(this->_str);
            this->_isDouble = true;
        }
        catch (std::exception const &e)
        {
            std::cerr << "double: impossible" << std::endl;
        }
    }
    return;
}

std::ostream &operator<<(std::ostream &os, ScalarConverter const &other)
{
    if (other._isChar)
    {
        os << "char: '" << other._char << "'" << std::endl;
        os << "int: " << static_cast<int>(other._char) << std::endl;
        os << "float: " << static_cast<float>(other._char) << ".0f" << std::endl;
        os << "double: " << static_cast<double>(other._char) << ".0" << std::endl;
    }
    else if (other._isInt)
    {
        os << "char: ";
        if (other._int >= 0 && other._int <= 127)
            os << "'" << static_cast<char>(other._int) << "'" << std::endl;
        else
            os << "Non displayable" << std::endl;
        os << "int: " << other._int << std::endl;
        os << "float: " << static_cast<float>(other._int) << ".0f" << std::endl;
        os << "double: " << static_cast<double>(other._int) << ".0" << std::endl;
    }
    else if (other._isFloat)
    {
        os << "char: ";
        if (other._float >= 0 && other._float <= 127)
            os << "'" << static_cast<char>(other._float) << "'" << std::endl;
        else
            os << "Non displayable" << std::endl;
        os << "int: ";
        if (other._float >= std::numeric_limits<int>::min() && other._float <= std::numeric_limits<int>::max())
            os << static_cast<int>(other._float) << std::endl;
        else
            os << "impossible" << std::endl;
        os << "float: " << other._float << "f" << std::endl;
        os << "double: " << static_cast<double>(other._float) << std::endl;
    }
    else if (other._isDouble)
    {
        os << "char: ";
        if (other._double >= 0 && other._double <= 127)
            os << "'" << static_cast<char>(other._double) << "'" << std::endl;
        else
            os << "Non displayable" << std::endl;
        os << "int: ";

        if (other._double >= std::numeric_limits<int>::min() && other._double <= std::numeric_limits<int>::max())
            os << static_cast<int>(other._double) << std::endl;
        else
            os << "impossible" << std::endl;

        os << "float: ";

        if (other._double >= std::numeric_limits<float>::min() && other._double <= std::numeric_limits<float>::max())
            os << static_cast<float>(other._double) << "f" << std::endl;
        else
            os << "impossible" << std::endl;

        os << "double: " << other._double << std::endl;

    }

    return (os);

}
