#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
# include <cmath>

class ScalarConverter
{
    public:
        static void convert(std::string const &str);
    private:
        ScalarConverter(void);
        static void toChar(char litteral);
        static void toInt(int litteral);
        static void toFloat(float litteral);
        static void toDouble(double litteral);

        static bool isChar(std::string litteral);
        static bool isInt(std::string litteral);
        static bool isFloat(std::string litteral);
        static bool isDouble(std::string litteral);
};

#endif
