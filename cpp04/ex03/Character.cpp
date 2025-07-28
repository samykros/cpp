#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = nullptr;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = nullptr;
        }
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inventory[i])
        {
            inventory[i] = m;  // Equipamos la Materia en el primer espacio vacío
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        inventory[idx] = nullptr;  // Vaciamos el espacio de la Materia
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
    {
        inventory[idx]->use(target);  // Llamamos al método 'use' de la Materia
    }
}