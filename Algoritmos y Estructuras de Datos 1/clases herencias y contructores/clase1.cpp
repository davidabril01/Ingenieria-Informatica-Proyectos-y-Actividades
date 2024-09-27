#include <iostream>
#include <cmath>
using namespace std;

class triangulo
{
private:
    float l1, l2, l3;
public:
    triangulo(){};
    triangulo(float L1, float L2, float L3){l1=L1; l2=L2; l3=L3;}
    float S(); //semiperimetro
    float altura();
    float superficie();
    ~triangulo(){};
};

float triangulo::S(){ //semiperimetro
    float aux;
    aux=(l1+l2+l3)/2;
    return aux;
}

float triangulo::altura(){
    float aux;
    aux=(2/l1)*(sqrt(S()*(S()-l1)*(S()-l2)*(S()-l3)));
    return aux;
}

float triangulo::superficie(){
    float aux;
    aux=(l1*altura())/2;
    return aux;
}

int main(){
    triangulo T1(5, 5, 3);
    cout<<"El triangulo tiene una superficie total de "<<T1.superficie();
}