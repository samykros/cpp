#include "serialization.hpp"

// Convierte un puntero Data* a uintptr_t (entero sin signo)
uintptr_t Serializer::serialize(Data* ptr)
{
    // reinterpret_cast convierte el puntero en un número entero
    return reinterpret_cast<uintptr_t>(ptr);
}

// Convierte un entero uintptr_t de nuevo a Data*
Data* Serializer::deserialize(uintptr_t raw)
{
    // reinterpret_cast convierte el número de vuelta a puntero
    return reinterpret_cast<Data*>(raw);
}

// reinterpret_cast → convierte un tipo a otro tipo “incompatible”, en este caso puntero → entero.
// uintptr_t → tipo entero sin signo que puede almacenar cualquier dirección de memoria.
