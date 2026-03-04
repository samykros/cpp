#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// utilizamos deep copy para que Dog tenga su propio array
// de ideas y Cat su propio array y no sea solo compartir
// la direccion de memoria de un array de ideas
// Si copias el puntero del Brain sin hacer una copia profunda,
// cuando destruyes un objeto (como el Dog o el Cat), se libera
// la memoria del array de ideas de ambos objetos, ya que ambos
// objetos apuntan a la misma dirección de memoria. Esto puede
// causar un problema de doble liberación de memoria, también
// conocido como fugas de memoria. Si un objeto se destruye y
// libera la memoria, pero otro objeto también intenta liberar
// la misma memoria, eso provoca un error de memoria.

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();
    j->brain->printIdeas();  // Mostramos las ideas del perro
    i->brain->printIdeas();  // Mostramos las ideas del gato

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