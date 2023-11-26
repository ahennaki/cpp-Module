#include "replace.hpp"

int main(int ac, char** av)
{
	if (ac != 4)
	{
	    std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
	    return 0;
	}
	std::string filename(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	if (s1.empty())
	{
	    std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>." << std::endl;
		std::cerr << "<s1> should not be empty!!" << std::endl;
	    return 0;
	}
	Replace replace(filename, s1, s2);
	if (!replace.replaceAndWriteToFile())
	{
		std::cerr << "Error in the file!!" << std::endl;
		return 0;
	}
	std::cout << "Check " << filename << ".replace" << std::endl;
	return 0;
}
