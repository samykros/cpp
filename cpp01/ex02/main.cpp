#include <string>
#include <iostream>

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;

	std::cout << "Address of string variable: " << &string << std::endl;
	std::cout << "Address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Address held by stringREF:  " << &stringREF << std::endl;

	std::cout << "Value of string variable:      " << string << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}

// En C++ una referencia es un alias para otra variable.
// Otro nombre para la misma variable existente.
// Estás creando un segundo nombre que puedes usar para referirte a esa variable.
// No es una nueva variable en sí misma;
// No ocupa un espacio de memoria adicional.
// No me entero del todo para que sirve pero bueno, ahi esta