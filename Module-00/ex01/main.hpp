#ifndef MAIN_HPP
# define MAIN_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
    public:
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setPhoneNumber(std::string str);

        const std::string&	getFirstName(void) const;
        const std::string&	getLastName(void) const;
        const std::string&	getPhoneNumber(void) const;

    private:
        std::string	first_name;
        std::string	last_name;
        std::string	phone_number;
};

class PhoneBook {
    public:
       PhoneBook();
       void add(void);
       void search(void);

    private:
        size_t count;
        size_t index;
		Contact contacts[8];
};

#endif