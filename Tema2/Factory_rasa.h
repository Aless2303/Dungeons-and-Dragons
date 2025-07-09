#pragma once

#include<iostream>
#include"Elf.h"
#include"Orc.h"
#include"Human.h"
#include"Goblin.h"

rasa_nume convert_string_to_rasa(std::string nume_rasa);

class Factory_rasa
{
public:
	static IRasa* getRasa(std::string nume_rasa);
};

