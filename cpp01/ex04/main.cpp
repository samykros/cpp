#include "main.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream file(argv[1]);  // std::ifstream signfica archivo, igual que std::string significa string
		if (!file)
		{
			std::cerr << "Error opening file: " << argv[1] << std::endl;  // cerr se utiliza especificamente para printear errores
			return 1;
		}

		std::ofstream outFile((std::string(argv[1]) + ".replace").c_str());  // Archivo de salida
		if (!outFile)
		{
			std::cerr << "Error creating output file." << std::endl;  // puedes poner std::out y hace lo mismo
			return 1;
		}

		std::string line;
		std::string to_find = argv[2];
		std::string replacement = argv[3];
		size_t pos; // por que no funciona int ?

		while (std::getline(file, line))
		{
			size_t start = 0;
			while ((pos = line.find(to_find, start)) != std::string::npos)
			{
				line.erase(pos, to_find.length());
				line.insert(pos, replacement);
				start = pos + replacement.length();
			}
			outFile << line << std::endl;
		}

		file.close();
		outFile.close();
	}
	return 0;
}

// find() | length() es un ejemplo de método de la clase std::string
// find() busca una subcadena (to_find) dentro de una cadena (line) a partir de la posición start
// Si no se encuentra la subcadena, retorna std::string::npos
// erase e insert puedes deducir como funciona viendo find

// c_str() se utiliza para obtener un array de caracteres del contenido de un objeto
// devuelve un puntero const char* al primer char de una cadena de caracteres terminada en null