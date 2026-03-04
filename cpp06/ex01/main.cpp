#include "serialization.hpp"

int main()
{
    // Crear un objeto Data
    Data d;
    d.nbr = 42;

    std::cout << "Original pointer: " << &d << "\n";

    // Convertir puntero a entero
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Serialized value: " << raw << "\n";

    // Convertir entero de nuevo a puntero
    Data* recovered = Serializer::deserialize(raw);
    std::cout << "Recovered pointer: " << recovered << "\n";

    // Comprobar que apuntan al mismo objeto
    if (recovered == &d)
        std::cout << "Pointers match.\n";
    else
        std::cout << "Error! Pointers do not match.\n";

    // Mostrar el contenido del objeto usando el puntero recuperado
    std::cout << "Recovered value: " << recovered->nbr << "\n";

    return 0;
}
