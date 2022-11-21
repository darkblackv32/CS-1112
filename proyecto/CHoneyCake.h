
#include "CAlimento.h"

class HoneyCake : public Alimento
{
private:
public:
    HoneyCake(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = 5;
    //     this->cantidad = cant;
    // }   
    virtual ~HoneyCake();
};