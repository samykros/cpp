#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// Polimorfismo: Usamos punteros o referencias a la clase
// base (Animal*), pero en tiempo de ejecución, C++ decide
// llamar a la implementación más específica, que está en
// las clases derivadas (Dog y Cat).

// Has tenido problemas con los includes
// poner #include "Dog.hpp" en Animal.hpp y eso mal

// cuando se usa delete?

int main()
{
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    c->makeSound();
    d->makeSound();
    a->makeSound();

    return 0;
}