#include "Book.h"

Book::Book(int diff, std::string name_book, std::string atr) : Difficulty(diff), nume(name_book), atribut(atr)
{

}

std::string Book::getNume()
{
	return this->nume;
}

int Book::getDifficulty()
{
	return this->Difficulty;
}

std::string Book::getAtribut()
{
	return this->atribut;
}

void Book::prezinta_book()
{
	std::cout << "\033[1;33m";
	std::cout << this->nume << " " << this->atribut << std::endl;
	std::cout << "\033[0m";
}
