#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure& obj);
        Cure &operator=(const Cure& obj);
        ~Cure();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
