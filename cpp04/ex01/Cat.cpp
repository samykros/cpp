#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

// Constructor de copia (deep copy)
Cat::Cat(const Cat& other) : Animal(other)
{
    this->brain = new Brain(*other.brain);  // Copiamos el cerebro de otro gato
    std::cout << "Cat copy constructor called" << std::endl;
}

// Operador de asignación (deep copy)
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);  // Copiamos la base (Animal)
        delete brain;  // Liberamos el cerebro antiguo
        brain = new Brain(*other.brain);  // Copiamos el cerebro de otro gato
    }
    std::cout << "Cat assignment operator called" << std::endl;
    return *this;
}
