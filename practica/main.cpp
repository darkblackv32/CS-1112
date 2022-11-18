#include "p1.h"

int main()
{
#ifndef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pregunta1();
    return 0;
}
// g++ main.cpp p1.cpp p1.h -std=c++17 && ./a.out && rm ./a.out