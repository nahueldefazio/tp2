//
// Created by SuckMyPocket on 24/11/2020.
//
#include <iostream>
#include "menu.h"


void Menu::interfaz(Lista &lista) {
    int opcion;
    do{
        cout << " ==================================================================" << endl;
        cout << "1. Agregar un nuevo personaje." << endl;
        cout << "2. Eliminar un personaje."<< endl;
        cout << "3. Mostrar todos los nombres de los personajes." << endl;
        cout << "4. Buscar por nombre los detalles de un personaje en particular." << endl;
        cout << "5. Alimentar un personaje."<< endl;
        cout << "6. Salir." << endl;
        cout << "Ingrese alguna de las opciones (1,2,3,4,5 o 6):" ;
        cin >> opcion ;
        cout << " ==================================================================" << endl;

        opciones(opcion, lista);
    }
    while (opcion != 6);
}

void Menu::opciones(int opcion, Lista &lista) {

    switch (opcion) {
        case 1:
            agregar_personaje(lista);
            break;
        case 2:
            eliminar_personaje(lista);
            break;
        case 3:
            mostrar_nombres_lista(lista);
            break;
        case 4:
            buscar_personaje_detalles(lista);
            break;
        case 5:
            alimentar_personaje(lista);
            break;
        case 6:
            cout << "FIN DEL PROGRAMA =)" << endl;
            break;
        default:
            cout << "********* OPCION INVALIDA ********* " << endl;
    }

}

void Menu::agregar_personaje(Lista &lista) {

    string elemento_usuario, nombre_usuario, elemento_minusculas, nombre_usuario_minusculas;

    int escudo_usuario_int = rand() % 3;
    int vida_usuario_int = 10 + rand() %  (101 - 10) ;

    string escudo_usuario = to_string(escudo_usuario_int);
    string vida_usuario = to_string(vida_usuario_int);

    cout << "Ingrese el tipo de elemento (aire, agua, fuego, tierra): " << endl;
    cin >> elemento_usuario;
    elemento_minusculas = minusculas(elemento_usuario);
    elemento_usuario = validar_elemento("elemento", elemento_minusculas);

    cout << "Ingrese un nombre:" << endl;
    cin >> nombre_usuario;
    nombre_usuario_minusculas = minusculas(nombre_usuario);
    nombre_usuario = nombre_usuario_minusculas;


    lista.cargar_datos(elemento_usuario, nombre_usuario, escudo_usuario, vida_usuario);
}

void Menu::eliminar_personaje (Lista &lista){
    int posicion = 0;
    string nombre,nombre_minusculas;
    cout << "Ingrese el nombre del personaje que quiere eliminar:" << endl;
    cin >> nombre;
    while (!posicion){
        nombre_minusculas = minusculas(nombre);
        posicion = lista.pos_nombre(nombre_minusculas);
        if (posicion == 0){
            cout << "Nombre INVALIDO, ingrese un nombre que se encuentre en la lista: " << endl;
            cin >> nombre;
        }
    }
    lista.baja(posicion);
}

void Menu::buscar_personaje_detalles(Lista &lista) {
    Personaje* personaje;
    string nombre,nombre_minusculas;
    int posicion = 0;
    cout << "Ingrese el nombre del personaje del cual quiere sus detalles:";
    cin >> nombre;
    while (!posicion){
        nombre_minusculas = minusculas(nombre);

        posicion = lista.pos_nombre(nombre_minusculas);

        if (posicion == 0){
            cout << "Nombre INVALIDO, ingrese un nombre que se encuentre en la lista: " << endl;
            cin >> nombre;
        }
    }
    personaje = lista.consulta(posicion);
    personaje->mostrar();
}

void Menu::mostrar_nombres_lista(Lista &lista) {

    cout << "El listado de los personajes es el siguiente:" << endl;

    for (int i = 1;i <= lista.obtener_cantidad(); i++){
        cout << "Nombre del personaje: " << lista.consulta(i)->get_nombre() << endl;
    }
}

void Menu::alimentar_personaje(Lista &lista) {
    int posicion = 0;
    string nombre,nombre_minusculas;
    Personaje* personaje;
    cout << "Ingrese el nombre del personaje a quien quiere alimentar:" << endl;
    cin >> nombre;

    while (!posicion){
        nombre_minusculas = minusculas(nombre);

        posicion = lista.pos_nombre(nombre_minusculas);

        if (posicion == 0){
            cout << "Nombre INVALIDO, ingrese un nombre que se encuentre en la lista: " << endl;
            cin >> nombre;
        }
    }
    personaje = lista.consulta(posicion);

    personaje->alimentar();

}

string Menu::validar_elemento(string tipo_dato, string valor) {
    string valor_minusculas;

    cout << valor << endl;

    if (tipo_dato == "elemento") {
        while (valor != "aire" && valor != "agua" && valor != "fuego" &&
               valor != "tierra") {
            cout << "Ingrese un elemento valido: " << endl;
            cin >> valor;
            valor_minusculas = minusculas(valor);
            valor = valor_minusculas;
        }
        return valor;
    }
    return " ";
}
string Menu::minusculas(string cadena) {

    for (unsigned i = 0; i < cadena.length(); i++)
        cadena[i] = tolower(cadena[i]);

    return cadena;
}


Menu::Menu() {}

