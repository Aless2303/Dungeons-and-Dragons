#include "Factory_clasa.h"

clasa_nume convert_string_to_clasa(std::string nume_clasa)
{
    if (nume_clasa == "FIGHTER")
        return FIGHTER;
    else if (nume_clasa == "SORCERER")
        return SORCERER;
    else if (nume_clasa == "WARRIOR")
        return WARRIOR;
    else if (nume_clasa == "NINJA")
        return NINJA;
    else
        throw new Exceptie("Eroare. Ai introdus numele clasei gresit.");
}

IClasa* Factory_clasa::getClasa(std::string nume_rasa)
{
    IClasa* clasa = nullptr;
    clasa_nume temp_rasa = convert_string_to_clasa(nume_rasa);
    switch (temp_rasa)
    {
    case clasa_nume::FIGHTER:
        clasa = new Fighter();
        return clasa;
        break;
    case clasa_nume::SORCERER:
        clasa = new Sorcerer();
        return clasa;
        break;
    case clasa_nume::WARRIOR:
        clasa = new Warrior();
        return clasa;
        break;
    case clasa_nume::NINJA:
        clasa = new Ninja();
        return clasa;
        break;
    default:
        return clasa;
        break;
    }
}
