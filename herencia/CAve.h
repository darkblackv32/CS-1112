#ifndef HERENCIAANIMAL_CAVE_H
#define HERENCIAANIMAL_CAVE_H

#include "CAnimal.h"
class CAve: public CAnimal {
private:
public:
    CAve();
    ~CAve();
    CAve(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
         TipoEntero mCantAlimento);
};
#endif //HERENCIAANIMAL_CAVE_H
