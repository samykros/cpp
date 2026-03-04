#include "base.hpp"

Base* generate(void)
{
    // Inicializamos la semilla una vez para que rand() sea diferente cada ejecución
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }

    int r = rand() % 3; // genera un número aleatorio: 0, 1 o 2

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) // basicamente: es p igual que el puntero de A?
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p)
{
    // dynamic_cast con referencia lanza std::bad_cast si no coincide
    // con punteros dynamic_cast<A*>(p) → devuelve nullptr si falla → no rompe el programa.
    // con referencias dynamic_cast<A&>(ref) → lanza excepción si falla → si no hay try/catch → crash
    // NO puedes usar un if normal: no hay un valor “falso” que revisar → si falla, el programa se rompe
    // pointers pueden apuntar a diferentes cosas y a nullptr, pero las referencias no
    try
    {
        (void)dynamic_cast<A&>(p); // void pq compilador se queja q el resultado de dynamic_cast no se guarda en variable
        std::cout << "A\n";
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::bad_cast&) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::bad_cast&) {}

    std::cout << "Unknown type\n";
}
