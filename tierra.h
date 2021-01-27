//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_TIERRA_H
#define UNTITLED_TIERRA_H
#include <string>
using namespace std;

#include "personaje.h"

class Tierra : public Personaje {
public:
    Tierra(std::string nombre, int escudo, int vida, int energia);
    void mostrar();
    void alimentar();
};



#endif //UNTITLED_TIERRA_H
