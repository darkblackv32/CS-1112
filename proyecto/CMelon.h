#include "CAlimento.h"

class Melon : public Alimento
{
public:
    Melon(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = 1;
    //     this->cantidad = cant;
    // }   
    virtual ~Melon();
};