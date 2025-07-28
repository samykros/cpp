#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(const std::string& name);
        ~FragTrap();


    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif