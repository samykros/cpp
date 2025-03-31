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
		// Operador de salida (cout << obj)
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed); 
		~Fixed();

		int getRawBits(void) const; // Obtener el valor crudo
		void setRawBits(int const raw); // Establecer el valor crudo
		float toFloat(void) const; // Convierte a float
		int toInt(void) const; // Convierte a entero

		// Operadores de comparación
		// comparan valor y devuelven bool
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Operadores aritméticos
		// crean un nuevo Fixed con la operacion aplicada
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Operadores de incremento/decremento
		// pre modifica value y devuelve *this
		// post devuelve version anterior de this
		Fixed &operator++();   // Pre-incremento (++x)
		Fixed operator++(int); // Post-incremento (x++)
		Fixed &operator--();   // Pre-decremento (--x)
		Fixed operator--(int); // Post-decremento (x--)

		// Métodos estáticos min y max
		// devuelve referencia al menor o mayor valor (a o b)
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

#endif
