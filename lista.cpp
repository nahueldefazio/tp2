//
// Created by SuckMyPocket on 17/11/2020.
//
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstring>
#include "lista.h"

using namespace std;

const string PATH = "personajes.csv";

std::string get_current_dir() {
    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX);
    string current_working_dir (buff);
    return current_working_dir;
}

Lista::Lista() {
    cantidad = 0;
    primero = 0;
    actual = 0;
    leer_datos();
}

bool Lista::vacia() {
    return (cantidad == 0);
}

void Lista::alta(Dato d) {

    Nodo* nuevo = new Nodo(d);
    if (cantidad == 0){
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else{
        Nodo* anterior = obtener_nodo (cantidad );
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }

    cantidad ++;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    for (int i=1; i < pos; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

Dato Lista::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);

    return aux ->obtener_dato();
}


void Lista::baja(int pos) {
    Nodo* borrar;

    if (pos == 1){
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else{
        Nodo* anterior = obtener_nodo(pos -1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    reiniciar();
    delete borrar;
    cantidad --;
}

Lista::~Lista() {
    while (!vacia())
        baja(1);
}

int Lista::obtener_cantidad() {
    return cantidad;
}

void Lista::reiniciar() {
    actual = primero;
}

bool Lista::hay_siguiente() {
    return  (actual !=0);
}

Dato Lista::siguiente() {
    if (hay_siguiente()){
        Nodo *aux = actual;
        actual = actual->obtener_siguiente();
        return aux->obtener_dato();
    }
    return nullptr;
}

void Lista::leer_datos() {

    ifstream archivo;
    archivo.open(PATH);

    if (!archivo) {
        cout << "No se pudo leer el archivo: " << PATH << endl;
        exit(1);
    } else {

        string elemento;
        string nombre;
        string escudo;
        string vida;

        while (archivo.good()) {

            getline(archivo, elemento, ',');
            getline(archivo, nombre, ',');
            getline(archivo, escudo, ',');
            getline(archivo, vida, '\n');

            cargar_datos(elemento, nombre, escudo, vida);
        }
        archivo.close();
    }
}

void Lista::cargar_datos(string elemento, string nombre, string escudo, string vida) {

        int escudo_ = stoi(escudo);
        int vida_ = stoi(vida);
        int energia;
        Personaje *personaje;

        if (elemento == "agua") {
            energia = rand() % 21;
            personaje = new Agua(nombre, escudo_, vida_, energia);
            alta(personaje);
        }
        else if (elemento == "fuego"){
            energia = rand() % 21;
            personaje = new Fuego(nombre, escudo_, vida_, energia);
            alta(personaje);
        }
        else if (elemento == "aire"){
            energia = rand() % 21;
            personaje = new Aire(nombre , escudo_, vida_, energia);
            alta(personaje);
        }
        else if (elemento == "tierra"){
            energia = rand() % 21;
            personaje = new Tierra(nombre, escudo_, vida_, energia);
            alta(personaje);
        }
}

int Lista::pos_nombre(string nombre) {

    int pos_personaje = 0;
    reiniciar();
    while (hay_siguiente()) {
        pos_personaje++;
        int res = siguiente()->get_nombre().compare(nombre);
        if (res == 0)
            return pos_personaje;

    }


    return 0;
}

