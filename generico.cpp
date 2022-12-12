
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&v){
    int i, j ,aux;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size();j++){
            if(v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}
    
int main(){

    vector<int>v1 = {14,2,8,10,56};

    merge(v1);

    for(size_t i = 4; i >= v1.size(); --i){
        cout<<v1[i]<<" ";
    }






    return 0;
}