#include "CAlimento.h"

class Hongos : public Alimento
{
private:
public:
    Hongos(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = -10;
    //     this->cantidad = cant;
    // }  
    virtual ~Hongos();
};
