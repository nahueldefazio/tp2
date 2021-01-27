//
// Created by SuckMyPocket on 17/11/2020.
//

#include <iostream>
#include "tierra.h"
using namespace std;

Tierra::Tierra(std::string nombre, int escudo, int vida, int energia) : Personaje( nombre, escudo, vida, energia) {

}
void Tierra::mostrar() {
    cout << "\n";
    cout << "Elemento: Tierra" << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Energia: " << energia << endl;
    cout << "\n";
}

void Tierra::alimentar() {
    int hierbas = 8;
    cout << "Mi energia inicial es: " << energia << endl;
    cout << "Estoy comiendo HIERBAS (+8 energia)" << endl;
    energia = energia + hierbas;
    if (energia >= 20){
        energia = 20;
    }
    cout <<"Energia actual: " <<  energia << endl;
}