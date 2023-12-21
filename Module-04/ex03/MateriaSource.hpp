#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *Materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& obj);
        ~MateriaSource();
        MateriaSource& operator=(const MateriaSource& obj);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif