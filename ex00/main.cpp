#include "ScalarConverter.hpp"

int main(int argc, char **av)
{
    if (argc != 2)
    {
        std::cout << "usage: ./convert [string]" << std::endl;
        return (1);
    }

    ScalarConverter::convert(av[1]);
    return (0);
}
