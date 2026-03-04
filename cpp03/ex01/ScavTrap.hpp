#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif