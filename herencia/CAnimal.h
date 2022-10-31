#ifndef HERENCIAANIMAL_CANIMAL_H
#define HERENCIAANIMAL_CANIMAL_H

#include "Tipos.h"
#include "CAlimento.h"
class CAnimal {
private:
    TipoCaracter m_Genero;
    TipoString m_RegionVive;
protected:
    TipoString m_Nombre;
    TipoDecimal m_Peso;
    TipoEntero m_CantAlimento;
public:
    CAnimal(TipoCaracter, const TipoString&, const TipoString&, TipoDecimal, TipoEntero);
    virtual ~CAnimal() = 0;
    
    TipoCaracter getGenero() const { return m_Genero; };
    const TipoString &getRegionVive() const { return m_RegionVive; };
    const TipoString &getNombre() const { return m_Nombre; };
    TipoDecimal getPeso() const { return m_Peso; };
    TipoEntero getCantAlimento() const { return m_CantAlimento; };

    virtual void ProduceSonido(ostream &os) = 0;
    virtual void Alimentar(ostream &os, CAlimento* pAlimento) = 0;
};

#endif //HERENCIAANIMAL_CANIMAL_H
