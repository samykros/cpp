#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

// por lo que entiendo, los fixed point nbr es como pasar a otra base
// igual q pasas 10,50 euro a 1050 centimos pasas 2,75, por ejemplo
// a 704 pq es 2,75 x (2^8). Relacion con binario que no me aclaro de todo
// sigo sin entender funcionalidad, chatgpt dice q algunos systemas
// no tienen floats y cosas asi, pero se me ocurre ponerlo como fraccion
// 5/2 o ns, pq de la otra forma es pasarlo todo a otra base, no?