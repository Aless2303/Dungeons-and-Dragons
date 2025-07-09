#include "Personaj.h"


void print_text_alegere_rasa() {
	std::cout << "\033[1;33m";
	std::cout << "Alege rasa pe care o doresti dintre:\n";
	std::cout << "	ORC | ELF | HUMAN | GOBLIN \n";
	std::cout << "\033[0m";
}

void print_text_alegere_clasa() {
	std::cout << "\033[1;33m";
	std::cout << "Alege clasa pe care o doresti dintre:\n";
	std::cout << "	FIGHTER | SORCERER | WARRIOR | NINJA \n";
	std::cout << "\033[0m";
}

void print_text_alegere_trecut() {
	std::cout << "\033[1;33m";
	std::cout << "Alege trecutul pe care il doresti dintre:\n";
	std::cout << "	MAGICIAN | SOLDAT | ACOLIT | HOT \n";
	std::cout << "\033[0m";

}

Trecut convert_string_to_trecut(std::string nume_trecut)
{
	if (nume_trecut == "MAGICIAN")
		return MAGICIAN;
	else if (nume_trecut == "SOLDAT")
		return SOLDAT;
	else if (nume_trecut == "ACOLIT")
		return ACOLIT;
	else if (nume_trecut == "HOT")
		return HOT;

	throw new Exceptie("Eroare. Ai introdus numele trecutului gresit.");
}

void print_text_alegere_nume()
{
	std::cout << "\033[1;33m";
	std::cout << "Alege un nume pentru caracter:\n";
	std::cout << "\033[0m";
}

Personaj::Personaj()
{
	int ok = 1;

	while(ok==1)
	{
		try {
			print_text_alegere_rasa();
			std::string nume_rasa_temporar;
			std::cin >> nume_rasa_temporar;
			//std::getline(std::cin, nume_rasa_temporar);
			ok = 0;
			this->rasa_personaj = Factory_rasa::getRasa(nume_rasa_temporar);
		}
		catch (IExceptie* ex)
		{
			ex->printMesaj();
			ok = 1;
		}
	}

	ok = 1;
	while (ok == 1)
	{
		try {
			print_text_alegere_clasa();
			ok = 0;
			std::string nume_clasa_temporar;
			std::cin >> nume_clasa_temporar;
			this->clasa_personaj = Factory_clasa::getClasa(nume_clasa_temporar);
		}
		catch (IExceptie* ex)
		{
			ex->printMesaj();
			ok = 1;
		}
	}

	ok = 1;
	while (ok == 1)
	{
		try {
			ok = 0;
			print_text_alegere_trecut();
			std::string nume_trecut_temporar;
			std::cin >> nume_trecut_temporar;
			this->trecut_personaj = convert_string_to_trecut(nume_trecut_temporar);
		}
		catch (IExceptie* ex)
		{
			ex->printMesaj();
			ok = 1;
		}
	}


	print_text_alegere_nume();
	std::cin >> this->nume;

	this->atribute_personaj.set_atribute_rasa(this->rasa_personaj);
	this->atribute_personaj.set_atribute_clasa(this->clasa_personaj);
	this->atribute_personaj.set_atribute_trecut(this->trecut_personaj);
	this->hp = this->atribute_personaj.get_constitution() * 10;
}

Personaj::Personaj(IRasa* rasa, IClasa* clasa, Trecut trecut,std::string name) : rasa_personaj(rasa), clasa_personaj(clasa), trecut_personaj(trecut), nume(name)
{
	if (rasa == nullptr || clasa == nullptr || trecut == EROARE_TRECUT)
		throw new Exceptie("eroare la Personaj::Personaj(IRasa* rasa, IClasa* clasa, Trecut trecut,std::string name) din Personaj.cpp deoarece este nullptr.\n");

	this->atribute_personaj.set_atribute_rasa(this->rasa_personaj);
	this->atribute_personaj.set_atribute_clasa(this->clasa_personaj);
	this->atribute_personaj.set_atribute_trecut(this->trecut_personaj);
	this->hp = this->atribute_personaj.get_constitution() * 10;
}

void Personaj::interactiune_esuata(std::string atr)
{
	this->atribute_personaj.interactiune_esuata(atr);
}

void Personaj::interactiune_reusita(std::string atr)
{
	this->atribute_personaj.interactiune_reusita(atr);
}

int Personaj::ataca()
{
	bool ok = true;

	std::string alegere;
	while(ok==true)
	{
		ok = false;
		std::cout << "\033[1;33m";
		std::cout << "Alege atacul de la RASA sau CLASA: ";
		std::cout << "\033[0m";
		std::cin >> alegere;

		if (!(alegere == "RASA" || alegere == "CLASA"))
		{
			std::cout << "\033[1;31m";
			std::cout << "Ai tastat gresit RASA sau CLASA. Mai alege odata.\n";
			std::cout << "\033[0m";
			ok = true;
		}
			/*throw new Exceptie("Eroare in  Personaj::ataca din Personaj.cpp deoarece nu s-a tastat bine RASA sau CLASA.\n");*/
	}

	ok = true;

	std::string skil;
	while(ok==true)
	{
		ok = false;
		std::cout << "\033[1;33m";
		std::cout << "Tasteaza 1 sau 2 in functie de skill doresti: ";
		std::cout << "\033[0m";
		std::cin >> skil;



		if (!(skil == "1" || skil == "2"))
		{
			std::cout << "\033[1;31m";
			std::cout << "Ai tastat gresit 1 sau 2. Mai alege odata.\n";
			std::cout << "\033[0m";
			ok = true;
		}
			//throw new Exceptie("Eroare in  Personaj::ataca din Personaj.cpp deoarece nu s-a tastat bine skilul, 1 sau 2.\n");
	}

	int dmg=0;

	if (alegere == "RASA")
	{
		if (skil == "1")
			dmg=this->rasa_personaj->skill1(this->atribute_personaj);
		else if (skil == "2")
			dmg=this->rasa_personaj->skill2(this->atribute_personaj);
	}
	else if (alegere == "CLASA")
	{
		if (skil == "1")
			dmg = this->clasa_personaj->skill1(this->atribute_personaj);
		else if (skil == "2")
			dmg = this->clasa_personaj->skill2(this->atribute_personaj);
	}
	return dmg;
}

void Personaj::scade_hp(int dmg)
{
	this->hp -= dmg;
}

int Personaj::getHP()
{
	return this->hp;
}

void Personaj::setHP_WIN()
{
	int new_cons = this->atribute_personaj.get_constitution();
	new_cons += 2;
	if (new_cons > MAX_ATRIBUTE)
		new_cons = MAX_ATRIBUTE;
	this->atribute_personaj.set_constitution(new_cons);
	this->hp = new_cons * 10;
}

int Personaj::getAtribut_by_name(std::string atr)
{
	return atribute_personaj.getAtribut_by_name(atr);

}



void Personaj::prezinta_personaj()
{
	std::cout << "\033[1;33m";
	std::cout << this->nume << " " << this->trecut_personaj << " " << this->rasa_personaj->getRasa() << " " << this->clasa_personaj->getClasa() << std::endl;
	std::cout << "\033[0m";
}

void Personaj::prezinta_statusuri_hp()
{
	std::cout << "\033[1;33m";
	std::cout << "		++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "			" << this->nume << std::endl;
	std::cout << "	   	   " << this->rasa_personaj->getRasa() <<" " << this->clasa_personaj->getClasa() << " " << this->trecut_personaj << std::endl;
	std::cout << "\033[0m";
	this->atribute_personaj.print_atribute();
	std::cout << "\033[1;33m";
	std::cout << "			"<<"HP: " << this->hp << "\n";
	std::cout << "		++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "\033[0m";
}


std::string Personaj::getNume()
{
	return this->nume;
}


