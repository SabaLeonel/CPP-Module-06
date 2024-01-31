# ifndef IDENT_HPP
# define IDENT_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
    private:

    public:
        virtual ~Base() {};
        Base() {};
        Base *generate(void);
        void identify_from_pointer(Base *p);
        void identify_from_reference(Base &p);
};




#endif