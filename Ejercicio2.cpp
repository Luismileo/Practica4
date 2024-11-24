/*Sobrecargar la funcion anterior para que devuelva 1 si las lineas son perpendiculares, 0 si son paralelas y -1 si se cruzan*/

#include <iostream>
#include <cmath>

using namespace std;

struct ParCoordenadas {
    float X1, Y1, X2, Y2, X3, Y3, X4, Y4;
};

// Función original que acepta un arreglo de ParCoordenadas
int AnalisisDeLinea(int coordenadas, ParCoordenadas P[]) {
    float PendienteM[2];
    float InterceptoB[2];

    // Calcular la pendiente y el intercepto para cada línea
    PendienteM[0] = (P[0].Y2 - P[0].Y1) / (P[0].X2 - P[0].X1);
    InterceptoB[0] = P[0].Y1 - PendienteM[0] * P[0].X1;
    PendienteM[1] = (P[0].Y4 - P[0].Y3) / (P[0].X4 - P[0].X3);
    InterceptoB[1] = P[0].Y3 - PendienteM[1] * P[0].X3;

    // Verificar si las líneas son paralelas
    if (PendienteM[0] == PendienteM[1]) {
        return 0; // Las líneas son paralelas
    } else if (PendienteM[0] * PendienteM[1] == -1) {
        return 1; // Las líneas son perpendiculares
    } else {
        // Calcular el punto de intersección
        float x_interseccion = (InterceptoB[1] - InterceptoB[0]) / (PendienteM[0] - PendienteM[1]);
        float y_interseccion = PendienteM[0] * x_interseccion + InterceptoB[0];

        // Verificar si el punto de intersección está dentro de los segmentos de línea
        bool en_segmento1 = (min(P[0].X1, P[0].X2) <= x_interseccion && x_interseccion <= max(P[0].X1, P[0].X2)) &&
                            (min(P[0].Y1, P[0].Y2) <= y_interseccion && y_interseccion <= max(P[0].Y1, P[0].Y2));
        bool en_segmento2 = (min(P[0].X3, P[0].X4) <= x_interseccion && x_interseccion <= max(P[0].X3, P[0].X4)) &&
                            (min(P[0].Y3, P[0].Y4) <= y_interseccion && y_interseccion <= max(P[0].Y3, P[0].Y4));

        if (en_segmento1 && en_segmento2) {
            return -1; // Las líneas se cruzan
        } else {
            return -2; // Las líneas no se cruzan ni son paralelas
        }
    }
}

// Sobrecarga de la función que acepta dos pares de coordenadas directamente
int AnalisisDeLinea(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) {
    ParCoordenadas P[1] = {{X1, Y1, X2, Y2, X3, Y3, X4, Y4}};
    return AnalisisDeLinea(1, P);
}

int main() {
    // Usar la función sobrecargada con un arreglo de ParCoordenadas
    int coordenadas = 1;
    ParCoordenadas P[coordenadas];

    cout << "Ingrese los valores de los pares de coordenadas" << endl;
    cout << "Ingrese X1: "; cin >> P[0].X1;
    cout << "Ingrese Y1: "; cin >> P[0].Y1;
    cout << "Ingrese X2: "; cin >> P[0].X2;
    cout << "Ingrese Y2: "; cin >> P[0].Y2;
    cout << "Ingrese X3: "; cin >> P[0].X3;
    cout << "Ingrese Y3: "; cin >> P[0].Y3;
    cout << "Ingrese X4: "; cin >> P[0].X4;
    cout << "Ingrese Y4: "; cin >> P[0].Y4;

    int resultado = AnalisisDeLinea(coordenadas, P);
    cout << "Resultado del análisis (con estructura): " << resultado << endl;

    // Usar la función sobrecargada con coordenadas individuales
    float X1, Y1, X2, Y2, X3, Y3, X4, Y4;
    cout << "Ingrese los valores de los pares de coordenadas directamente" << endl;
    cout << "Ingrese X1: "; cin >> X1;
    cout << "Ingrese Y1: "; cin >> Y1;
    cout << "Ingrese X2: "; cin >> X2;
    cout << "Ingrese Y2: "; cin >> Y2;
    cout << "Ingrese X3: "; cin >> X3;
    cout << "Ingrese Y3: "; cin >> Y3;
    cout << "Ingrese X4: "; cin >> X4;
    cout << "Ingrese Y4: "; cin >> Y4;

    resultado = AnalisisDeLinea(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
    cout << "Resultado del análisis (con coordenadas individuales): " << resultado << endl;

    return 0;
}