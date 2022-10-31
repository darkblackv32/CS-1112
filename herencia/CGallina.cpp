#include "CGallina.h"

CGallina::~CGallina() {}

CGallina::CGallina(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
                   TipoEntero mCantAlimento) : CAve(mGenero, mRegionVive, mNombre, mPeso, mCantAlimento) {}

void CGallina::ProduceSonido(ostream &os){   
    os<<m_Nombre<<" la gallina dijo: Cluclk"<<endl;
}
void CGallina::Alimentar(ostream &os,CAlimento* pAlimento){
 os<<m_Nombre<<" en proceso de implementación la alimentación"<<endl;
}
