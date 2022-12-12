#include <iostream>
using namespace std;

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
    
	string carro[8] = {"Mercedes","Red Bull","Ferrari","MClaren","Renault","Sauber","Williams","Lotus"}; 
    
	cout<<"\n";
    cout<<"\n";
	for(int i = 7 ; i >= 0 ; i--){
		cout<<"Puesto["<<8-i<<"]: "<<watch(array[i])<<" con "<<array[i]<<" pasos"<<endl;
	}
    cout<<"\n";
}
int main(){

    int s_mercedes = 123, s_redbull = 45, s_ferrari = 432, s_mclaren = 98, s_renault = 764, s_sauber = 678, s_williams = 798, s_lotus = 543;
    int pas[8] = {s_mercedes,s_redbull, s_ferrari, s_mclaren, s_renault, s_sauber, s_williams, s_lotus}; 
    Ordenar(pas);

    return 0;
}