#include "Zombie.hpp"

int main()
{
	// Crear zombie en heap (memoria dinamica, zombie permanecerá "vivo" hasta que se libere la memoria usando delete)
	Zombie* heapZombie = newZombie("Paco");
	heapZombie->announce();

	// Liberar la memoria del zombie (free), llama al destructor
	delete heapZombie;

	// Crear un zombie en el stack (zombie será destruido cuando el código termine su ejecución llamando al destructor)
	randomChump("Maria");

	return 0;
}
