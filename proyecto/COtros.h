#include "CAlimento.h"

class Otros : public Alimento
{
private:
public:
    Otros(int cant) /*: Alimento(puntos, cant)*/;
    // {   
    //     this->puntos = -1;
    //     this->cantidad = cant;
    // }  
    virtual ~Otros();
};