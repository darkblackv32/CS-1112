#include "CGato.h"

CGato::CGato(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
                 TipoEntero mCantAlimento) : CDomestico(mGenero, mRegionVive, mNombre, mPeso, mCantAlimento) {}
CGato::~CGato() {}
TipoEntero CGato::getVidas()  {
    return m_Vidas;
}

void CGato::ProduceSonido(ostream &os) {
    os<<m_Nombre<<" el gato dijo: Miauuuu"<<endl;
}
void CGato::ExpresionFelicidad(ostream &os){
    os<<m_Nombre<<" ronronea"<<endl;
}
void CGato::Alimentar(ostream &os,CAlimento* pAlimento) {
    if(pAlimento->getNombre()=="Carne"){
        float cantAlimento = 0.3 * pAlimento->getCantidad();
        m_Peso +=cantAlimento;
        m_CantAlimento+=pAlimento->getCantidad();
        os<<m_Nombre<<" está comiendo "<<pAlimento->getNombre()<<" y su peso actual es: "<<m_Peso<<endl;
    }
    else{
        os<<m_Nombre<<" el gato no quiere comer "<<pAlimento->getNombre()<<endl;
    }
}