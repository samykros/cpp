#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

/*
Eliminamos esto
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
*/

std::string Animal::getType() const
{
    return this->type;
}