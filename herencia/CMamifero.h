#ifndef HERENCIAANIMAL_CMAMIFERO_H
#define HERENCIAANIMAL_CMAMIFERO_H

#include "CAnimal.h"
class CMamifero: public CAnimal {
private:
public:
    CMamifero(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso, TipoEntero mCantAlimento): 
        CAnimal(mGenero, mRegionVive, mNombre, mPeso, mCantAlimento) {}
};


#endif //HERENCIAANIMAL_CMAMIFERO_H
