#include "Zombie.hpp"

int main()
{
    Zombie stackZombie("Stack Zombie");
    Zombie* heapZombie = newZombie("Heap Zombie");

    stackZombie.announce();
    heapZombie->announce();
    randomChump("Random Chump");
    delete heapZombie;
    return 0;
}