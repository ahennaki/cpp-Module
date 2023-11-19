#include "Zombie.hpp"

int main() {
    // Test the zombieHorde function
    int hordeSize = 5;
    Zombie* myHorde = zombieHorde(hordeSize, "Horde Zombie");

    // Announce each zombie in the horde
    for (int i = 0; i < hordeSize; ++i) {
        myHorde[i].announce();
    }

    // Clean up the zombie horde
    delete[] myHorde;

    return 0;
}