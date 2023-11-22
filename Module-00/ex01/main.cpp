#include "phonebook.hpp"

static bool isInputValid(const std::string& input) {
	return input == "ADD" || input == "SEARCH" || input == "EXIT";
}

std::string getInput(void)
{
	std::string input;

	while (1)
	{
		std::cout << "		ENTER:" << std::endl;
		std::cout << "	'ADD' to add a contact." << std::endl;
		std::cout << "	'SEARCH' to search for a contact." << std::endl;
		std::cout << "	'EXIT' to exit the PhoneBook."  << std::endl << std::endl;
		std::cout << "PhoneBook> ";
		getline(std::cin, input);
		if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
        }
		if (!input.empty() && isInputValid(input))
			break;
		std::cin.clear();
		std::cout << "	INVALID INPUT!!" << std::endl << std::endl;
	}
	return input;
}

int main(int ac, char **av)
{
	PhoneBook phonebook;
	std::string input;

	(void)av;
	if (ac == 1)
	{
		std::cout << "		*WELCOME TO AENNAKI'S PHONEBOOK*" << std::endl << std::endl;
		while (1)
		{
			input = getInput();
			if (input == "ADD")
				phonebook.add();
			else if (input == "SEARCH")
				phonebook.search();
			else
			{
				std::cout << "EXIT" << std::endl;
				return 0;
			}
		}
	}
	return 0;
}
