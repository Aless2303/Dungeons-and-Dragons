#pragma once

#include<iostream>
#include"Fighter.h"
#include"Ninja.h"
#include"Sorcerer.h"
#include"Warrior.h"


clasa_nume convert_string_to_clasa(std::string nume_clasa);


class Factory_clasa
{
public:
	static IClasa* getClasa(std::string nume_rasa);
};

