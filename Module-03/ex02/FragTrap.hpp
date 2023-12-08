#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& obj);
		~FragTrap();
		FragTrap &operator=(const FragTrap& obj);
		void highFivesGuys(void);
};

#endif