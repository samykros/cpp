#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

void Human_B::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon; // this especifica q weapon es la q esta en clase Human_B, no parametro q recibe la funcion
}

void Human_B::attack()
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with." << std::endl;
}
