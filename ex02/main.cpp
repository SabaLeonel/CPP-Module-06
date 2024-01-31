#include "Ident.hpp"


int main (void)
{
    Base base;
    Base *ptr = base.generate();

    std::cout << std::endl << "Trying to indentify base from pointer"  << std::endl;
    base.identify_from_pointer(ptr);
    std::cout << std::endl << "Trying to indentify reference from pointer"  << std::endl;
    base.identify_from_reference(*ptr);
    return (0);
    
}