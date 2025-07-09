#include "IClasa.h"


std::ostream& operator<<(std::ostream& os, const clasa_nume& clasa)
{
    switch (clasa)
    {
    case EROARE_CLASA:
        throw new Exceptie("EROARE_CLASA la supraincarcarea operatorului << pentru enum clasa_nume.");
        break;
    case FIGHTER:
        os << "FIGHTER";
        break;
    case SORCERER:
        os << "SORCERER";
        break;
    case WARRIOR:
        os << "WARRIOR";
        break;
    case NINJA:
        os << "NINJA";
        break;
    default:
        throw new Exceptie("EROARE_CLASA la supraincarcarea operatorului << pentru enum clasa_nume.");
        break;
    }

    return os;
}
