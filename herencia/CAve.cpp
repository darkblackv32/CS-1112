#include "CAve.h"

CAve::~CAve() {}

CAve::CAve(TipoCaracter mGenero, const TipoString &mRegionVive, const TipoString &mNombre, TipoDecimal mPeso,
           TipoEntero mCantAlimento) : CAnimal(mGenero, mRegionVive, mNombre, mPeso, mCantAlimento) {}
