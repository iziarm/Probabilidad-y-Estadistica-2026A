#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    double y[] = {2, 4, 6, 8, 10, 12, 14, 16, 18}; // Valores de ejemplo
    int n = sizeof(x) / sizeof(x[0]);

    // Variables para las sumatorias
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += (x[i] * y[i]);
        sumX2 += (x[i] * x[i]);
    }

    // Cálculo de los coeficientes
    double b1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    
    // b0 = (sumY - b1*sumX) / n
    double b0 = (sumY - b1 * sumX) / n;

    // 1. Imprime la ecuación de regresión
    cout << fixed << setprecision(2);
    cout << "MODELO DE REGRESION LINEAL SIMPLE" << endl;
    cout << "---------------------------------" << endl;
    cout << "Ecuacion de regresion: y = " << b0 << " + " << b1 << "x" << endl;
    cout << "Donde (x = Advertising, y = Sales)" << endl;
    cout << "---------------------------------" << endl;

    
    double predicciones[] = {10, 12, 15, 20, 25}; 
    
    cout << "\nPREDICCIONES DE VENTAS (Sales):" << endl;
    cout << "Advertising\tPredicted Sales" << endl;
    
    for (int i = 0; i < 5; i++) {
        double x_nueva = predicciones[i];
        // Aplicar  y = b0 + b1*x
        double y_predicha = b0 + b1 * x_nueva;
        
        cout << x_nueva << "\t\t" << y_predicha << endl;
    }

    return 0;
}