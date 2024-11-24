/*Realizar dos funciones, una que reallice un proceso cualquiera, y otra que devuelva la cantidad de veces 
que se llamo a la primera funcion*/

#include <iostream>
#include <string>

using namespace std;

int contador = 0; // Variable global para contar las llamadas

// Función que realiza un proceso cualquiera (imprimir un mensaje)
void imprimirGatos(const string& gato) {
    contador++;
    cout << gato << endl;
}

// Función que devuelve la cantidad de veces que se llamó a la primera función
int obtenerContador() {
    return contador;
}

int main() {
    string gato;

    cout << "Ingrese nombres de gatos. Presione la tecla de espacio y luego Enter para terminar." << endl;

    while (true) {
        cout << "Ingrese un nombre de gato: ";
        getline(cin, gato);

        if (gato == " ") {
            break; // Terminar el bucle si el usuario ingresa un espacio
        }

        imprimirGatos(gato);
    }

    // Mostrar cuántas veces se llamó a la función de impresión
    cout << "La función 'imprimirGatos' se llamó " << obtenerContador() << " veces." << endl;

    return 0;
}