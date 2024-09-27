#include "busqueda.h"


int main() {
    string text = "AAAAZERAAAAMDMDKSAAAADODODODAAAALLLOMOAOOOOAPPOAAAOP";
    string pattern = "AAAA";
    StringSearch searcher(text, pattern);
    cout << "Busqueda por fuerza bruta:\n";
    searcher.Busqueda_fuerza_bruta();
    cout << "Busqueda por KMP:\n";
    searcher.Busqueda_por_KMP();
    return 0;
}