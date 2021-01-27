//
// Created by SuckMyPocket on 17/11/2020.
//

#include "aire.h"
#include <iostream>
using namespace std;

Aire::Aire(std::string nombre, int escudo, int vida, int energia) : Personaje( nombre, escudo, vida, energia) {

}

void Aire::mostrar() {
    cout << "\n";
    cout << "Elemento: Aire" << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Energia: " << energia << endl;
    cout << "\n";
}

void Aire::alimentar() {

    cout << "Los personajes de aire no se alimentan" << endl;
    cout << "Su energia actual es: " << energia << endl;
    cout << "Su vida actual es: " << vida << endl;

}