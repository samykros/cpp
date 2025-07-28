#include "FragTrap.hpp"

int main() {
    FragTrap bot("RDaniel");

    bot.attack("target dummy");
    bot.takeDamage(42);
    bot.beRepaired(20);
    bot.highFivesGuys();
}
