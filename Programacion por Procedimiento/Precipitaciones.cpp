#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Precipitaciones.h"

void registroPrecipitaciones::leerDatos(){
	for (int i = 1; i < 5; i++){
		R[i - 1].nro = i;
	}
	ifstream dts("datos.txt");
	string xd;
	int a;
	for(int a =0; a<3;a++){
	dts >> xd;
	}
	dts >> a;
	while ((a==1)||(a==2)||(a==3)||(a==4)){
		switch(a){
			case 1:
				dts >> a;
				gDat(0, a);
			break;
			case 2:
				dts >> a;
				gDat(1, a);
			break;
			case 3:
				dts >> a;
				gDat(2, a);
			break;
			case 4:
				dts >> a;
				gDat(3, a);
			break;
		}
        dts >> a;
    }
}
void registroPrecipitaciones::sumPromPrec(){
	for (int e = 0; e < 4; e++){
		R[e].p = &R[e].prec[0];
		for (int i = 0; i < R[e].c; i++){
			R[e].totalR += (*R[e].p);
			R[e].p++;
		}
		R[e].promR = R[e].totalR / R[e].c;
	}
}
void registroPrecipitaciones::guardarDatosOrd(){
	ofstream file("Datos_Ordenados_MAY.txt");
	orden[0] = &R[0];
	orden[1] = &R[1];
	orden[2] = &R[2];
	orden[3] = &R[3];
	for (int i = 0; i < 4; i++){
		for (int j = i + 1; j < 4; j++){
			if (orden[i]->totalR < orden[j]->totalR){
				region *temporal;
				temporal = orden[j];
				orden[j] = orden[i];
				orden[i] = temporal;
			}
		}
	}
	file << "Region  "<< "Total(mm)  "<< "Prom(mm)" << endl;
	for (int i = 0; i < 4; i++){
		file << orden[i]->nro << "       " << orden[i]->totalR << "        " << orden[i]->promR << endl;
	}
	file.close();
}
void registroPrecipitaciones::guardarinvert(){
	ofstream file1("Datos_Ordenados_men.txt");
	Nodo *p = NULL;
	Nodo *q;
	for (int i = 0; i < 4; i++){
		q = new Nodo();
		q->dato = orden[i];
		q->puntero = p;
		p = q;
	}
	file1 << "Region  "<< "Total(mm)  "<< "Prom(mm)" << endl;
	for (int i = 0; i < 4; i++){
		if (p != NULL){
			file1 << p->dato->nro << "       " << p->dato->totalR << "        " << p->dato->promR << endl;
			p = p->puntero;
		}
	}
	file1.close();
}