#pragma once

#include<iostream>

class Book
{
	int Difficulty;
	std::string nume;
	std::string atribut;
public:
	Book() = default;
	Book(int diff, std::string name_book, std::string atr);

	std::string getNume();
	int getDifficulty();
	std::string getAtribut();
	void prezinta_book();

	

};

