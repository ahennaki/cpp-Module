#include "main.hpp"

PhoneBook::PhoneBook()
{
	count = 0;
	index = 0;
}

std::string getFormattedField(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

void display_contact_info(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

static std::string getInput(std::string str)
{
	std::string	input;

	while (1)
	{
		std::cout << str;
		getline(std::cin, input);
		if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
        }
		if (input.empty())
		{
			std::cin.clear();
			std::cout << "The input shouldn't be empty!!" << std::endl;
			continue;
		}
		break;
	}
	return (input);
}

void PhoneBook::add(void)
{
	Contact	new_contact;
	std::string	input;

	new_contact.setFirstName(getInput("First name: "));
	new_contact.setLastName(getInput("Last name: "));
	new_contact.setNickname(getInput("Nickname: "));

	while (1)
	{
		std::cout << "Phone number : ";
		getline(std::cin, input);
		if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
        }
		if (input.empty() || (!input.empty() && input.find_first_not_of("0123456789") != std::string::npos)) 
		{
			std::cin.clear();
			std::cout << "The input shouldn't be empty!!" << std::endl;
			std::cout << "Phone number must be composed by numbers" << std::endl;
			continue;
		}
		new_contact.setPhoneNumber(input);
		break;
	}

	new_contact.setDarkestSecret(getInput("Darckest secret: "));

	if (count > 7 || index > 7)
	{
		if (index > 7)
			index = 0;
		index++;
		this->contacts[index - 1] = new_contact;
	}
	else
	{
		this->count++;
		this->index++;
		this->contacts[index - 1] = new_contact;
	}
	std::cout << "	Contact added successfully:" << std::endl << std::endl;
}

void PhoneBook::search(void)
{
	if (count == 0)
	{
		std::cout << "	There are no contacts to display!" << std::endl << std::endl;
		return ;
	}
	std::cout << "\n|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|" ;
		std::cout << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << getFormattedField(contacts[i].getNickname()) << "|";
		std::cout << std::endl;
	}

	std::string index;
	int conv_index;

	while (1)
	{
		std::cout << "Please insert the index of the contact you'd like to display:";
		getline(std::cin, index);
		if (std::cin.eof() == true)
        {
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
        }
		if (!index.empty() && index.find_first_not_of("0123456789") == std::string::npos)
		{
			conv_index = atoi(index.c_str());
			if (conv_index <= 7)
				break;
		}
		std::cin.clear();
		std::cout << "INVALID INPUT!!" << std::endl << std::endl;
	}
	if ((size_t)conv_index > (count - 1))
		std::cout << "There's no contact with that index:" << std::endl << std::endl;
	else
		display_contact_info(this->contacts[conv_index]);
}