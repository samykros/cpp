#include "Zombie.hpp"

// Función para crear un zombie en el heap
// Entiendo que new es como malloc 
Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}
