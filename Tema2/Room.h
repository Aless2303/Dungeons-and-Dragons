#pragma once

#include<vector>
#include<fstream>
#include"Book.h"
#include"Statue.h"
#include"Portal.h"
#include"Door.h"
#include"Enemy.h"

class Door;
class Portal;
class Room
{
private:
	std::string nume_camera;
	std::vector<Book> books;
	//vector portale
	std::vector<Portal> portals;
	//vector statui
	std::vector<Statue> statui;
	//vector usi
	std::vector<Door> usi;
	//vector inamici
	std::vector<Enemy*> inamici;

public:
	Room() = default;

	void set_nume_camera(std::string nume) { this->nume_camera = nume; };
	std::string get_nume_camera() { return this->nume_camera; };
	void add_usa_noua(Door usa_add);

	bool test_exista_usa(Door test_exist);

	void prezinta_camera();
	void enumera_books();
	void enumera_portals();
	void enumera_statui();
	void enumera_usi();
	void enumera_inamici();

	void interactioneaza_books(Personaj* player);
	void interactioneaza_portals(Personaj* player);
	void interactioneaza_statui(Personaj* player);
	void interactioneaza_usi(Personaj* player);
	void interactioneaza_inamici(Personaj* player);

	void interactioneaza_obiect(Personaj* player, std::string interac);

	void leaga_usi(std::vector<Room*> harta);
	void leaga_portale(std::vector<Room*> harta);

	void citeste_inamici(std::string filename);
	void citeste_portale(std::string filename);
	void citeste_statui(std::string filename);
	void citeste_usi(std::string filename);
	void citeste_carti(std::string filename);
	void citeste_camera(std::string filename);
};

