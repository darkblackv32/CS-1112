#ifndef HERENCIAANIMAL_UFUNCIONES_H
#define HERENCIAANIMAL_UFUNCIONES_H

#include "CGato.h"
#include "CPerro.h"
#include "CGallina.h"

ostream& operator<<(ostream& os,CAnimal &rAnimal)
{   os<<"\n------- Datos del Animal ------\n";
    os << "Nombre         : " << rAnimal.getNombre() << "\n";
    os << "Cantidad Comida: " << rAnimal.getCantAlimento() << "\n";
    os << "Peso           : " << rAnimal.getPeso()  << "\n";
    os << "Género         : " << rAnimal.getGenero() << "\n";
    os << "Región         : " << rAnimal.getRegionVive() << "\n";
    return os;
}
ostream& operator<<(ostream& os,CGato &rGato)
{
    CAnimal &rAnimal = rGato;
    os << rAnimal;
    rGato.ProduceSonido(os);
    rGato.ExpresionFelicidad(os);
    return os;
}
ostream& operator<<(ostream& os,CPerro &rPerro)
{
    CAnimal &rAnimal = rPerro;
    os << rAnimal;
    rPerro.ProduceSonido(os);
    rPerro.ExpresionFelicidad(os);
    return os;
}
ostream& operator<<(ostream& os,CGallina &rGallina)
{
    CAnimal &rAnimal = rGallina;
    os << rAnimal;
    rGallina.ProduceSonido(os);
    return os;
}
#endif 