#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const Animal* a = NULL;

    j->makeSound();
    i->makeSound();
    // a->makeSound(); esto da segfault porque animal es abstracto ahora
    
    // j->brain->printIdeas();  // Mostramos las ideas del perro
    // i->brain->printIdeas();  // Mostramos las ideas del gato

    delete j;
    delete i;

    return 0;
}

/*
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    return 0;
}
*/