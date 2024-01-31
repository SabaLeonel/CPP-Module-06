# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <limits>
# include <cmath>
# include <cstdint>


struct Data
{
    std::string s1;
    int n;
};

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer &operator=(Serializer const &rhs);
};

#endif