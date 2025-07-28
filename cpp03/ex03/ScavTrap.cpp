#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap " << this->name << " created (with special stats)!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energy_points <= 0 || hit_points <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack. No energy or dead." << std::endl;
        return;
    }

    energy_points--;
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
}
