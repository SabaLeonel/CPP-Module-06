#include "Ident.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(void)
{
	std::cout << "Base instanciated" << std::endl;
}

Base::~Base(void)
{
	std::cout << "Base destroyed" << std::endl;
}


Base *Base::generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;

    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void Base::identify_from_pointer(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void Base::identify_from_reference(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "C" << std::endl;
}

