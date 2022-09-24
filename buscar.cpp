
bool buscarPalabra(char **M, int filas, int columnas, string buscar)
{
    bool flag = false;          // esto significa si encontre la palabra o no

    // itero sobre toda la matriz
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            if(M[i][j] == buscar[0])        // encuentro la posicion de la primera letra
            {
                flag = buscarAbajo(M, filas, columnas, buscar, i ,j);       // busco hacia abajo desde la primera letra (que ya encontre su posicion)
                
                if (flag == true)
                {
                    cout << "Se encuentra en la pos["<<i<<"]["<<j<<"]" << endl;
                    break;
                }    
            }
        }
        if (flag)
            break;
    }
    return flag;
}

bool buscarAbajo(char **M, int filas, int columnas, string buscar, int i2, int j2)
{
    // Comparo la letra en posicion x del string con la letra de la matriz en la posicion i2+x, j2, si es que i2+x, j2 es una posicion valida
    // Si termine de comparar con todas las letras, pues la encontre
    // Sino no la encontre
}


// Tejido Tenido Acabado Confeccion
// Jersey Pique Franela
// Polos Camisas Cuellos
/*
basta crear 3 matrices
    Jersey
        (3*4)
    Pique
        (3*4)
    Franela
        (3*4)

    [Polos, Camisas, Cuellos]      
    [Tejido "Tenido" Acabado Confeccion]

            Tejido  Tenido  Acabado Confeccion
    0 Polos
    1 Camisas
    2 Cuellos
*/
















