#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // DataSet Hardcoded 
    double datos[] = {
        25, 28, 30, 33, 35, 38, 40, 42, 43, 45, 
        45, 47, 48, 50, 51, 52, 53, 55, 56, 58, 
        60, 60, 61, 63, 65, 67, 69, 70, 72, 75, 78
    };
    int n = sizeof(datos) / sizeof(datos[0]);
    sort(datos, datos + n);

    // Cálculos de intervalos 
    double v_min = datos[0];
    double v_max = datos[n-1];
    int k = ceil(1 + 3.322 * log10(n)); 
    double ancho = ceil((v_max - v_min) / k);

    int f[20]; 
    int Fa_arr[20];
    double Xc[20];
    double LI[20]; // Limites inferiores reales para mediana/moda

    cout << fixed << setprecision(2);
    cout << "Clase\tLimite\t\tf\tXc\tFa\tfr\tfra\tPorcentaje" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    int Fa = 0;
    double suma_fXc = 0;
    double limite_inf = v_min;

    for (int i = 0; i < k; i++) {
        double limite_sup = limite_inf + ancho - 1;
        LI[i] = limite_inf;
        Xc[i] = (limite_inf + limite_sup) / 2.0;
        
        int cont = 0;
        for (int j = 0; j < n; j++) {
            if (datos[j] >= limite_inf && datos[j] <= limite_sup) cont++;
        }

        f[i] = cont;
        Fa += cont;
        Fa_arr[i] = Fa;
        suma_fXc += (f[i] * Xc[i]);

        double fr = (double)f[i] / n;
        cout << i+1 << "\t" << limite_inf << "-" << limite_sup << "\t\t" << f[i] << "\t" 
             << Xc[i] << "\t" << Fa << "\t" << fr << "\t" << (double)Fa/n << "\t" << fr*100 << "%" << endl;

        limite_inf = limite_sup + 1;
    }

    
    // 1. Media
    double media = suma_fXc / n;

    // Buscar clase mediana (donde Fa >= n/2)
    int idx_mediana = 0;
    for(int i=0; i<k; i++) {
        if(Fa_arr[i] >= (double)n/2) {
            idx_mediana = i;
            break;
        }
    }
    double Fa_anterior = (idx_mediana == 0) ? 0 : Fa_arr[idx_mediana-1];
    double mediana = LI[idx_mediana] + ((((double)n/2) - Fa_anterior) / f[idx_mediana]) * ancho;

    // Buscar clase modal 
    int idx_moda = 0;
    for(int i=1; i<k; i++) {
        if(f[i] > f[idx_moda]) idx_moda = i;
    }
    double f_modal = f[idx_moda];
    double f_ant = (idx_moda == 0) ? 0 : f[idx_moda-1];
    double f_sig = (idx_moda == k-1) ? 0 : f[idx_moda+1];
    double d1 = f_modal - f_ant;
    double d2 = f_modal - f_sig;
    double moda = LI[idx_moda] + (d1 / (d1 + d2)) * ancho;

    cout << "--------------------------------------------------------------------------" << endl;
    cout << "\nMEDIDAS DE TENDENCIA CENTRAL:" << endl;
    cout << "1. Media (Promedio): " << media << endl;
    cout << "2. Mediana: " << mediana << endl;
    cout << "3. Moda: " << moda << endl;

    return 0;
}