#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Busqueda_fuerza_bruta(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])//si no coincide el caracter
                break;
        if (j == m)
            cout << "Patron encontrado en la posicion: " << i << endl;
    }
}

vector<int> compute_lps_array(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void Busqueda_por_KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = compute_lps_array(pattern);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            cout << "Patron encontrado en la posicion: " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main() {
    string text = "AAAAZERAAAAMDMDKSAAAADODODODAAAALLLOMOAOOOOAPPOAAAOP";
    string pattern = "AAAA";
    cout << "Busqueda por fuerza bruta:\n";
    Busqueda_fuerza_bruta(text, pattern);
    cout << "Busqueda por KMP:\n";
    Busqueda_por_KMP(text, pattern);
    return 0;
}