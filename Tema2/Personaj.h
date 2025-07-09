#pragma once

#include"Atribute.h"

#include"Factory_rasa.h"
#include"Factory_clasa.h"




class Personaj
{
protected:
	Atribute atribute_personaj;
	IRasa* rasa_personaj;
	IClasa* clasa_personaj;
	Trecut trecut_personaj;
	int hp;
	std::string nume;
public:
	Personaj();
	Personaj(IRasa* rasa, IClasa* clasa,Trecut trecut,std::string name);

	void interactiune_esuata(std::string atr);
	void interactiune_reusita(std::string atr);

	int ataca();
	void scade_hp(int dmg);
	int getHP();
	void setHP_WIN();
	int getAtribut_by_name(std::string atr);
	void prezinta_personaj();
	void prezinta_statusuri_hp();
	std::string getNume();
};


void print_text_alegere_rasa();
void print_text_alegere_clasa();
void print_text_alegere_trecut();

