#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// virtual es una palabra clave en C++ que
// permite la sobrescritura de métodos (funciones, 
// makeSound) en clases derivadas. Si no usas virtual,
// el compilador siempre usará la versión de makeSound()
// de la clase base Animal, incluso si se llama a través
// de un puntero de tipo Animal* que en realidad apunta
// a un objeto Dog. Usando virtual, C++ sabe que en realidad
// debe llamar a la versión de makeSound() en la clase Dog,
// no en Animal.

class Animal
{
    protected:
        std::string type;

    public:
        Animal();
        virtual ~Animal();
        // Destructor virtual en la clase base es necesario
        // en herencias polimorficas para eliminar objetos
        // derivados correctamente cuando se usan punteros
        // o referencias de tipo base.
        virtual void makeSound() const;
        // tener el viertual significa que queremos acceder
        // al metodo de la clase deribada, al makeSound de
        // Cat, por ejemplo
        std::string getType() const;
};

#endif
