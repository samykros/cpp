#include "phone_book.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include "phone_book.hpp"

std::string truncate(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int main(void)
{
	PhoneBook PB;
	PB.num = 0;
	std::string command;
	int index;
	int i = 0;

	while (true)
	{
		// Muestra el menú
		std::cout << "\n\033[97m\033[1mADD == 1, SEARCH == 2, EXIT == 3 : \033[0m";
		// Errores eof || ctrl + d
		if (!(std::cin >> command))
			break; // Salimos del while y, por ende, del programa
		// Después de leer el comando, limpiamos el salto de línea que queda en el buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (command == "ADD" || command == "1")
		{
			if (i >= 8)
				i = 0;
			
			std::cout << "\033[32mName:         \033[0m";
			std::getline(std::cin, PB.Contacts[i].name); // getline lee linea completa con " "
			
			std::cout << "\033[32mLast name:    \033[0m";
			std::getline(std::cin, PB.Contacts[i].last_name);
			
			std::cout << "\033[32mNickname:     \033[0m";
			std::getline(std::cin, PB.Contacts[i].nickname);
			
			std::cout << "\033[32mPhone number: \033[0m";
			std::getline(std::cin, PB.Contacts[i].phone);
			
			std::cout << "\033[32mSecret:       \033[0m";
			std::getline(std::cin, PB.Contacts[i].secret);

			i++;
			if (PB.num < 8)
				PB.num++;
		}
		else if (command == "SEARCH" || command == "2")
		{
			if (PB.num == 0)
			{
				std::cout << "\033[31mNo hay contactos guardados.\033[0m\n";
				continue; // Vuelve al inicio del while
			}

			for (int j = 0; j < PB.num; j++)
			{
				std::cout << std::setw(2) << "\033[97m\033[1m" << j + 1 << " |\033[0m"; // setw guarda espacio
				std::cout << std::setw(10) << truncate(PB.Contacts[j].name) << "\033[97m\033[1m |\033[0m";
				std::cout << std::setw(10) << truncate(PB.Contacts[j].last_name) << "\033[97m\033[1m |\033[0m";
				std::cout << std::setw(10) << truncate(PB.Contacts[j].nickname) << "\033[97m\033[1m |\033[0m";
				std::cout << std::endl;
			}
			std::cout << std::endl << "\033[97m\033[1mEnter index for details: \033[0m";
			
			std::cin >> index;
			if (std::cin.fail() || index <= 0 || index > PB.num)
			{
				std::cin.clear(); 
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\033[31mInvalid index!\033[0m" << std::endl;
			}
			else
			{
				// Convertimos a base 0
				index--;
				// Mostramos datos
				std::cout << "\033[32mName:      \033[0m" << PB.Contacts[index].name << std::endl;
				std::cout << "\033[32mLast Name: \033[0m" << PB.Contacts[index].last_name << std::endl;
				std::cout << "\033[32mNickname:  \033[0m" << PB.Contacts[index].nickname << std::endl;
				std::cout << "\033[32mPhone:     \033[0m" << PB.Contacts[index].phone << std::endl;
				std::cout << "\033[32mSecret:    \033[0m" << PB.Contacts[index].secret << std::endl;
			}
		}
		else if (command == "EXIT" || command == "3")
		{
			break;
		}
		else
		{
			std::cout << "\033[31mInvalid input\033[0m" << std::endl;
		}
	}
	return 0;
}
