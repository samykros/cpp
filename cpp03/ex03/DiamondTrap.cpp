#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name")
{
	this->_name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor for " << this->name << " called" << std::endl;
}

// Sobrecarga del método attack
void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);  // Llama al attack() de ScavTrap
}

// Sobrecarga del método takeDamage
void DiamondTrap::takeDamage(unsigned int amount)
{
    FragTrap::takeDamage(amount);  // Llama al takeDamage() de FragTrap
}

// Sobrecarga del método beRepaired
void DiamondTrap::beRepaired(unsigned int amount)
{
    FragTrap::beRepaired(amount);  // Llama al beRepaired() de FragTrap
}

// Método quien soy (whoAmI)
void DiamondTrap::whoAmI(void)
{
    std::cout << "Hello, I am a DiamondTrap named " << this->name <<
        " and I am originated from the ClapTrap named " << ClapTrap::name << "." <<
        std::endl;
}
