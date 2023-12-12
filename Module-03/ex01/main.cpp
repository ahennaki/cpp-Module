#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap1("CLAP");

	ClapTrap clap2 = clap1;

	ClapTrap clap3;
	clap3 = clap1;

	clap1.attack("HIM");
	clap1.takeDamage(5);
	clap1.beRepaired(3);

	ScavTrap scav("SCAV");
	scav.attack("scavt");
	scav.takeDamage(5);
	scav.beRepaired(3);
	scav.guardGate();

	return 0;
}
