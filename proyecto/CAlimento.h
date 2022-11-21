
class Alimento
{
protected:
    int puntos;
    int cantidad;
public:
    Alimento();
    Alimento(int pun ,int can);
    virtual ~Alimento();

    int getPuntos(); //{return puntos;}
    virtual int getCantidad(); //{return cantidad;}
};