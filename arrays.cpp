#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

// class, struct -> tipos de dato compuesto (user-defined)
//               -> componen de otros tipos datos (base | compuesto)

// NO TIENE PRIVACIDAD
struct alumno {
    string nombre;
    int ciclo;
    alumno() = default;
    alumno(string nn, int cc) : nombre{nn}, ciclo{cc} {}
};

// SI TIENE PRIVACIDAD
class profesor{
private:
    string nombre;
public:
    profesor() = default;
    profesor(string nn)
    {
        this->nombre = nn;
    }
};

struct Universidad {
    profesor* profesores;       // array dinamico | apuntador a otra variable
    alumno* alumnos;
    int aforo;

    Universidad() = default;
};

void teoria()
{
    // ESTATICOS -> STACK   en tiempo de compilacion
    int N; 
    cout << "N: "; cin >> N;
    int array_estatico[N];      // array de N elementos
    
    cout << "ESTATICO\n";
    // 1 nomenclatura para el indexing
    for (size_t i = 0; i < N; i++)
        cout << array_estatico[i] << ", ";
    cout << endl;
    
    // DINAMICOS -> HEAP    en tiempo de ejecucion
    int* array_dinamico = new int[N];       // 4 bytes
    //    array_dinamico -> a1 | a2 | a3 | .... | an |

    for (int i = 0; i < N; i++)
        *(array_dinamico + i) = i*10;       // array_dinamico[i] = i*10;
    
    cout << "DINAMICO DIRECCIONES\n"; 
    // 2 nomenclaturas para el indexing
    for (int i = 0; i < N; i++)
        cout << &array_dinamico[i] << ", ";      // &[i]: accede a la referencia(dir. memoria) de la pos. i en el array
    cout << endl;

    for (int i = 0; i < N; i++)
        cout << array_dinamico + i << ", ";
    cout << endl;

    cout << "DINAMICO VALORES\n"; 
    for (int i = 0; i < N; i++)
        cout << array_dinamico[i] << ", ";      // [i]: accede al valor en la pos. i
    cout << endl;

    for (int i = 0; i < N; i++)
        cout << *(array_dinamico + i) << ", ";
    cout << endl;
    delete[] array_dinamico;
}

int main()
{
    int N; cout << "N: "; cin >> N;
    alumno angello;
    alumno* pointer = &angello;
    
    alumno* aula1 = new alumno[N];      // creando un array de alumnos
    for (size_t i = 0; i < N; i++)
    {   
        alumno* alumno_actual = &aula1[i];
        cin >> (*alumno_actual).nombre >> (*alumno_actual).ciclo;       // dereference operator
        // cin >> alumno_actual->nombre >> alumno_actual->ciclo;           // arrow operator   
    }
    
    for (size_t i = 0; i < N; i++)
    {
        auto alumno_actual = aula1[i];
        cout << alumno_actual.nombre << " " << alumno_actual.ciclo << endl;
    }
    
    return 0;
}

// 0x5568936526d0 + 0 = 0x5568936526d0 
// 0x5568936526d0 + 1*4 = 0x5568936526d4
// 0x5568936526d0 + 2*4 = 0x5568936526d8
// 0x5568936526d0 + 3*4 = 0x5568936526dc
// 0x5568936526d0 + 4*4 = 0x5568936526e0

// HEXADECIMAL   (0-15)
// 0 1 2 3 4 5 6 7 8 9 A B C D E F