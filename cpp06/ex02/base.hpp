#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// Genera aleatoriamente un objeto de tipo A, B o C
Base* generate(void);

// Identifica la clase real usando un puntero
void identify(Base* p);

// Identifica la clase real usando referencia
void identify(Base& p);

#endif