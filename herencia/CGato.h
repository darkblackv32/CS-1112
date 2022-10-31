#ifndef HERENCIAANIMAL_CGATO_H
#define HERENCIAANIMAL_CGATO_H

#include "CDomestico.h"
class CGato: public CDomestico {
private:
    TipoEntero m_Vidas;
public:
    CGato(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
          TipoEntero mCantAlimento);
    virtual ~CGato();
    TipoEntero getVidas();
    void ProduceSonido(ostream &os);
    void Alimentar(ostream &os,CAlimento* pAlimento);
    void ExpresionFelicidad(ostream &os);
};
#endif //HERENCIAANIMAL_CGATO_H
