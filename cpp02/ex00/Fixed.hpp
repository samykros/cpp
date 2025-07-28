#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <fstream>

class Fixed
{
	private:
		int value;
		static const int bits = 8; // static = toda instancia comparte valor, const = no cambia, pq no solo const?, no pillo del todo
	public:
		Fixed();
		Fixed(const Fixed &other); // Constructor de copia, pq?
		Fixed &operator=(const Fixed &other); // Operador de asignación?
		~Fixed();

		int getRawBits(void) const; // Obtener el valor crudo
		void setRawBits(int const raw); // Establecer el valor crudo
};

#endif
