//
// Created by SuckMyPocket on 17/11/2020.
//


#include "personaje.h"

Personaje::Personaje(std::string nombre, int escudo, int vida, int energia){
    this->nombre = nombre;
    this->escudo = escudo;
    this->vida = vida;
    this->energia = energia;

}

std::string Personaje::get_nombre() {
    return this->nombre;
}



