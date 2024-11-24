/*Realizar una funcion que devuelva el valor de un angulo en el punto de cruce de dos lineas,
realizar la funcion de tal manera que por defecto el angulo lo de en radianes, pero que pueda cambiarse a grados*/

#include <iostream>
#include <cmath>

using namespace std;

struct ParCoordenadas {
    float X1, Y1, X2, Y2, X3, Y3, X4, Y4;
};

// Función que calcula el ángulo en el punto de cruce de dos líneas
float CalcularAngulo(ParCoordenadas P, bool enGrados = false) {
    // Calcular la pendiente de cada línea
    float PendienteM1 = (P.Y2 - P.Y1) / (P.X2 - P.X1);
    float PendienteM2 = (P.Y4 - P.Y3) / (P.X4 - P.X3);

    // Calcular el ángulo en radianes
    float angulo = atan(abs((PendienteM1 - PendienteM2) / (1 + PendienteM1 * PendienteM2)));

    // Convertir a grados si es necesario
    if (enGrados) {
        angulo = angulo * (180.0 / M_PI);
    }

    return angulo;
}

int main() {
    ParCoordenadas P;

    cout << "Ingrese los valores de los pares de coordenadas" << endl;
    cout << "Ingrese X1: "; cin >> P.X1;
    cout << "Ingrese Y1: "; cin >> P.Y1;
    cout << "Ingrese X2: "; cin >> P.X2;
    cout << "Ingrese Y2: "; cin >> P.Y2;
    cout << "Ingrese X3: "; cin >> P.X3;
    cout << "Ingrese Y3: "; cin >> P.Y3;
    cout << "Ingrese X4: "; cin >> P.X4;
    cout << "Ingrese Y4: "; cin >> P.Y4;

    // Calcular el ángulo en radianes
    float anguloRadianes = CalcularAngulo(P);
    cout << "El ángulo en el punto de cruce en radianes es: " << anguloRadianes << endl;

    // Calcular el ángulo en grados
    float anguloGrados = CalcularAngulo(P, true);
    cout << "El ángulo en el punto de cruce en grados es: " << anguloGrados << endl;

    return 0;
}