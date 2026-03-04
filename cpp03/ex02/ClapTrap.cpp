#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << this->name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energy_points <= 0 || hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " can't attack. No energy or dead." << std::endl;
        return;
    }

    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_points -= amount;
    if (hit_points < 0)
        hit_points = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! Remaining HP: " << hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points <= 0 || hit_points <= 0)
    {
        std::cout << "ClapTrap " << name << " can't repair. No energy or dead." << std::endl;
        return;
    }

    hit_points += amount;
    energy_points--;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hit points! Total HP: " << hit_points << std::endl;
}