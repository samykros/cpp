#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class ClapTrap
{
    protected:
        std::string name;
        int hit_points; // vida
        int energy_points;
        int attack_damage;

    public:
        ClapTrap(std::string const& name);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif