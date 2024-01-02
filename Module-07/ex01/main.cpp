#include "iter.hpp"

class Awesome{

public:
    Awesome(void) : _n(42){}
    Awesome(int n) : _n(n) {}

    Awesome &operator= (Awesome &a) {_n = a._n; return *this;}

    bool operator>(Awesome &a) {return this->_n > a.get_n();}
    bool operator<(Awesome &a) {return this->_n < a.get_n();}

    int get_n() const {return _n;}

private:
    int _n;
};

std::ostream &operator << (std::ostream &o, const Awesome& a){o << a.get_n(); return o;}

template<typename T>
void print(T const &x) {std::cout << x << std::endl;}

int main( void )
{
    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter(tab, 5, print);
    iter(tab2, 5, print);
    return 0;
}