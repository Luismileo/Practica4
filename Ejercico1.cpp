/* Realizar una funcion que dado 2 pares de coordenadas, correspondiente al inicio y fin de dos lineas.
Devuelva 1 si las lineas se cruzan, 0 si  son paralelas y -1 si no se cruzan ni son paralelas*/

#include <iostream>
#include <cmath>

using namespace std;

struct ParCoordenadas{

    float X1,Y1,X2,Y2;
};

int AnalisisDeLinea(int coordenadas, ParCoordenadas P[]) {
    float PendienteM[coordenadas];
    float InterceptoB[coordenadas];

    // Calcular la pendiente y el intercepto para cada línea
    for(int i = 0; i < coordenadas; i++) {
        PendienteM[i] = (P[i].Y2 - P[i].Y1) / (P[i].X2 - P[i].X1);
        InterceptoB[i] = P[i].Y1 - PendienteM[i] * P[i].X1;
    }

    // Verificar si las líneas son paralelas
    if (PendienteM[0] == PendienteM[1]) {
        return 0; // Las líneas son paralelas
    } else {
        // Calcular el punto de intersección
        float x_interseccion = (InterceptoB[1] - InterceptoB[0]) / (PendienteM[0] - PendienteM[1]);
        float y_interseccion = PendienteM[0] * x_interseccion + InterceptoB[0];

        // Verificar si el punto de intersección está dentro de los segmentos de línea
        bool en_segmento1 = (min(P[0].X1, P[0].X2) <= x_interseccion && x_interseccion <= max(P[0].X1, P[0].X2)) &&
                            (min(P[0].Y1, P[0].Y2) <= y_interseccion && y_interseccion <= max(P[0].Y1, P[0].Y2));
        bool en_segmento2 = (min(P[1].X1, P[1].X2) <= x_interseccion && x_interseccion <= max(P[1].X1, P[1].X2)) &&
                            (min(P[1].Y1, P[1].Y2) <= y_interseccion && y_interseccion <= max(P[1].Y1, P[1].Y2));

        if (en_segmento1 && en_segmento2) {
            return 1; // Las líneas se cruzan
        } else {
            return -1; // Las líneas no se cruzan ni son paralelas
        }
    }
}

int main() {
    int coordenadas = 2;
    ParCoordenadas P[coordenadas];

    // Ingresar los valores de los pares de coordenadas
    for(int i = 0; i < coordenadas; i++) {
        cout << "Ingrese los valores de los pares de coordenadas" << endl;
        cout << "Ingrese X1: "; cin >> P[i].X1;
        cout << "Ingrese Y1: "; cin >> P[i].Y1;
        cout << "Ingrese X2: "; cin >> P[i].X2;
        cout << "Ingrese Y2: "; cin >> P[i].Y2;
    }

    // Llamar a la función AnalisisDeLinea y mostrar el resultado
    int resultado = AnalisisDeLinea(coordenadas, P);
    cout << "Resultado del análisis: " << resultado << endl;

    return 0;
}