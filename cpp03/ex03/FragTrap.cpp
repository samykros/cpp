#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap " << this->name << " created (with special stats)!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        energy_points--;
        std::cout << "FragTrap " << name << " throws a mega attack at " << target << ", dealing " << attack_damage << " damage!" << std::endl;
    }
    else
        std::cout << "FragTrap " << name << " can't attack right now." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " wants to give a high five!✋" << std::endl;
}
