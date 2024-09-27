#include <iostream>
using namespace std;

// Función para implementar el algoritmo KMP
void KMP(string texto, string patron)
{
    int m = texto.length();
    int n = patron.length();

    // si el patrón es una string vacía
    if (n == 0)
    {
        cout << "The patron occurs with shift 0";
        return;
    }

    // si la longitud del textoo es menor que la del patrón
    if (m < n)
    {
        cout << "Pattern not found";
        return;
    }

    // next[i] almacena el índice de la siguiente mejor coincidencia parcial
    int next[n + 1];

    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int j = next[i];

        while (j > 0 && patron[j] != patron[i]) {
            j = next[j];
        }

        if (j > 0 || patron[j] == patron[i]) {
            next[i + 1] = j + 1;
        }
    }

    for (int i = 0, j = 0; i < m; i++)
    {
        if (texto[i] == patron[j])
        {
            if (++j == n) {
                cout << "The patron occurs with shift " << i - j + 1 << endl;
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // ya que `i` se incrementará en la siguiente iteración
        }
    }
}

void find(string texto, string patron)
{
    int n = texto.length();
    int m = patron.length();

    // si el textoo es una string vacía
    if (m == 0)
    {
        cout << "The patron occurs with shift 0";
        return;
    }

    // si la longitud del textoo es menor que la del patrón
    if (n < m)
    {
        cout << "Pattern not found";
        return;
    }

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (texto[i + j] != patron[j]) {
                break;
            }

            if (j == m - 1) {
                cout << "The patron occurs with shift " << i << endl;
            }
        }
    }
}




// Programa para implementar el algoritmo KMP en C++
int main()
{
    string texto = "AAAAZERAAAAMDMDKSAAAADODODODAAAALLLOMOAOOOOAPPOAAAOP";
    string patron = "CAB";

    find(texto, patron);

    KMP(texto, patron);

    return 0;
}
