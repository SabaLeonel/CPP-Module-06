#include "Ident.hpp"


int main (void)
{
    Base base;
    Base *ptr = base.generate();


    base.identify_from_pointer(ptr);
    base.identify_from_reference(*ptr);
    return (0);
    
}