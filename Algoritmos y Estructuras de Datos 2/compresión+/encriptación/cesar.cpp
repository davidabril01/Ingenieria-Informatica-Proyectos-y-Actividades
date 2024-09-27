#include <iostream>
#include <string>

using namespace std; // Usar 'std::'

class CesarCipher
{
private:
    int desplazamiento;

public:
    CesarCipher(int desplazamiento) : desplazamiento(desplazamiento) {}

    string cifrar(const string &texto)
    {
        string textoCifrado = texto;
        for (char &c : textoCifrado)
        {
            if (isalpha(c))
            {
                char base = (isupper(c)) ? 'A' : 'a';
                c = (c - base + desplazamiento) % 25 + base;
            }
        }
        return textoCifrado;
    }

    string descifrar(const string &textoCifrado)
    {
        CesarCipher descifrador(25 - desplazamiento); // Corrección: desplazamiento en la dirección opuesta
        return descifrador.cifrar(textoCifrado);
    }
};

int main()
{
    int desplazamiento;
    string textoEntrada;

    do
    {
        cout << "Ingrese el valor de desplazamiento para el cifrado César(menor a 25): ";
        cin >> desplazamiento;
        cin.ignore(); // Limpiar el carácter de nueva línea del búfer de entrada
    } while (desplazamiento > 25);

    CesarCipher cifrador(desplazamiento);

    cout << "Ingrese el texto a cifrar: ";
    getline(cin, textoEntrada);

    string textoCifrado = cifrador.cifrar(textoEntrada);
    string textoDescifrado = cifrador.descifrar(textoCifrado);

    cout << "Texto Cifrado: " << textoCifrado << endl;
    cout << "Texto Descifrado: " << textoDescifrado << endl;

    return 0;
}
