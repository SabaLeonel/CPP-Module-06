#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <limits>
#include <regex>
# include <cmath>

class ScalarConverter
{
    public:
        void convert(std::string const &litteral);
    private:
        ScalarConverter(void);
        static void toChar(std::string litteral);
        static void toInt(std::string litteral);
        static void toFloat(std::string litteral);
        static void toDouble(std::string litteral);
};

#endif
