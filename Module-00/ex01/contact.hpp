#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdio>

class Contact {
    private:

        std::string	first_name;
        std::string	last_name;
        std::string Nickname;
        std::string	phone_number;
        std::string DarkestSecret;

    public:

        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickname(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);

        const std::string&	getFirstName(void) const;
        const std::string&	getLastName(void) const;
        const std::string&	getNickname(void) const;
        const std::string&	getPhoneNumber(void) const;
        const std::string&	getDarkestSecret(void) const;
};

#endif
