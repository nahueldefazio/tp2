//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_AGUA_H
#define UNTITLED_AGUA_H


#include "personaje.h"

class Agua : public Personaje {
private:
    int cont_comida ;
public:
   Agua(std::string nombre, int escudo, int vida, int energia);
   void mostrar();
   void alimentar();
};


#endif //UNTITLED_AGUA_H
