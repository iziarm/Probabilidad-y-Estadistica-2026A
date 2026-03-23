#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip> /

using namespace std;

int main() {
    
    double datos[] = {
        25, 28, 30, 33, 35, 38, 40, 42, 43, 45, 
        45, 47, 48, 50, 51, 52, 53, 55, 56, 58, 
        60, 60, 61, 63, 65, 67, 69, 70, 72, 75, 78
    };
    
    int n = sizeof(datos) / sizeof(datos[0]);

    //  Ordenar datos
    sort(datos, datos + n);

    //  Cálculos iniciales
    double v_min = datos[0];
    double v_max = datos[n-1];
    double rango = v_max - v_min;

    // Regla de Sturges
    int k = ceil(1 + 3.322 * log10(n)); 
    
    
    double ancho = ceil(rango / k);

    // Encabezado de la tabla
    cout << "Clase\tLimite\t\tf\tXc\tFa\tfr\tfra\tPorcentaje %" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;

    int Fa = 0;
    double fra = 0;
    double limite_inferior = v_min;

    for (int i = 1; i <= k; i++) {
        double limite_superior = limite_inferior + ancho - 1; 
        double punto_medio = (limite_inferior + limite_superior) / 2.0;
        
        // Contar frecuencia absoluta 
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (datos[j] >= limite_inferior && datos[j] <= limite_superior) {
                f++;
            }
        }

        Fa += f; // Acumulada
        double fr = (double)f / n;
        fra += fr; // Relativa acumulada
        double porc = fr * 100;

        // Imprimir fila
        cout << i << "\t" 
             << limite_inferior << "-" << limite_superior << "\t\t" 
             << f << "\t" 
             << punto_medio << "\t" 
             << Fa << "\t" 
             << fixed << setprecision(2) << fr << "\t" 
             << fra << "\t" 
             << (int)porc << "%" << endl;

        // Siguiente clase
        limite_inferior = limite_superior + 1;
    }

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "TOTAL\t\tn = " << n << "\t\t\t\t1.00\t\t100%" << endl;

    return 0;
}