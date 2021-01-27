//
// Created by SuckMyPocket on 17/11/2020.
//

#ifndef UNTITLED_PERSONAJE_H
#define UNTITLED_PERSONAJE_H
#include <string>
#include <cstdlib>

class Personaje {
protected:
    int escudo;
    int vida;
    int energia;
    std::string nombre;

public:
    //Constructos
    Personaje(std::string nombre, int escudo, int vida, int energia);
    //Destructor
    virtual ~Personaje(){};
    virtual void mostrar() = 0;
    virtual void alimentar() = 0;
    std::string get_nombre();
};



#endif //UNTITLED_PERSONAJE_H
