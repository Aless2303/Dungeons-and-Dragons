#pragma once


#include<iostream>


class Statue
{
	int Difficulty;
	std::string nume;
	std::string atribut;
public:
	Statue() = default;
	Statue(int diff, std::string name_book, std::string atr);


	int getDifficulty();
	std::string getAtribut();

	void prezinta_statue();
	std::string getNume();

};

