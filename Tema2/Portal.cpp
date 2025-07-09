#include "Portal.h"

Portal::Portal(int diff, std::string name, std::string atr, Room* portal): Difficulty(diff), nume(name), atribut(atr), teleport(portal)
{
}

Portal::Portal(int diff, std::string name, std::string atr, std::string nume_teleport): Difficulty(diff), nume(name), atribut(atr), nume_camera_teleport(nume_teleport)
{
}

std::string Portal::getNume_camera_teleport()
{
    return this->nume_camera_teleport;
}

std::string Portal::getNume()
{
    return this->nume;
}

void Portal::prezinta_portal()
{
    std::cout << "\033[1;33m";
    std::cout << this->nume << " " << this->atribut << " Duce spre " << this->nume_camera_teleport << std::endl;
    std::cout << "\033[0m";

}

int Portal::getDifficulty()
{
    return this->Difficulty;
}

std::string Portal::getAtribut()
{
    return this->atribut;
}

Room* Portal::getCamera_teleport()
{
   return this->teleport;
}
