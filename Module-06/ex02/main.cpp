#include <iostream>

class Base {public: virtual ~Base(){}};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate(void)
{
    int	rd;

    rd = std::rand() % 3;
    switch (rd)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
        default:
            return (NULL);
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        static_cast<void>(a);
    }
    catch(const std::bad_cast &e){}
    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        static_cast<void>(b);
    }
    catch(const std::bad_cast &e){}
    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        static_cast<void>(c);
    }
    catch(const std::bad_cast &e){}
}

int main()
{
    // std::srand(static_cast<unsigned>(std::time(NULL)));
    Base* a = generate();
    Base* b = generate();
    Base* c = generate();

    std::cout << "a* = ";
    identify(a);
    std::cout << "a& = ";
    identify(*a);

    std::cout << "b* = ";
    identify(b);
    std::cout << "b& = ";
    identify(*b);

    std::cout << "c* = ";
    identify(c);
    std::cout << "c& = ";
    identify(*c);

    delete a;
    delete b;
    delete c;

    return (0);
}
