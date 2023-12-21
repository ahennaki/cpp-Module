#include "ClapTrap.hpp"

/*
Types of Inheritance:

Single Inheritance: A class is derived from only one base class.
Multiple Inheritance: A class is derived from more than one base class.
Multilevel Inheritance: A class is derived from another derived class.
*/

int main() {

    ClapTrap clap1("CLAP");

    ClapTrap clap2 = clap1;

    ClapTrap clap3;

    clap3 = clap1;

    (clap3).attack("Me");
    (clap3).takeDamage(5);
    (clap3).takeDamage(5);
    (clap3).beRepaired(3);

    return 0;
}