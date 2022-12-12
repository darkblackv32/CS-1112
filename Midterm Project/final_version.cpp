#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

void aleatorio(float *a);
void mercedes(float i,long int *recorrido, long int *sucesiones);
void redbull(float i,long int *recorrido, long int *sucesiones);
void ferrari(float i,long int *recorrido, long int *sucesiones);
void mclaren(float i,long int *recorrido, long int *sucesiones);
void renault(float i,long int *recorrido, long int *sucesiones);
void sauber(float i,long int *recorrido, long int *sucesiones);
void williams(float i,long int *recorrido, long int *sucesiones);
void lotus(float i,long int *recorrido, long int *sucesiones);
void Ordenar(int arr[]);


int main(){
    srand(time(NULL));
    float a_mercedes,a_redbull,a_ferrari,a_mclaren,a_renault,a_sauber,a_williams,a_lotus;
    float *b_mercedes,*b_redbull,*b_ferrari,*b_mclaren,*b_renault,*b_sauber,*b_williams,*b_lotus;
    long int r_mercedes = 0,r_redbull = 0,r_ferrari = 0,r_mclaren = 0,r_renault = 0,r_sauber = 0,r_williams = 0,r_lotus = 0;
    long int *d_mercedes,*d_redbull,*d_ferrari,*d_mclaren,*d_renault,*d_sauber,*d_williams,*d_lotus;
    long int s_mercedes = 1,s_redbull = 1,s_ferrari = 1,s_mclaren = 1,s_renault = 1,s_sauber = 1,s_williams = 1,s_lotus = 1;
    long int *i_mercedes,*i_redbull,*i_ferrari,*i_mclaren,*i_renault,*i_sauber,*i_williams,*i_lotus;
    
    b_mercedes = &a_mercedes;
    d_mercedes = &r_mercedes;
    i_mercedes = &s_mercedes;

    b_redbull = &a_redbull;
    d_redbull = &r_redbull;
    i_redbull = &s_redbull;

    b_ferrari = &a_ferrari;
    d_ferrari = &r_ferrari;
    i_ferrari = &s_ferrari;

    b_mclaren = &a_mclaren;
    d_mclaren = &r_mclaren;
    i_mclaren = &s_mclaren;

    b_renault = &a_renault;
    d_renault = &r_renault;
    i_renault = &s_renault;

    b_sauber = &a_sauber;
    d_sauber = &r_sauber;
    i_sauber = &s_sauber;

    b_williams = &a_williams;
    d_williams = &r_williams;
    i_williams = &s_williams;

    b_lotus = &a_lotus;
    d_lotus = &r_lotus;
    i_lotus = &s_lotus;


    do{
        aleatorio(b_mercedes);
        mercedes(a_mercedes,d_mercedes,i_mercedes);
    }while(r_mercedes<300000);

    do{
        aleatorio(b_redbull);
        mercedes(a_redbull,d_redbull,i_redbull);
    }while(r_redbull<300000);
    
    do{
        aleatorio(b_ferrari);
        mercedes(a_ferrari,d_ferrari,i_ferrari);
    }while(r_ferrari<300000);
    
    do{
        aleatorio(b_mclaren);
        mercedes(a_mclaren,d_mclaren,i_mclaren);
    }while(r_mclaren<300000);
    
    do{
        aleatorio(b_renault);
        mercedes(a_renault,d_renault,i_renault);
    }while(r_renault<300000);
    
    do{
        aleatorio(b_sauber);
        mercedes(a_sauber,d_sauber,i_sauber);
    }while(r_sauber<300000);
    
    do{
        aleatorio(b_williams);
        mercedes(a_williams,d_williams,i_williams);
    }while(r_williams<300000);
    
    do{
        aleatorio(b_lotus);
        mercedes(a_lotus,d_lotus,i_lotus);
    }while(r_lotus<300000);
    

    // cout<<"Mercedes termino la carrera en "<<s_mercedes<<" pasos"<<endl;
    // cout<<"Red Bull termino la carrera en "<<s_redbull<<" pasos"<<endl;
    // cout<<"Ferrari termino la carrera en "<<s_ferrari<<" pasos"<<endl;
    // cout<<"MClaren termino la carrera en "<<s_mclaren<<" pasos"<<endl;
    // cout<<"Renault termino la carrera en "<<s_renault<<" pasos"<<endl;
    // cout<<"Sauber termino la carrera en "<<s_sauber<<" pasos"<<endl;
    // cout<<"Williams termino la carrera en "<<s_williams<<" pasos"<<endl;
    // cout<<"Lotus termino la carrera en "<<s_lotus<<" pasos"<<endl;

    int pas[8] = {s_mercedes,s_redbull, s_ferrari, s_mclaren, s_renault, s_sauber, s_williams, s_lotus}; 

    Ordenar(pas);
}

void aleatorio(float *a){
    *a = ((rand( ) % 101 ) / 100.0f );
}

void mercedes(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void redbull(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void ferrari(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stopff
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void mclaren(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void renault(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void sauber(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void williams(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void lotus(float i,long int *recorrido, long int *sucesiones){
    if(i > 0.8){
        *recorrido += 83; //Avance rapido
    }
    else if(i >= 0.6 && i <= 0.8){
        *recorrido += 50; //Competencia
    }
    else if(i >= 0.4 && i <= 0.6){
        *recorrido += 30; //Trafico
    }
    else if(i >= 0.2 && i <= 0.4){
        *sucesiones +=2; //Pit-Stop
    }
    else if(i>= 0.04 && i <= 0.2){
        *recorrido -= 10; //Obstruccion
    }
    else if(i == 0.03){
        *recorrido += 13; //drive-through
    }
    else if(i == 0.02){
        *sucesiones += 4; //stop-and-go de cinco segundos,
    }
    else if(i == 0.01){
        *sucesiones += 9; //stop-and-go de diez segundos,
    }
    *sucesiones += 1;
}

void Ordenar(int array[]){
    int aux;
	
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0; j < 7 ; j++){
			if(array[j] > array[j+1]){
				aux = array[j];
				array[j] = array[j+1];
				array[j+1] = aux;
			}
		}
	}
	
	
	for(int i = 7 ; i >= 0 ; i--){
		cout<<"Puesto["<<8-i<<"]: "<<""<<array[i]<<" pasos"<<endl;
	}
}