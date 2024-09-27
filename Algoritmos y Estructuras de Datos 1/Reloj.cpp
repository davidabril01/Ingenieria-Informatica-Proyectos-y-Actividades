#include <iostream>
using namespace std;

class reloj{
	private:
		int seg, min, hora;
		int segA, minA, horaA;
	public:
		void cargarHora();
		void delay();
		void mostrarHora();
		void cargarAlarma();
		void mostrarAlarma();
};

void reloj::cargarHora(){
	cout<<"Ingrese la Hora actual en este orden (Hora - min - seg): ";
	cin>>hora>>min>>seg;
}

void reloj::delay(){
	for(int i=0;i<500000000;i++){
	}
}

void reloj::mostrarHora(){
	cout<<"Hora ("<<hora<<" : "<<min<<" : "<<seg<<")";
	delay();
	system("cls");
	seg++;
	if(seg>60){
		seg=0;
		min++;
	}
	if(min>60){
		min=0;
		hora++;
	}
}

void reloj::cargarAlarma(){
	cout<<"Ingrese alarma en este orden (Hora - min - seg): ";
	cin>>horaA>>minA>>segA;
}

void reloj::mostrarAlarma(){
	if((hora==horaA)&&(min==minA)&&(seg==segA)){
		system("cls");
		for(int i; i<10;i++){
			cout<<"ALARMA!!";
			delay();
			system("cls");
			delay();
		}
		if(seg<40){
			seg+=20;
		}
		if(seg>40){
			min++;
			seg=20-(60-seg);
		}
	}
}

int main(){
	int seg=0, min=0, hora=0;
	reloj R;
	R.cargarAlarma();
	R.cargarHora();
	while(1){
		R.mostrarHora();
		R.mostrarAlarma();
	}
}
