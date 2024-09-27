#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct datos{
	int nro;
	int centro;
	int medio;
	int errado;
	char provincia[10];
};
void carga( datos competidor){
	
    cout<<"Ingrese el nro del competidor: ";
    cin>>competidor.nro;
	cout<<"\n ingrese tiros al centro del competidor nro"<<competidor.nro<<" :";
	cin>> competidor.centro;
	cout<<"\n ingrese tiros al medio: "<<competidor.nro<<" :";
	cin>> competidor.medio;
	cout<<"\n ingrese tiros errados: "<<competidor.nro<<" :";
	cin>>competidor.errado;
	cout<<"\n ingrese provincia: "<<competidor.nro<<" :";
	cin>>competidor.provincia;
	FILE *arch;
	arch=fopen("datos.dat" , "a");
	fwrite(&competidor, sizeof(datos), 1,arch);
	fclose(arch);
}
int main(){
	datos competidor ;

	char condicion;
	FILE *arch;
	arch=fopen("datos.dat","wb");
	fclose(arch);
	for(int i=0; i<10; i++){
	carga(competidor);
	cout<<"Quiere ingresar otro competidor? s/n ";
	cin>> condicion;
	if(condicion=='n'){
		i=10;
	} 
	}
}
	

	

