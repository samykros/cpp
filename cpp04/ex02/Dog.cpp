#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

// Constructor de copia (deep copy)
Dog::Dog(const Dog& other) : Animal(other)
{
    this->brain = new Brain(*other.brain);  // Copiamos el cerebro de otro perro
    std::cout << "Dog copy constructor called" << std::endl;
}

// Operador de asignación (deep copy)
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other) {
        Animal::operator=(other);  // Copiamos la base (Animal)
        delete brain;  // Liberamos el cerebro antiguo
        brain = new Brain(*other.brain);  // Copiamos el cerebro de otro perro
    }
    std::cout << "Dog assignment operator called" << std::endl;
    return *this;
}
