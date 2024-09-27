#include <iostream>
#include "FB.h";
using namespace std;


int main(){
    string texto="AAAAZERAAAAMDMDKSAAAADODODODAAAALLLOMOAOOOOAPPOAAAOP", patron="OA";
    FB A(texto, patron);
    A.find();
}