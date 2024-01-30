#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <limits>
# include <sstream>
# include <cmath>

class ScalarConverter
{
    public:
        static void convert(std::string const &litteral);
    private:
        ScalarConverter(void);
        static void toSpecial(std::string litteral);
        static void toChar(std::string litteral);
        static void toInt(std::string litteral);
        static void toFloat(std::string litteral);
        static void toDouble(std::string litteral);
};

#endif
