#include "CAlimento.h"

CAlimento::CAlimento(TipoString pNombre, TipoEntero pCantidad): m_Nombre{pNombre}, m_Cantidad{pCantidad} {}

TipoEntero CAlimento::getCantidad() {
    return m_Cantidad;
}

TipoString CAlimento::getNombre() {
    return  m_Nombre;
}