#ifndef MAIN_HPP
# define MAIN_HPP

# include <string>

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
        std::string	nickname;
        std::string	phone_number;
        std::string	darkest_secret;
};

class PhoneBook {
    public:
       /* Default constructor */
       PhoneBook();

       void add(void);
       void search(void);

    private:
        size_t count;
		Contact contacts[8];
};

#endif