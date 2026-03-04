#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    public:
        Brain();
        ~Brain();
        Brain(const Brain& other);  // Constructor de copia (deep copy)
        Brain& operator=(const Brain& other);  // Operador de asignación (deep copy)
        
        void printIdeas() const;
        std::string ideas[100];  // Array de ideas
};

#endif