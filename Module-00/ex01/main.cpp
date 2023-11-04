#include "main.hpp"

static inline bool isInputValid(const std::string& input) {
    return input == "ADD" || input == "SEARCH" || input == "EXIT";
}

std::string getInput(void)
{
    std::string input;

    while (1)
    {
        std::cout << "Print 'ADD' to add a contact:\n'SEARCH' to search for a contact:\n'Exit' to exit the PhoneBook\nPhoneBook> ";
        getline(std::cin, input);
        if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
        }
        if (!input.empty() && isInputValid(input))
            break;
        std::cin.clear();
        std::cout << "Please insert a valid input" << std::endl;
    }
    return input;
}

int main(int ac, char **av)
{
    PhoneBook pb;
    std::string input;

	(void)av;
	if (ac == 1)
	{
    	while (1)
    	{
    	    input = getInput();
    	    if (input == "ADD")
    	        pb.add();
    	    else if (input == "SEARCH")
    	        pb.search();
    	    else
    	    {
    	        std::cout << "EXIT" << std::endl;
    	        return 0;
    	    }
    	}
	}
    return 0;
}
