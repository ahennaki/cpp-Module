#include "ScavTrap.hpp"

int main()
{
	// ClapTrap clap1("CLAP");

	// ClapTrap clap2(clap1);

	// ClapTrap clap3;
	// clap3 = clap1;

	// std::cout << std::endl;
	// clap1.attack("HIM");
	// clap1.takeDamage(5);
	// clap1.beRepaired(3);

	// std::cout << std::endl;
	ScavTrap *scav = new ScavTrap("SCAV");
	(*scav).ClapTrap::attack("scavt");
	(*scav).attack("scavt");
	(*scav).takeDamage(5);
	(*scav).beRepaired(3);
	(*scav).guardGate();

	delete scav;

	return 0;
}
