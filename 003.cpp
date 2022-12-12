#include <iostream>
using namespace std;



void generarAleatorio(float a1);
void Avanzar(float x, int pasos);


int main( ) {
    float a1;
   
    int auto1 = 200;


    generarAleatorio(a1);
    
    Avanzar(a1, auto1);

    // generarAleatorio(a1);
    
    // Avanzar(a1, auto1);

    
    
    
    
  return 0;
}

void Avanzar(float x, int pasos){
    if(x > 0.8){
        pasos += 83;
    }
    else if(x >= 0.6 and x <= 0.8){
        pasos += 50;
    }
    else if(x >= 0.4 and x <= 0.6){
        pasos += 30;
    }
    else if(x >= 0.2 and x <= 0.4){
        pasos -= 2;
    }
    else if(x <= 0.2){
        pasos -= 10;
    }
    cout<<"Pasos: "<<pasos<<endl;
}

void generarAleatorio(float a1){
    
    srand( time( NULL ) );

    a1 = ((rand( ) % 1001 ) / 1000.0f );
   

    cout<<"Velocidad a1: "<<a1<<endl;
}
    
