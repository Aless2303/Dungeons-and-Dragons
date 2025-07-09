#include "Atribute.h"

std::ostream& operator<<(std::ostream& os, const Trecut& trecut)
{
	switch (trecut)
	{
	case EROARE_TRECUT:
		throw new Exceptie("Eroare_trecut in Atribute.cpp la supraincarcarea operatorului de afisare <<.\n");
		break;
	case MAGICIAN:
		os << "MAGICIAN";
		break;
	case SOLDAT:
		os << "SOLDAT";
		break;
	case ACOLIT:
		os << "ACOLIT";
		break;
	case HOT:
		os << "HOT";
		break;
	default:
		throw new Exceptie("Eroare_trecut in Atribute.cpp la supraincarcarea operatorului de afisare <<.\n");
	}

	return os;
}

bool test_maxim(atribut_type atr)
{
	if (atr <= MAX_ATRIBUTE)
		return true;
	else
		return false;
}

bool test_min(atribut_type atr)
{
	if (atr >= MIN_ATRIBUTE)
		return true;
	else
		return false;
}


void test_min_max_atribute(Atribute* atribute)
{
	if (atribute == nullptr)
		throw new Exceptie("Eroare la functia test_min_max_atribute in Atribute.cpp deoarece atribute=nullptr.\n");

	if (atribute->get_strenght() > MAX_ATRIBUTE)
		atribute->set_strenght(MAX_ATRIBUTE);
	else if (atribute->get_strenght() < MIN_ATRIBUTE)
		atribute->set_strenght(MIN_ATRIBUTE);

	if (atribute->get_dexterity() > MAX_ATRIBUTE)
		atribute->set_dexteriy(MAX_ATRIBUTE);
	else if (atribute->get_dexterity() < MIN_ATRIBUTE)
		atribute->set_dexteriy(MIN_ATRIBUTE);

	if (atribute->get_constitution() > MAX_ATRIBUTE)
		atribute->set_constitution(MAX_ATRIBUTE);
	else if (atribute->get_constitution() < MIN_ATRIBUTE)
		atribute->set_constitution(MIN_ATRIBUTE);

	if (atribute->get_intelligence() > MAX_ATRIBUTE)
		atribute->set_intelligence(MAX_ATRIBUTE);
	else if (atribute->get_intelligence() < MIN_ATRIBUTE)
		atribute->set_intelligence(MIN_ATRIBUTE);

	if (atribute->get_wisdom() > MAX_ATRIBUTE)
		atribute->set_wisdom(MAX_ATRIBUTE);
	else if (atribute->get_wisdom() < MIN_ATRIBUTE)
		atribute->set_wisdom(MIN_ATRIBUTE);

	if (atribute->get_charisma() > MAX_ATRIBUTE)
		atribute->set_charisma(MAX_ATRIBUTE);
	else if (atribute->get_charisma() < MIN_ATRIBUTE)
		atribute->set_charisma(MIN_ATRIBUTE);

}


Atribute::Atribute()
{
	this->strenght = 20;
	this->dexterity = 20;
	this->constitution = 20;
	this->intelligence = 20;
	this->wisdom = 20;
	this->charisma = 20;
}

Atribute::Atribute(atribut_type str, atribut_type dex, atribut_type cons, atribut_type intell, atribut_type wisd, atribut_type ch)
{
	this->strenght = str;
	this->dexterity = dex;
	this->constitution = cons;
	this->intelligence = intell;
	this->wisdom = wisd;
	this->charisma = ch;
}

void Atribute::set_strenght(atribut_type str)
{
	this->strenght = str;
}

void Atribute::set_dexteriy(atribut_type dex)
{
	this->dexterity = dex;
}

void Atribute::set_constitution(atribut_type cons)
{
	this->constitution = cons;
}

void Atribute::set_intelligence(atribut_type intell)
{
	this->intelligence = intell;
}

void Atribute::set_wisdom(atribut_type wisd)
{
	this->wisdom = wisd;
}

void Atribute::set_charisma(atribut_type ch)
{
	this->charisma = ch;
}

atribut_type Atribute::get_strenght()
{
	return this->strenght;
}

atribut_type Atribute::get_dexterity()
{
	return this->dexterity;
}

atribut_type Atribute::get_constitution()
{
	return this->constitution;
}

atribut_type Atribute::get_intelligence()
{
	return this->intelligence;
}

atribut_type Atribute::get_wisdom()
{
	return this->wisdom;
}

atribut_type Atribute::get_charisma()
{
	return this->charisma;
}

atribut_type Atribute::getAtribut_by_name(std::string atr)
{
	if (atr == "strenght")
		return this->strenght;
	if (atr == "dexterity")
		return this->dexterity;
	if (atr == "constitution")
		return this->constitution;
	if (atr == "intelligence")
		return this->intelligence;
	if (atr == "wisdom")
		return this->wisdom;
	if (atr == "charisma")
		return this->charisma;

	throw new Exceptie("eroare in functia Atribute::getAtribut_by_name din atribute.cpp deoarece s-a cautat un atribut care nu exista.\n");
}

void Atribute::interactiune_esuata(std::string atr)
{
	if (atr == "strenght")
	{
		this->strenght -= 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "dexterity")
	{
		this->dexterity -= 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "constitution")
	{
		this->constitution -= 1;
		test_min_max_atribute(this);
		return;

	}
	if (atr == "intelligence")
	{
		this->intelligence -= 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "wisdom")
	{
		this->wisdom -= 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "charisma")
	{
		this->charisma -= 1;
		test_min_max_atribute(this);
		return;
	}
}

void Atribute::interactiune_reusita(std::string atr)
{
	if (atr == "strenght")
	{
		this->strenght+= 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "dexterity")
	{
		this->dexterity += 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "constitution")
	{
		this->constitution += 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "intelligence")
	{
		this->intelligence += 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "wisdom")
	{
		this->wisdom += 1;
		test_min_max_atribute(this);
		return;
	}
	if (atr == "charisma")
	{
		this->charisma += 1;
		test_min_max_atribute(this);
		return;
	}
}

void Atribute::print_atribute()
{
	std::cout << "\033[1;33m";
	std::cout << "			"<<"Strenght: " << this->strenght<<std::endl;
	std::cout << "			" << "dexterity: " << this->dexterity << std::endl;
	std::cout << "			" << "constitution: " << this->constitution << std::endl;
	std::cout << "			" << "intelligence: " << this->intelligence << std::endl;
	std::cout << "			" << "wisdom: " << this->wisdom << std::endl;
	std::cout << "			" << "charisma: " << this->charisma << std::endl;
	std::cout << "\033[0m";
}

atribut_type calcul_procent(atribut_type atr, int procent)
{
	atribut_type temp = procent * atr / 100;
	return temp;
}




void Atribute::set_atribute_rasa(IRasa* rasa)
{
	if (rasa->getRasa() == ORC)
	{
		this->intelligence -= calcul_procent(this->intelligence, 35);
		this->charisma -= calcul_procent(this->charisma, 35);
		this->constitution -= calcul_procent(this->constitution, 25);
		this->wisdom -= calcul_procent(this->wisdom, 35);

		this->strenght += calcul_procent(this->strenght, 65);
		this->dexterity += calcul_procent(this->dexterity, 65);
	}
	else if (rasa->getRasa() == ELF)
	{
		this->intelligence += calcul_procent(this->intelligence, 50);
		this->wisdom += calcul_procent(this->wisdom, 50);

		this->strenght -= calcul_procent(this->strenght, 50);
		this->dexterity -= calcul_procent(this->dexterity, 50);
	}
	else if (rasa->getRasa() == HUMAN)
	{
		this->constitution += calcul_procent(this->constitution, 20);
		this->charisma += calcul_procent(this->charisma, 40);

		this->wisdom -= calcul_procent(this->wisdom, 50);
		this->dexterity -= calcul_procent(this->dexterity, 50);
	}
	else if (rasa->getRasa() == GOBLIN)
	{
		this->strenght += calcul_procent(this->strenght, 50);
		this->dexterity += calcul_procent(this->dexterity, 50);

		this->intelligence -= calcul_procent(this->intelligence, 50);
		this->charisma -= calcul_procent(this->charisma, 50);
	}

	test_min_max_atribute(this);
}



void Atribute::set_atribute_trecut(Trecut trecut)
{

	if (trecut == MAGICIAN)
	{
		this->intelligence += calcul_procent(this->intelligence, 35);
		this->wisdom += calcul_procent(this->wisdom, 35);

		this->strenght -= calcul_procent(this->strenght, 15);
		this->constitution -= calcul_procent(this->constitution, 15);
		this->dexterity -= calcul_procent(this->dexterity, 15);
		this->charisma -= calcul_procent(this->charisma, 15);
	}
	else if (trecut == SOLDAT)
	{
		this->intelligence -= calcul_procent(this->intelligence, 15);
		this->charisma -= calcul_procent(this->charisma, 15);
		this->constitution -= calcul_procent(this->constitution, 15);
		this->wisdom -= calcul_procent(this->wisdom, 15);

		this->strenght += calcul_procent(this->strenght, 35);
		this->dexterity += calcul_procent(this->dexterity, 35);
	}
	else if (trecut == ACOLIT)
	{
		this->constitution += calcul_procent(this->constitution, 20);
		this->charisma += calcul_procent(this->charisma, 35);

		this->wisdom -= calcul_procent(this->wisdom, 25);
		this->dexterity -= calcul_procent(this->dexterity, 25);
	}
	else if (trecut == HOT)
	{
		this->intelligence += calcul_procent(this->intelligence, 25);
		this->dexterity += calcul_procent(this->dexterity, 25);


		this->strenght -= calcul_procent(this->strenght, 20);
		this->charisma -= calcul_procent(this->charisma, 20);
		this->wisdom -= calcul_procent(this->wisdom, 20);
	}


	test_min_max_atribute(this);
}

void Atribute::set_atribute_clasa(IClasa* clasa)
{
	if (clasa->getClasa() == FIGHTER)
	{
		this->charisma -= calcul_procent(this->charisma, 30);
		this->intelligence -= calcul_procent(this->intelligence, 30);
		this->wisdom -= calcul_procent(this->wisdom, 30);

		this->strenght += calcul_procent(this->strenght, 55);
		this->dexterity += calcul_procent(this->dexterity, 55);
		this->constitution += calcul_procent(this->constitution, 10);
	}
	else if (clasa->getClasa() == SORCERER)
	{
		this->intelligence += calcul_procent(this->intelligence, 65);
		this->wisdom += calcul_procent(this->wisdom, 65);

		this->strenght -= calcul_procent(this->strenght, 30);
		this->constitution -= calcul_procent(this->constitution, 15);
		this->dexterity -= calcul_procent(this->dexterity, 30);
		this->charisma -= calcul_procent(this->charisma, 30);
	}
	else if (clasa->getClasa() == WARRIOR)
	{
		this->strenght += calcul_procent(this->strenght, 100);

		this->intelligence -= calcul_procent(this->intelligence, 45);
		this->wisdom -= calcul_procent(this->wisdom, 45);
		this->dexterity -= calcul_procent(this->dexterity, 45);
	}
	else if (clasa->getClasa() == NINJA)
	{
		this->intelligence += calcul_procent(this->intelligence, 50);
		this->dexterity += calcul_procent(this->dexterity, 50);
		this->constitution += calcul_procent(this->constitution, 20);

		this->strenght -= calcul_procent(this->strenght, 50);
		this->charisma -= calcul_procent(this->charisma, 50);
		this->wisdom -= calcul_procent(this->wisdom, 50);
	}

	test_min_max_atribute(this);
}

