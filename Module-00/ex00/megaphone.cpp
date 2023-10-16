#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	int	i = 0;
	int	j = -1;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (++i < ac)
	{
		while (av[i] && av[i][++j])
			std::cout << (char) toupper(av[i][j]);
		j = -1;
	}
	std::cout << std::endl;
	return 0;
}