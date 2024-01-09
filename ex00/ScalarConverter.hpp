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
        ScalarConverter(std::string const &str);
        ScalarConverter(ScalarConverter const &other);
        ~ScalarConverter(void);
        ScalarConverter	&operator=(ScalarConverter const &other);
        void	convert(void);
        void	convertChar(void);
        void	convertInt(void);
        void	convertFloat(void);
        void	convertDouble(void);

        std::string const	_str;
        char				_char;
        int					_int;
        float				_float;
        double				_double;
        bool				_isChar;
        bool				_isInt;
        bool				_isFloat;
        bool				_isDouble;


    private:
        ScalarConverter(void);
};

#endif
