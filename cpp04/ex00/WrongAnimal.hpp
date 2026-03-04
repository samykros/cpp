#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        void makeSound() const;    // No tiene virtual, por lo que lo hara mal
        std::string getType() const;

    protected:
        std::string type;
};

#endif
