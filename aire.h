//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_AIRE_H
#define UNTITLED_AIRE_H
#include "personaje.h"

using namespace std;

class Aire : public Personaje {
public:
    Aire(std::string nombre, int escudo, int vida, int energia);
    void mostrar();
    void alimentar();
};


#endif //UNTITLED_AIRE_H
