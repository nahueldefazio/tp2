//
// Created by SuckMyPocket on 24/11/2020.
//

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H
#include "lista.h"

class Menu {
public:
    //Contructor
    //Pos: Crea un menu
    Menu();

    string validar_elemento(string tipo_dato, string valor);

    //Pos: muestra por pantalla el menu
    void interfaz(Lista &lista);

    //Pre: no se ingresan letras, ni numeros de mas de 1  cifra, ni numeros negativos
    //Pos: ejecuta alguna de las opciones
    void opciones(int opcion, Lista &lista);

    //Pre: no se pueden agregar personajes repetidos
    //Pos: agrega un personaje a la lista
    void agregar_personaje(Lista &lista);

    //Pre: no hay personajes repetidos
    //Pos: elimina un personaje de la lista
    void eliminar_personaje(Lista &lista);

    //Pos: muestra los nombres de los personajes en la lista
    void mostrar_nombres_lista(Lista &lista);

    //Pre: no hay personajes repetidos
    //Pos: muestra por pantalla los detalles de un personaje
    void buscar_personaje_detalles(Lista &lista);

    //Pos: alimenta un personaje, segun su elemento
    void alimentar_personaje(Lista &lista);

    //Pos: convierte un string a minusculas
    string minusculas (string cadena);


};
#endif //UNTITLED_MENU_H
