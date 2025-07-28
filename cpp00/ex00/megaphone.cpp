#include <iostream>
#include <cctype>   // std::toupper

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	// Empezar i = 1 para omitir el nombre del programa
	for (int j = 1; j < argc; j++)
	{
		int i = 0;
		while (argv[j][i] != '\0')
		{
			// Mayúscula con toupper (toupper funciona con char, no str) y enviar a la salida
			std::cout << (char)std::toupper(argv[j][i]);
			i++;
		}
		if (j != argc - 1)
			std::cout << " ";
	}
	// Al final, un salto de línea
	std::cout << std::endl;
	return 0;
}

