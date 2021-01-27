//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_LISTA_H
#define UNTITLED_LISTA_H
#include <string>
#include "nodo.h"
#include "lista.h"
#include "agua.h"
#include "aire.h"
#include "fuego.h"
#include "tierra.h"
using namespace std;

class Lista {
private:
    Nodo* primero;
    int cantidad; // largo de la lista
    Nodo *obtener_nodo(int pos);
    Nodo *actual;

public:

    //Constructor
    //Pos:Crea una lista
    Lista();

    //Pre: posicion > 0 posiscion >= cantidad +1
    //Pos: inserta el dato d en la posicion pos, la pos 1 es la 1era
    void alta(Dato d);

    //Pre: 0 < posicion <= cantidad
    //Pos: saca elelemento que esta en la posicion
    void baja (int pos);

    //Pre: 0 < posicion <= cantidad
    //Pos: devuelve el dato que esta en la posicion
    Dato consulta(int pos);

    bool vacia();

    //Destructor
    //Pos: libera espacio en memoria
    virtual ~Lista();

    //Pos: devuelve la longuitud de la lista
    int obtener_cantidad();

    //Pos: pasa el nodo actual al primero (reinicia el nodo actual)
    void reiniciar();

    bool hay_siguiente();

    //Pos: devuelve
    Dato siguiente();

    //Pos: vuelve la posicion de la lista en donde se encuentra ese "nombre"
    int pos_nombre(string nombre);

    //Pre: no hay nombres repetidos y el formato del archivo es el correcto
    //Pos: lee los datos del archivo.csv
    void leer_datos();

    //Pos: hace la carga de datos ,mientras se lee el archivo
    void cargar_datos(string elemento, string nombre, string escudo, string vida);

};


#endif //UNTITLED_LISTA_H
