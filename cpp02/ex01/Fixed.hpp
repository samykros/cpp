#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	private:
		int value;
		// static = toda instancia comparte valor en vez de q cada instancia
		// tenga una copia, como una var global para todas las instancias
		// const = no cambia, pq no solo const?, no pillo del todo
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const int n); // Constructor con entero
		Fixed(const float n); // Constructor con float
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other); // Operador de asignación
		// Sobrecarga del operador << para imprimir, no entiendo q es eso
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
		~Fixed();

		int getRawBits(void) const; // Obtener el valor crudo
		void setRawBits(int const raw); // Establecer el valor crudo
		float toFloat(void) const; // Convierte a float
		int toInt(void) const; // Convierte a entero
};

#endif
