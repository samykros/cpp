#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

const std::string& Weapon::getType()
{
	return type;
}

void Weapon::setType(const std::string& Newtype)
{
	type = Newtype;
}
