#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <chrono>
#include <limits>
#include <random>
using namespace std;

// UTILITIES
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int random (int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }


class tanque{
private:
    int capacidad = 0;
public:
    tanque() = default;
    tanque(int c): capacidad{c}{};

    void bombear(){
        auto aumento = random(1, 20);
        cout << "bombear " << aumento << endl;

        capacidad += aumento;
    }
    bool repartir(){
        auto to_repatir = random(1, 20);
        // cout << "repartir " << to_repatir << endl;

        if (to_repatir > this->capacidad)
            return false;
        this->capacidad -= to_repatir;
        return true;
    }
    auto get_capacidad() { return capacidad; }
};

int main()
{
    tanque *t_A = new tanque(10), *t_B = new tanque(10);
    int contador = 0;
    bool flag = true;
    cout << "\ttanque A\n";
    while (flag){
        t_A->bombear();
        contador++;
        flag = t_A->repartir();
    }

    cout << "\ttanque B\n";
    flag = true;
    while (flag){
        t_B->bombear();
        contador++;
        flag = t_B->repartir();
    }

    cout << "Cantidad total de bombeos: " << contador << endl;
    cout << "Capacidad restante:\n";
    cout << "\tA: " << t_A->get_capacidad() << endl;
    cout << "\tB: " << t_B->get_capacidad() << endl;
}