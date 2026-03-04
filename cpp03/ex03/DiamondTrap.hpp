#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    private:
        std::string name;

    public:
        DiamondTrap(const std::string& name);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI(void);
};

#endif