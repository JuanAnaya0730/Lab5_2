#ifndef NIVEL_H
#define NIVEL_H

#include <fstream>
#include <QList>
#include "obstaculo.h"
#include "moneda.h"

using namespace std;

class Nivel
{
private:
    QList<Obstaculo*> muros;
    QList<Moneda*> comida;

public:
    Nivel();

    void leerMuros(string nombre);
    Obstaculo* atMuros(int posicion);
    int sizeMuros(void);

    void leerComida(string nombre);
    Moneda* atComida(int posicion);
    int sizeComida(void);

    void removeMoneda(int posision);


};

#endif // NIVEL_H
