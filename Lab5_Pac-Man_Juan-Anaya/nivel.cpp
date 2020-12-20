#include "nivel.h"

Nivel::Nivel(){}

void Nivel::leerMuros(string nombre)
{
    ifstream archivo;
    string datos;
    int aux[4]={0,0,0,0};

    archivo.open(nombre);
    if (archivo.is_open()){
        while (!archivo.eof()) {
            getline(archivo, datos);
            for(int i=0; i<4 ; ++i){
                aux[i] = stoi(datos.substr(0, datos.find(',')));
                datos = datos.substr(datos.find(',')+1, datos.length());
            }
            muros.append(new Obstaculo(aux[0],aux[1],aux[2],aux[3]));
        }
        archivo.close();
    }
    else{
        exit(1);
    }
}

void Nivel::leerComida(string nombre)
{
    ifstream archivo;
    string datos;
    int aux[4]={0,0,0,0};

    archivo.open(nombre);
    if (archivo.is_open()){
        while (!archivo.eof()) {
            getline(archivo, datos);
            for(int i=0; i<4 ; ++i){
                aux[i] = stoi(datos.substr(0, datos.find(',')));
                datos = datos.substr(datos.find(',')+1, datos.length());
            }
            comida.append(new Moneda(aux[0],aux[1],aux[2],aux[3]));
        }
        archivo.close();
    }
    else{
        exit(1);
    }
}

Obstaculo *Nivel::atMuros(int posicion)
{
    return muros.at(posicion);
}

int Nivel::sizeMuros()
{
    return muros.size();
}

Moneda *Nivel::atComida(int posicion)
{
    return comida.at(posicion);
}

int Nivel::sizeComida()
{
    return comida.size();
}

void Nivel::removeMoneda(int posision)
{
    comida.removeAt(posision);
}
