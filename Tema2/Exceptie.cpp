#include "Exceptie.h"

void Exceptie::printMesaj()
{
	std::cout << "\033[1;31m";
	std::cout << "Eroare. " << mesaj << std::endl;
	std::cout << "\033[0m";
}
