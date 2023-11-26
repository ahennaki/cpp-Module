#include "Zombie.hpp"

int main()
{
    int hordeSize = 5;
    Zombie* myHorde = zombieHorde(hordeSize, "Horde Zombie");

    for (int i = 0; i < hordeSize; ++i)
    {
        myHorde[i].announce();
    }
    delete[] myHorde;
    return 0;
}