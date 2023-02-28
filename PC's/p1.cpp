#include "p1.h"


int main(){

    // Troncal t1;
    // Alimentador t2;
    // Expreso t3;
    // Regular t4;

    Usuario Juan("Juan","Altomayo","General",0); // USUARIO SIN SALDO

    cout<<Juan.getSaldo();

    cout<<endl;

    cout << Juan; // MOSTRAR DATOS DEL USUARIO
    
    Usuario Carlos("Carlos","Salazar","General",23.25); // USUARIO CON SALDO

    cout<<Juan.getSaldo();

    cout<<endl;

    cout << Carlos; // MOSTRAR DATOS DEL USUARIO

    cout<<endl;

    Carlos.setOpcion(Carlos);


    return 0;
}

