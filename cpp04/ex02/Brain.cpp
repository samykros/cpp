#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Empty idea";  // Inicializamos las ideas con un valor predeterminado
    }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

// Constructor de copia (deep copy)
Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ideas[i] = other.ideas[i];  // Copiamos cada idea
    }
}

// Operador de asignación (deep copy)
Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
    {  // Comprobamos auto-asignación
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = other.ideas[i];  // Copiamos cada idea
        }
    }
    return *this;
}

void Brain::printIdeas() const
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Idea " << i + 1 << ": " << ideas[i] << std::endl;
    }
}
