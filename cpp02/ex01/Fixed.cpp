#include "Fixed.hpp"

/*

// esta forma es mejor porque de la otra value se inicializa
// primero con un valor random y luego se pone el valor correcto (0)
// obligatorio para const y referencias (&), supongo q pq const no
// puede cambiar del ramdom a (0), tengo la otra pq se me
// hace raro verlo de esa forma

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}
*/

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

// Constructor de enteros
Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = n << bits; // Desplazamiento a la izquierda para almacenar parte fraccional
}

// Constructor de floats
Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << bits)); // Multiplicación por 256 para convertir a punto fijo
}

// Constructor de copia
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;  // Copiamos el valor directamente
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Devuelve el valor en punto fijo
int Fixed::getRawBits(void) const
{
	return this->value;
}

// Establece el valor en punto fijo
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

// (float)this->value → Convierte ese número a float
// (1 << bits) → Bit shift izquierda == elevar 2 a la potencia de bits (2^bits)
// División final → Convierte value de fixed-point a un número decimal
float Fixed::toFloat(void) const 
{
	return (float)this->value / (1 << bits);
}

// Convierte a int (redondea hacia abajo)
int Fixed::toInt(void) const
{
	return this->value >> bits; // Desplazamiento a la derecha elimina la parte fraccional
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this; // el this y los punteros me matan
}
// this es un puntero al objeto actual, *this es el propio objeto
// no lo pillo del todo pero bueno

// Sobrecarga del operador << para imprimir, no pillo nada de esto
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}