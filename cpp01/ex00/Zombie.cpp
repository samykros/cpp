#include "Zombie.hpp"

// Constructor función especial de la clase se llama cada vez que crea un objeto de esa clase
Zombie::Zombie(std::string name) : name(name) {}

// Destructor se llama automáticamente cuando un objeto de la clase se destruye (delete)
Zombie::~Zombie()
{
	std::cout << name << " is being destroyed" << std::endl;
}

void Zombie::setName(const std::string& newName)
{
	name = newName;
}

void Zombie::announce()
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
