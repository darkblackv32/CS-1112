#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
    int s_mercedes = 1,s_lotus = 2,s_redbull = 3,s_williams = 4,s_sauber =5,s_ferrari = 26,s_renault = 7,s_mclaren = 1;

    vector<pair<int,string>>v1;
    v1 = {{s_mercedes,"Mercedes"},{s_lotus,"Lotus"},{s_redbull,"Red Bull"},{s_williams,"Williams"},{s_sauber,"Sauber"},{s_ferrari,"Ferrari"},{s_renault,"Renault"},{s_mclaren,"MClaren"}};
    
    int aux;
	
	for(int i = 0 ; i < 8 ; i++){
		for(int j = 0; j < 7 ; j++){
			if(v1[j].first > v1[j+1].first){
				aux = v1[j].first;
				v1[j].first = v1[j+1].first;
				v1[j+1].first = aux;
			}
		}
	}

    for(int i = 7 ; i >= 0 ; i--){
		cout<<"Puesto["<<8-i<<"]: "<<v1[i].second<<" con "<<v1[i].first<<" pasos"<<endl;
	}
    cout<<"\n";
    
}
