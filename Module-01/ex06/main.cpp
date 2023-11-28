#include "Harl.hpp"

bool isInputValid(const std::string& input)
{
	if (input != "DEBUG" && input != "INFO"
	&& input != "WARNING" && input != "ERROR")
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}
	return 1;
}

int main(int ac, char **av)
{
	Harl		harl;
	std::string	input;

	if (ac == 2)
	{
		input = av[1];
		if (input.empty() || !isInputValid(input))
			return 0;
		harl.complain(input);
	}
	return 0;
}