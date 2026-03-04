#include "Zombie.hpp"

// Constructor
Zombie::Zombie() {}

// Destructor
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
