#include <iostream>
#include "Kmp.h"
using namespace std;

int main(){
    string texto="AAAAZERAAAAMDMDKSAAAADODODODAAAALLLOMOAOOOOAPPOAAAOP", patron="OA";
    Kmp A(texto, patron);
    A.find();
}