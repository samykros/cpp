#include "Zombie.hpp"

// Crear un zombie en el stack y que se anuncie
void randomChump(std::string name)
{
	Zombie Z(name); // Llamada al constructor 
	Z.announce();
}
