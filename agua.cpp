//
// Created by SuckMyPocket on 17/11/2020.
//


#include "agua.h"
#include <iostream>
using namespace std;
Agua::Agua(std::string nombre, int escudo, int vida, int energia) : Personaje( nombre, escudo, vida, energia) {
    cont_comida = 3 ;
}
void Agua::mostrar() {
    cout << "\n";
    cout << "Elemento: Agua" << endl;
    cout << "Vida: " << vida << endl;
    cout << "Escudo: " << escudo << endl;
    cout << "Energia: " << energia << endl;
    cout << "\n";
}

void Agua::alimentar() {
    if (cont_comida > 0 && cont_comida <=3) {
        int plancton = 10;
        cout << "Mi energia inicial es: " << energia << endl;
        cout << "Me estoy alimentando con plancton (+10 energia)" << endl;
        energia = plancton + energia;
        if (energia >= 20) {
            energia = 20;
        }
        cout << " Energia actual: " << energia << endl;
        cont_comida--;
    }
    else{
        cout << "Ya comio mucho plancton este personaje, no puede volver a ser alimentado" << endl;
    }
}

