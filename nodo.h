//
// Created by SuckMyPocket on 19/11/2020.
//

#include <string>
#include "personaje.h"

#ifndef UNTITLED_NODO_H
#define UNTITLED_NODO_H

#endif //UNTITLED_NODO_H

typedef Personaje* Dato;

class Nodo {
private:
    Dato dato;
    Nodo* siguiente;

public:
    //Constructor
    //PRE: d sea un dato valido
    // POST : crea un nodo con dato = d y siguiente = NULL
    Nodo(Dato d);

    void cambiar_dato (Dato d);

    void cambiar_siguiente (Nodo* s);

    Dato obtener_dato ();

    Nodo* obtener_siguiente ();

    ~Nodo();

};
