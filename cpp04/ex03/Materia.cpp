#include "AMateria.hpp"
#include "Materia.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        materia[i] = nullptr;  // Inicializamos el inventario vacío
}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete materia[i];  // Eliminamos las Materias al destruir el objeto
}

/*
mejora
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (materia[i])
        {
            delete materia[i];
            materia[i] = nullptr;
        }
    }
}
*/

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!materia[i])
        {
            materia[i] = m;  // Guardamos la Materia en el primer espacio vacío
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materia[i] && materia[i]->getType() == type)
        {
            return materia[i]->clone();  // Retorna una nueva Materia del mismo tipo
        }
    }
    return nullptr;  // Si no encontramos el tipo, retornamos nullptr
}