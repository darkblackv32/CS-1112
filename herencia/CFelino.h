#ifndef HERENCIAANIMAL_CFELINO_H
#define HERENCIAANIMAL_CFELINO_H

#include "CMamifero.h"
class CFelino: public CMamifero {
private:
public :
    virtual ~CFelino();

    CFelino(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
            TipoEntero mCantAlimento);
};
#endif //HERENCIAANIMAL_CFELINO_H
