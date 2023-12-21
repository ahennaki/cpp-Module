#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        Materias[i] = 0;
	// std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
    for (size_t i = 0; i < 4; i++)
        Materias[i] = obj.Materias[i]->clone();
	// std::cout << "MateriaSource copy constructor called." << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
    if (this != &obj)
        for (size_t i = 0; i < 4; i++)
        {
            if (Materias[i])
            {
                delete Materias[i];
                Materias[i] = 0;
            }
            Materias[i] = obj.Materias[i]->clone();
        }
	// std::cout << "MateriaSource copy assignment operator called." << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
        if (Materias[i])
            delete Materias[i];
	// std::cout << "MateriaSource destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
    size_t i = 0;

	while (i < 4 && this->Materias[i])
		i++;
	if (i != 4)
		this->Materias[i] = m;
	// std::cout << "learnMateria() called." << std::endl;
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for ( int i = 0; i < 4; i++ )
        if ( Materias[i] && Materias[i]->getType() == type )
            return Materias[i]->clone();
    return 0;
}
