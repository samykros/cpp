#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
	}

// por lo que entiendo, los fixed point nbr es como pasar a otra base
// igual q pasas 10,50 euro a 1050 centimos pasas 2,75, por ejemplo
// a 704 pq es 2,75 x (2^8). Relacion con binario que no me aclaro de todo
// sigo sin entender funcionalidad, chatgpt dice q algunos systemas
// no tienen floats y cosas asi, pero se me ocurre ponerlo como fraccion
// 5/2 o ns, pq de la otra forma es pasarlo todo a otra base, no?