#include "Statue.h"

Statue::Statue(int diff, std::string name_book, std::string atr) : Difficulty(diff), nume(name_book), atribut(atr)
{
}

int Statue::getDifficulty()
{
	return this->Difficulty;
}

std::string Statue::getAtribut()
{
	return this->atribut;
}

void Statue::prezinta_statue()
{
	std::cout << this->nume << " " << this->atribut << std::endl;
}

std::string Statue::getNume()
{
	std::cout << "\033[1;33m";
	return this->nume;
	std::cout << "\033[0m";

}
