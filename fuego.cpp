//
// Created by SuckMyPocket on 17/11/2020.
//
#include <iostream>
using namespace std;
#include "fuego.h"
#include <string>

Fuego::Fuego(std::string nombre, int escudo, int vida, int energia) : Personaje( nombre, escudo, vida, energia) {

}

void Fuego::mostrar() {
    cout << "\n";
    cout << "Elemento: Fuego" << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Energia: " << energia << endl;
    cout << "\n";
}
void Fuego::alimentar() {
    int madera = 15;
    cout << "Mi vida inicial es: " << vida << endl;
    cout << "Estoy comiendo MADERA (+15 vida)" << endl;
    vida = vida + madera;
    if (vida >= 100){
        vida = 100;
    }
    cout <<"Vida actual: " <<  vida << endl;
}