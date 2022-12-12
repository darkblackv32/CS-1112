#include <iostream>
#include "Auto.h"
#include "Vehiculo.h"
#include "Moto.h"
#include <vector>
#include "Sistema.h"
using namespace std;

int main() {
    Sistema* sistema=new Sistema();
    sistema->ejecutar1();

    delete sistema;
    return 0;
}

