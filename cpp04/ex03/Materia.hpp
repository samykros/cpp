#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource
{
    public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia[4];

    public:
        MateriaSource();

        ~MateriaSource();

        void learnMateria(AMateria* m);

        AMateria* createMateria(std::string const & type);
};

#endif
