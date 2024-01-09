#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "usage: ./convert [string]" << std::endl;
        return (1);
    }
    ScalarConverter converter(argv[1]);
    converter.convert();
    return (0);
}