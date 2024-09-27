#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

struct datos{
	int nro;
	int centro;
	int medio;
	int errado;
	char provincia[10];
};

void leerPuntajes(){
	datos jugadores;
	int centro, medio, errado;
	string xd;
	FILE *arch;
	arch=fopen("datos.dat","rb");
	ifstream pts("puntos.txt");
	for(int a =0; a<3;a++){
	pts >> xd;
	}
	pts >> centro;
	pts >> xd;
	pts >> medio;
	pts >> xd;
	pts >>errado;

	if (arch==NULL) perror ("Error opening file");
	else{
		fread (&jugadores,sizeof (datos),1,arch); 
		while (!feof(arch)) {
			cout<<"El jugador nro "<<jugadores.nro<<" de la provincia de "<<jugadores.provincia<<" ha echo un total de "<<jugadores.centro*centro+jugadores.medio*medio+jugadores.errado*errado<<" puntos!!\n\n";
			fread (&jugadores,sizeof (datos),1,arch);
			if(jugadores.errado>=(jugadores.centro+jugadores.errado+jugadores.medio)/2){
				
			}
		}
	}
	fclose(arch);
}

int main(){
	leerPuntajes();
}
