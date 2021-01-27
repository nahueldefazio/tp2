#include <string>
#include <ctime>
#include "menu.h"

int main() {
    srand (time(0));
    Lista lista;
    Menu menu;
    menu.interfaz(lista);

    return 0;
}