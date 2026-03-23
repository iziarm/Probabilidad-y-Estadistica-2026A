#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

int main() {
    // El DataSet con números reales como pide la hoja
    double datos[] = {15.5, 20.0, 15.5, 45.2, 20.0, 15.5, 10.8, 45.2, 20.0, 15.5};
    int n = sizeof(datos) / sizeof(datos[0]);

    sort(datos, datos + n);

    cout << "TABLA DE FRECUENCIAS DE LA VARIABLE" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "Valor\t\tfa\tfr\t\t\t%" << endl;
    cout << "-------------------------------------------------------" << endl;

    int contador = 0;
    double suma_fr = 0;
    double suma_porcentaje = 0;

    for (int i = 0; i < n; i++) {
        contador++;

        
        if (i == n - 1 || datos[i] != datos[i + 1]) {
            double fr = (double)contador / n;
            double porc = fr * 100;

            cout << datos[i] << "\t\t";
            cout << contador << "\t";
            cout << contador << "/" << n << " = " << fr << "\t\t";
            cout << porc << "%" << endl;

            suma_fr += fr;
            suma_porcentaje += porc;

            // resetear el contador para la siguiente clase 
            contador = 0;
        }
    }

    cout << "-------------------------------------------------------" << endl;
    cout << "TOTAL\t\t" << n << "\t" << suma_fr << "\t\t\t" << suma_porcentaje << "%" << endl;

    return 0;
}