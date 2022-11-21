#include "CAlimento.h"

class Manzana : public Alimento
{
private:
public:
    Manzana(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = 1;
    //     this->cantidad = cant;
    // }   
    virtual ~Manzana();
};
