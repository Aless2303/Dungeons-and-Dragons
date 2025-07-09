#include "Room.h"
#include"Dungeon_Master.h"

void Room::add_usa_noua(Door usa_add)
{
	this->usi.push_back(usa_add);
}

bool Room::test_exista_usa(Door test_exist)
{
	for (auto& it : this->usi)
	{
		if (it.getDifficulty() == test_exist.getDifficulty() &&
			it.getNume() == test_exist.getNume() &&
			it.getAtribut() == test_exist.getAtribut())
			return true;
	}


	return false;
}

void Room::prezinta_camera()
{
	std::cout << "\033[1;33m";
	std::cout << "Te aflii in camera: " << this->nume_camera << ". In aceasta camera sunt:\n";

	std::cout << "	" <<"BOOKS: " << this->books.size() << std::endl;
	std::cout << "	" << "PORTALS: " << this->portals.size() << std::endl;
	std::cout << "	" << "STATUE: " << this->statui.size() << std::endl;
	std::cout << "	" << "DOORS: " << this->usi.size() << std::endl;
	std::cout << "	" << "ENEMIES: " << this->inamici.size() << std::endl;
	std::cout << "\033[0m";

}

void Room::enumera_books()
{
	for (auto& it : this->books)
		it.prezinta_book();
}

void Room::enumera_portals()
{
	for (auto& it : this->portals)
		it.prezinta_portal();
}

void Room::enumera_statui()
{
	for (auto& it : this->statui)
		it.prezinta_statue();
}

void Room::enumera_usi()
{
	for (auto& it : this->usi)
		it.prezinta_door();
}

void Room::enumera_inamici()
{
	std::cout << "\033[1;33m";
	std::cout << "Inamici sunt de forma: NUME TRECUT RASA CLASA\n";
	std::cout << "\033[0m";
	for (auto& it : this->inamici)
		it->prezinta_inamic();
}

int convert_atribut_to_ability_score(int nr)
{
	return nr / 2 - 5;
}



void Room::interactioneaza_books(Personaj* player)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::interactioneaza_books deoarece player este nullptr.");
	std::string nume_carte;
	std::cout << "\033[1;33m";
	std::cout << "Alege una din carti:\n";
	std::cin >> nume_carte;
	//for (auto& it : this->books)
	for (auto it = this->books.begin(); it != this->books.end();++it)
	{
		if (it->getNume() == nume_carte)
		{
			//duel dice etc
			std::random_device rd;
			std::mt19937 generator(rd());
			std::uniform_int_distribution<int> distribution(0, 20);
			int dice = distribution(generator);

			dice = dice + convert_atribut_to_ability_score(player->getAtribut_by_name(it->getAtribut()));
			if (dice < it->getDifficulty())
			{
				std::cout << "Interactiunea cu cartea a esuat.\n";
				player->interactiune_esuata(it->getAtribut());
			}
			else
			{
				std::cout << "Interactiunea cu cartea a reusit.\n";
				player->interactiune_reusita(it->getAtribut());
				it = this->books.erase(it);
			}
			return;
		}
	}
	std::cout << "	Cartea nu exista, ai scris numele gresit.\n";
	std::cout << "\033[0m";
}

void Room::interactioneaza_portals(Personaj* player)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::interactioneaza_portals deoarece player este nullptr.");
	std::cout << "\033[1;33m";
	std::string nume_portal;
	std::cout << "Alege unul dintre portale:\n";
	std::cin >> nume_portal;
	for (auto it = this->portals.begin(); it != this->portals.end(); ++it)
	{
		if (it->getNume() == nume_portal)
		{
			//duel dice etc
			std::random_device rd;
			std::mt19937 generator(rd());
			std::uniform_int_distribution<int> distribution(0, 20);
			int dice = distribution(generator);

			dice = dice + convert_atribut_to_ability_score(player->getAtribut_by_name(it->getAtribut()));
			if (dice < it->getDifficulty())
			{
				std::cout << "Interactiunea cu portalul a esuat.\n";
				player->interactiune_esuata(it->getAtribut());
			}
			else
			{
				std::cout << "Interactiunea cu portalul a reusit.\n";
				player->interactiune_reusita(it->getAtribut());
				
				Dungeon_Master::getInstance()->actualizeaza_camera(it->getCamera_teleport());

				//it = this->portals.erase(it);
			}
			return;
		}
	}
	std::cout << "	Portalul nu exista, ai scris numele gresit.\n";
	std::cout << "\033[0m";
}

void Room::interactioneaza_statui(Personaj* player)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::interactioneaza_statui deoarece player este nullptr.");
	std::cout << "\033[1;33m";
	std::string nume_statuie;
	std::cout << "Alege una dintre statui:\n";
	std::cin >> nume_statuie;
	for (auto it = this->statui.begin(); it != this->statui.end(); ++it)
	{
		if (it->getNume() == nume_statuie)
		{
			//duel dice etc
			std::random_device rd;
			std::mt19937 generator(rd());
			std::uniform_int_distribution<int> distribution(0, 20);
			int dice = distribution(generator);

			dice = dice + convert_atribut_to_ability_score(player->getAtribut_by_name(it->getAtribut()));
			if (dice < it->getDifficulty())
			{
				std::cout << "Interactiunea cu statuia a esuat.\n";
				player->interactiune_esuata(it->getAtribut());
				return;
			}
			else
			{
				std::cout << "Interactiunea cu statuia a reusit.\n";
				player->interactiune_reusita(it->getAtribut());
				it = this->statui.erase(it);
				return;
			}
		}
	}
	std::cout << "	Statuia nu exista, ai scris numele gresit.\n";
	std::cout << "\033[0m";
}

void Room::interactioneaza_usi(Personaj* player)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::interactioneaza_usi deoarece player este nullptr.");
	std::string nume_usa;
	std::cout << "\033[1;33m";
	std::cout << "Alege una dintre usi:\n";
	std::cin >> nume_usa;
	for (auto it = this->usi.begin(); it != this->usi.end(); ++it)
	{
		if (it->getNume() == nume_usa)
		{
			//duel dice etc
			std::random_device rd;
			std::mt19937 generator(rd());
			std::uniform_int_distribution<int> distribution(0, 20);
			int dice = distribution(generator);

			dice = dice + convert_atribut_to_ability_score(player->getAtribut_by_name(it->getAtribut()));
			if (dice < it->getDifficulty())
			{
				std::cout << "Interactiunea cu usa a esuat.\n";
				player->interactiune_esuata(it->getAtribut());
			}
			else
			{
				std::cout << "Interactiunea cu usa a reusit.\n";
				player->interactiune_reusita(it->getAtribut());

				Dungeon_Master::getInstance()->actualizeaza_camera(it->getCamera_teleport());

				//it = this->portals.erase(it);
			}
			return;
		}
	}
	std::cout << "	Usa nu exista, ai scris numele gresit.\n";
	std::cout << "\033[0m";
}



void lupta_inamic(Personaj* player, Enemy* inamic)
{
	if (inamic == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::lupta_inamic deoarece inamic este nullptr.");
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::lupta_inamic deoarece player este nullptr.");

	std::cout << "\033[1;33m";
	std::cout << "Incepe lupta cu inamicul: " << inamic->getNume() << std::endl;

	while (player->getHP()>0 && inamic->getHP()>0)
	{
		int dmg_player =player->ataca();
		inamic->scade_hp(dmg_player);
		std::cout << "Ai lovit inamicul cu: " << dmg_player << " dmg. Mai are "<<inamic->getHP()<<" HP.\n";

		if (inamic->getHP() <= 0)
		{
			std::cout << "Ai invins inamicul.\n";
			player->setHP_WIN();
			return;
		}

		int dmg_inamic = inamic->atac_random();
		player->scade_hp(dmg_inamic);
		std::cout << "Ai fost lovit cu: " << dmg_inamic << " dmg. Mai ai "<<player->getHP()<<" HP.\n";
		if (player->getHP() <= 0)
		{
			std::cout << "		Ai murit deoarece hp-ul tau a ajuns la 0. Ai pierdut jocul.\n";
			exit(1);
		}

	}
	std::cout << "\033[0m";
}

void Room::interactioneaza_inamici(Personaj* player)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::lupta_inamic deoarece player este nullptr.");
	std::string nume_inamic;
	std::cout << "\033[1;33m";
	std::cout << "Tasteaza numele unuia dintre inamici:\n";
	std::cin >> nume_inamic;
	for (auto it = this->inamici.begin(); it != this->inamici.end();++it )
	{
		if ((*it)->getNume() == nume_inamic)
		{
			player->prezinta_statusuri_hp();
			lupta_inamic(player, *it);
			it = this->inamici.erase(it);
			return;
		}
	}
	std::cout << "	Numele pe care l-ai introdus este gresit, nu exista acest inamic.\n";
	std::cout << "\033[0m";
}

void Room::interactioneaza_obiect(Personaj* player, std::string interac)
{
	if (player == nullptr)
		throw new Exceptie("Eroare in Room.cpp la Room::lupta_inamic deoarece player este nullptr.");
	std::cout << "\033[1;33m";
	if (interac == "BOOKS")
	{
		if (this->books.size() != 0)
			this->interactioneaza_books(player);
		else
			std::cout << "Nu exista carti.\n";
		return;
	}
	if (interac == "PORTALS")
	{
		if (this->portals.size() != 0)
			this->interactioneaza_portals(player);
		else
			std::cout << "nu exista portale.\n";
		return;
	}
	if (interac == "STATUE")
	{
		if (this->statui.size() != 0)
			this->interactioneaza_statui(player);
		else
			std::cout << "Nu exista statui.\n";
		return;
	}
	if (interac == "DOORS")
	{
		if (this->usi.size() != 0)
			this->interactioneaza_usi(player);
		else
			std::cout << "nu exista usi.\n";
		return;
	}
	if (interac == "ENEMIES")
	{
		if (this->inamici.size() != 0)
			this->interactioneaza_inamici(player);
		else
			std::cout << "nu exista inamici.\n";
		return;
	}
	std::cout << "\033[0m";
	throw new Exceptie("Eroare la interactiunea cu un obiect, s-a tastat un obiect gresit.\n");
}



void Room::leaga_usi(std::vector<Room*> harta)
{
	for (auto& it : this->usi)
	{
		for (auto& it2 : harta)
		{
			if (it.getNume_camera_teleport() == it2->get_nume_camera())
			{
				it.set_teleport(it2);
				if(it2->test_exista_usa(it) == false)
				{
					Door usa_noua = it;
					usa_noua.set_nume_camera_usa(this->get_nume_camera());
					usa_noua.set_teleport(this);
					it2->add_usa_noua(usa_noua);
				}
				break;
			}
		}
	}
}

void Room::leaga_portale(std::vector<Room*> harta)
{
	for (auto& it : this->portals)
	{
		for (auto& it2 : harta)
		{
			if (it.getNume_camera_teleport() == it2->get_nume_camera())
			{
				it.set_teleport(it2);
				break;
			}
		}
	}

}

void Room::citeste_inamici(std::string filename)
{
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		throw new Exceptie("Eroare la deschidere fisier la citeste_inamici in Room.cpp.\n");
	}

	int nr_inamici;
	fin >> nr_inamici;
	for (int i = 0; i < nr_inamici; i++)
	{
		Enemy* temporar = new Enemy();
		this->inamici.push_back(temporar);
	}

	fin.close();
}

void Room::citeste_portale(std::string filename)
{
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		throw new Exceptie("Eroare la deschidere fisier la citeste_portale in Room.cpp.\n");
	}

	std::string nume_carte, atribut_carte, nume_teleport;
	int dificultate_carte;
	while (fin >> nume_carte >> dificultate_carte >> atribut_carte>> nume_teleport)
	{
		Portal temp(dificultate_carte, nume_carte, atribut_carte,nume_teleport);
		this->portals.push_back(temp);
	}

	fin.close();
}

void Room::citeste_statui(std::string filename)
{
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		throw new Exceptie("Eroare la deschidere fisier la citeste_statui in Room.cpp.\n");
	}

	std::string nume_carte, atribut_carte;
	int dificultate_carte;
	while (fin >> nume_carte >> dificultate_carte >> atribut_carte)
	{
		Statue temp(dificultate_carte, nume_carte, atribut_carte);
		this->statui.push_back(temp);
	}

	fin.close();
}

void Room::citeste_usi(std::string filename)
{
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		throw new Exceptie("Eroare la deschidere fisier la citeste_usi in Room.cpp.\n");
	}

	std::string nume_carte, atribut_carte, nume_teleport;
	int dificultate_carte;
	while (fin >> nume_carte >> dificultate_carte >> atribut_carte >> nume_teleport)
	{
		Door temp(dificultate_carte, nume_carte, atribut_carte, nume_teleport);
		this->usi.push_back(temp);
	}

	fin.close();
}

void Room::citeste_carti(std::string filename)
{
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		throw new Exceptie("Eroare la deschidere fisier la citeste_carti in Room.cpp.\n");
	}

	std::string nume_carte,  atribut_carte;
	int dificultate_carte;
	while (fin >> nume_carte >> dificultate_carte >> atribut_carte)
	{
		Book temp(dificultate_carte, nume_carte, atribut_carte);
		this->books.push_back(temp);
	}

	fin.close();
}

void Room::citeste_camera(std::string filename)
{
	this->citeste_carti(filename + "_Carte.txt");
	this->citeste_portale(filename + "_Portal.txt");
	this->citeste_statui(filename + "_Statuie.txt");
	this->citeste_usi(filename + "_Usa.txt");
	this->citeste_inamici(filename + "_Enemy.txt");
}
