#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = n << bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(n * (1 << bits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.value;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const 
{
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

// new

bool Fixed::operator>(const Fixed &other) const
{
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.value == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	this->value += 1; // Incrementa en el mínimo valor representable (1 en punto fijo)
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this; // Guarda el estado actual
	this->value += 1;
	return temp; // Devuelve el valor antes del incremento
}

Fixed &Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->value -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

