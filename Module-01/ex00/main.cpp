#include "Zombie.hpp"

int main() {
    // Allocate Zombie on the stack
    Zombie stackZombie("Stack Zombie");
    stackZombie.announce();

    // Allocate Zombie on the heap
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // Create a random chump on the stack
    randomChump("Random Chump");

    // Clean up the heap-allocated Zombie
    delete heapZombie;

    return 0;
}