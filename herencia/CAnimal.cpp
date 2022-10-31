#include "CAnimal.h"

CAnimal::CAnimal(TipoCaracter pGenero, 
            const TipoString &pRegionVive, 
            const TipoString &pNombre, 
            TipoDecimal pPeso,
            TipoEntero pCantAlimento)
{
    (*this).m_Genero = pGenero;
    this->m_RegionVive = pRegionVive;
    this->m_Nombre = pNombre;
    this->m_Peso = pPeso;
    (*this).m_CantAlimento = pCantAlimento;
}