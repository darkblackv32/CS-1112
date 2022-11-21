#include "CAlimento.h"

class Abarrote : public Alimento
{
private:
public:
    Abarrote(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = 2;
    //     this->cantidad = cant;
    // }   
    virtual ~Abarrote();
    
};