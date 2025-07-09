#include "CARasa.h"

CARasa::CARasa(rasa_nume temp_rasa) : rasa(temp_rasa)
{

}

rasa_nume CARasa::getRasa()
{
    return this->rasa;
}

//void CARasa::print_atribute()
//{
//	this->atribute.print_atribute();
//}
