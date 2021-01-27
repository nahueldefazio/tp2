//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_FUEGO_H
#define UNTITLED_FUEGO_H
#include "personaje.h"

class Fuego : public Personaje {
public:
    Fuego(std::string nombre, int escudo, int vida, int energia);
    void mostrar ();
    void alimentar();
};


#endif //UNTITLED_FUEGO_H
