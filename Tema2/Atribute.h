#pragma once

#include<iostream>
#include<string>
#include"IClasa.h"
#include"IRasa.h"


//#include"Factory_rasa.h"
//#include"Factory_clasa.h"

typedef int atribut_type;
#define MAX_ATRIBUTE 30
#define MIN_ATRIBUTE 1

typedef enum Trecut
{
	EROARE_TRECUT,
	MAGICIAN,
	SOLDAT,
	ACOLIT,
	HOT,
};


class Atribute
{
public:
	Atribute();
	Atribute(atribut_type str, atribut_type dex, atribut_type cons, atribut_type intell, atribut_type wisd, atribut_type ch);
	~Atribute() = default;
	void set_strenght(atribut_type str);
	void set_dexteriy(atribut_type dex);
	void set_constitution(atribut_type cons);
	void set_intelligence(atribut_type intell);
	void set_wisdom(atribut_type wisd);
	void set_charisma(atribut_type ch);
	atribut_type get_strenght();
	atribut_type get_dexterity();
	atribut_type get_constitution();
	atribut_type get_intelligence();
	atribut_type get_wisdom();
	atribut_type get_charisma();


	atribut_type getAtribut_by_name(std::string atr);

	void interactiune_esuata(std::string atr);
	void interactiune_reusita(std::string atr);

	void print_atribute();

	void set_atribute_rasa(IRasa* rasa);
	void set_atribute_trecut(Trecut trecut);
	void set_atribute_clasa(IClasa* clasa);

private:
	atribut_type strenght;
	atribut_type dexterity;
	atribut_type constitution;
	atribut_type intelligence;
	atribut_type wisdom;
	atribut_type charisma;
};




bool test_maxim(atribut_type atr);
bool test_min(atribut_type atr);
atribut_type calcul_procent(atribut_type atr, int procent);
void test_min_max_atribute(Atribute* atribute);
std::ostream& operator<<(std::ostream& os, const Trecut& trecut);