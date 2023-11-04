#include "main.hpp"

std::string getFormattedField(const std::string& field)
{
	if (field.length() > 10)
		return field.substr(0,9) + ".";
	return field;
}

void display_contact_info(Contact contact)
{
	std::cout << std::endl;
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << std::endl;
}

PhoneBook::PhoneBook() : count(0) , index(0) {};

void PhoneBook::add(void)
{
	Contact	new_contact;
	std::string	input;

	std::cout << "First name: ";
	getline(std::cin, input);
	new_contact.setFirstName(input);

	std::cout << "Last name: ";
	getline(std::cin, input);
	new_contact.setLastName(input);

	while (1)
	{
		std::cout << "Phone number : ";
		getline(std::cin, input);
		if (!input.empty() && input.find_first_not_of("0123456789") != std::string::npos) 
		{
			std::cin.clear();
			std::cout << "Phone number must be fully composed by numbers" << std::endl;
			continue;
		}
		new_contact.setPhoneNumber(input);
		break;
	}

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
	std::cout << "Contact added successfully" << std::endl;
}

void PhoneBook::search(void)
{
	if (count == 0)
	{
		std::cout << "There are no contacts to display!" << std::endl;
		return ;
	}
	std::cout << "\n|     Index|First Name| Last Name|" << std::endl;
	for (size_t i = 0; i < this->count; i += 1)
	{
		std::cout << "|" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getFirstName()) << "|" ;
		std::cout << std::right << std::setw(10) << getFormattedField(contacts[i].getLastName()) << "|";
		std::cout << std::endl;
	}

	std::string index;
	int conv_index;

	while (1)
	{
		std::cout << "Please insert the index of the contact you'd like to display:";
		getline(std::cin, index);
		if (!index.empty() && index.find_first_not_of("0123456789") == std::string::npos)
		{
			conv_index = atoi(index.c_str());
			if (conv_index <= 7)
				break;
		}
		std::cin.clear();
		std::cout << "Invalid input" << std::endl;
	}
	if ((size_t)conv_index > (count - 1))
		std::cout << "There's no contact with that index" << std::endl;
	else
		display_contact_info(this->contacts[conv_index]);
}