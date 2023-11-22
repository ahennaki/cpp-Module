#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdio>
# include "contact.hpp"

class PhoneBook {
    private:

        size_t count;
        size_t index;
		Contact contacts[8];

    public:

       PhoneBook();
       void add(void);
       void search(void);
};

#endif
