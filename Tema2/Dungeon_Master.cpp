#include "Dungeon_Master.h"

Dungeon_Master* Dungeon_Master::instance = nullptr;


Dungeon_Master::Dungeon_Master()
{
    this->player = new Personaj();
}

Dungeon_Master::~Dungeon_Master()
{
    for (Room* room : harta) {
        delete room;
    }
    delete player;
}

Dungeon_Master* Dungeon_Master::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Dungeon_Master;
        atexit(destroyInstanceAtExit);
    }
    return instance;
}

void Dungeon_Master::destroyInstanceAtExit()
{
    if (instance != nullptr)
    {
        //instance = nullptr;
        delete instance;
        instance = nullptr;
    }
}




void Dungeon_Master::citire_mapa_from_file(std::string filename)
{
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw new Exceptie("Eroare la deschidere fisier la citire_mapa_from_file in Dungeon_Master.cpp.\n");
    }

    std::string camera;
    while (fin >> camera)
    {
        Room* temporary_room = new Room();
        temporary_room->set_nume_camera(camera);
        temporary_room->citeste_camera(camera);
        this->harta.push_back(temporary_room);
    }
    fin.close();

    for (auto& it : this->harta)
    {
        it->leaga_portale(this->harta);
        it->leaga_usi(this->harta);
    }

}

bool Dungeon_Master::test_finish_game()
{
    return true;
}

void text_alege_interactiune()
{
    std::cout << "\033[1;33m";
    std::cout << "Alege cu ce vrei sa interactionezi din camera:\n";
    std::cout << "    BOOKS | PORTALS | STATUE | DOORS | ENEMIES\n";
    std::cout << "\033[0m";
}

void enumera_interactiune(std::string inter,Room* camera)
{
    if (camera == nullptr)
        throw new Exceptie("Camera este nullptr in functia enumera_interactiune din Dungeon_master.cpp.\n");

    if (inter == "BOOKS")
    {
        camera->enumera_books();
        return;
    }
    if (inter == "PORTALS")
    {
        camera->enumera_portals();
        return;
    }
    if (inter == "STATUE")
    {
        camera->enumera_statui();
        return;
    }
    if (inter == "DOORS")
    {
        camera->enumera_usi();
        return;
    }
    if (inter == "ENEMIES")
    {
        camera->enumera_inamici();
        return;
    }

    throw new Exceptie("Interactiunea care s-a scris la ecran nu exista.\n");

}

void Dungeon_Master::actualizeaza_camera(Room* camera)
{
    if (camera == nullptr)
        throw new Exceptie("Camera este nullptr in Dungeon_Master::actualizeaza_camera din Dungeon_master.cpp.\n");

    auto it = std::find(this->harta.begin(), this->harta.end(), camera);

    if(it != this->harta.end())
    {
        std::rotate(this->harta.begin(), it, it + 1);
    }
}


void afisare_prezentare_joc()
{
    std::cout << "\033[1;35m";
    std::cout << "Bun venit la Dungeon&Dragons.\n";
    std::cout << "In acest joc o sa va alegeti rasa/clasa/trecutul si un nume pentru a va crea caracterul.\n";
    std::cout << "Odata creat caracterul veti putea parcurge fiecare camera pentru a interactiona cu obiectele acesteia.";
    std::cout << "In functie de ce alegeti sa interactionati, o sa vedeti ca fiecare obiect are un nume si un atribut.\n";
    std::cout << "In functie de fiecare atribut al obiectului, se va calcula un modificator care se va aduna la zarul pe care il veti da (intre 0 si 20).\n";
    std::cout << "Fiecare obiect are o dificultate pentru a reusi interactiunea, daca modificatorul+zarul sunt >= dificultate, interactiunea a reusit, altfel a esuat.\n";
    std::cout << "Fiecare interactiune reusita va creste atributul dumneavoastra cu 1 sau daca a esuat il va scadea cu 1, in functie de atributul necesar pentru acel obiect.\n";
    std::cout << "Nu veti putea vedea dificultatea necesara pentru a reusi interactiunea, trebuie sa stiti doar ca maximul acestora este 20.\n";
    std::cout << "\033[0m";

    std::cout << "\033[1;36m";
    std::cout << "\nIMPORTANT:\n";
    std::cout << "In functie de clasa sau rasa pe care o vei alege ti se vor modifica atributele si vei avea doua abilitati specifice pentru fiecare.\n";
    std::cout << "In paranteza o sa puteti observa procentul cu care se modifica.\n";
    std::cout << "Rase:\n";
    std::cout << "ORC -> ii creste strenght(65)/dexterity(65) si ii scade intelligence(35)/charisma(35)/constitution(25)/wisdom(25).\n";
    std::cout << "    SKILL1 este in functie de strenght\n";
    std::cout << "    SKILL2 este in functie de dexterity\n";
    std::cout << "ELF -> ii creste INTELLIGENCE(50)/WISDOM(50) si ii scade strenght(50)/dexterity(50).\n";
    std::cout << "    SKILL1 este in functie de intelligence\n";
    std::cout << "    SKILL2 este in functie de wisdom\n";
    std::cout << "HUMAN -> ii creste constitution(20)/charisma(40) si ii scade wisdom(50)/dexterity(50).\n";
    std::cout << "    SKILL1 este in functie de charisma\n";
    std::cout << "    SKILL2 este in functie de charisma\n";
    std::cout << "GOBLIN ->ii creste strenght(50)/dexterity(50) si ii scade intelligence(50)/charisma(50).\n";
    std::cout << "    SKILL1 este in functie de strenght\n";
    std::cout << "    SKILL2 este in functie de dexterity\n";
    
    std::cout << "\nClase:\n";
    std::cout << "FIGHTER -> ii creste strenght(55)/dexterity(55)/constitution(10) si ii scade charisma(30)/intelligence(30)/wisdom(30)\n";
    std::cout << "    SKILL1 este in functie de strenght\n";
    std::cout << "    SKILL2 este in functie de dexterity\n";
    std::cout << "SORCERER -> ii creste intelligence(65)/wisdom(55) si ii scade strenght(30)/constitution(15)/dexterity(30)/charisma(30)\n";
    std::cout << "    SKILL1 este in functie de intelligence\n";
    std::cout << "    SKILL2 este in functie de wisdom\n";
    std::cout << "WARRIOR -> ii creste strenght(100) si ii scade intelligence(45)/wisdom(45)/dexterity(45)\n";
    std::cout << "    SKILL1 este in functie de strenght\n";
    std::cout << "    SKILL2 este in functie de strenght\n";
    std::cout << "NINJA -> ii creste intelligence(50)/dexterity(50)/constitution(20) si ii scade strenght(50)/charisma(50)/wisdom(50)\n";
    std::cout << "    SKILL1 este in functie de intelligence\n";
    std::cout << "    SKILL2 este in functie de dexterity\n";

    std::cout << "\nTrecut:\n";
    std::cout << "MAGICIAN -> ii creste intelligence(35)/wisdom(35) si ii scade strenght(15)/constitution(15)/dexterity(15)/charisma(15)\n";
    std::cout << "SOLDAT -> ii creste strenght(35)/dexterity(35) si ii scade strenght(15)/constitution(15)/dexterity(15)/charisma(15)\n";
    std::cout << "ACOLIT -> ii creste constitution(20)/charisma(35) si ii scade wisdom(25)/dexterity(25)\n";
    std::cout << "HOT -> ii creste intelligence(25)/dexterity(25) si ii scade strenght(20)/charisma(20)/wisdom(20)\n";


    std::cout << "\033[0m";

    std::cout << "\033[1;35m";
    std::cout << "\nMult succes in aventura dumneavoastra in Dungeon&Dragons. Va doresc sa reusiti sa parcurgeti tot jocul si sa invingeti toti inamicii.\n";
    std::cout << "SUCCES!!!\n\n\n";
    std::cout << "\033[0m";

}


void Dungeon_Master::startGame(std::string filename_map)
{
    citire_mapa_from_file(filename_map);
    while (test_finish_game() == true)
    {
        //this->player->prezinta_personaj();
        this->player->prezinta_statusuri_hp();
        if (this->harta[0] == nullptr)
            throw new Exceptie("harta[0] in Dungeon_Master::startGame din Dungeon_master.cpp este nullptr.\n");

        std::cout << "\033[1;33m";
        std::cout << std::endl;
        std::cout << "\033[0m";

        this->harta[0]->prezinta_camera();
        text_alege_interactiune();
        std::string interactiune;
        std::cin >> interactiune;
        try {
            enumera_interactiune(interactiune, this->harta[0]);
            this->harta[0]->interactioneaza_obiect(this->player, interactiune);
        }
        catch (IExceptie* ex)
        {
            ex->printMesaj();
        }

        std::cout << "\033[1;33m";
        std::cout << "\n------------------------------------------------------------------------\n";
        std::cout << "\033[0m";
    }

}


