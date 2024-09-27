#include <iostream>
#include <string>
using namespace std;

class calculadora{
	private:
		float op1, op2, res=0, mem=0;
		string op11, op22;
		char operacion;
		std::string::size_type sz;
	public:
		void visualizarR();
		void visualizarM();
		void cargarOp();
		void calcular();
		void cargarMemoria();
		void borrarMemoria();
		int menu();
};

void calculadora::visualizarR(){
	cout<<"El resultado es: "<<res<<endl;
}

void calculadora::visualizarM(){
	cout<<"El valor en memoria es: "<<mem<<endl;
}

void calculadora::cargarOp(){
	cout<<"Ingrese el primer operando: ";
	cin>>op11;
	if(op11=="m")op1=mem;
	else op1= std::stof(op11, &sz);
	cout<<"Ingrese el segundo operando: ";
	cin>>op22;
	if(op22=="m")op2=mem;
	else op2= std::stof(op22, &sz);
	cout<<"Ingrese la operacion que desea realizar (+ - * /): ";
	cin>>operacion;
}

void calculadora::calcular(){
	switch (operacion){
		case '+':
			res=op1+op2;
			break;
		case '-':
			res=op1-op2;
			break;
		case '/':
			res=op1/op2;
			break;
		case '*':
			res=op1*op2;
			break;
	}
}

void calculadora::cargarMemoria(){
	mem=res;
}

void calculadora::borrarMemoria(){
	mem=0;
}

int calculadora::menu(){
	int i;
	cout<<"Ingrese: "<<endl<<"	1-Cargar datos y calcular resultado"<<endl<<"	2-Cargar resultado anterior en la memoria"<<endl<<"	3-Borrar memoria"<<endl<<"	4-Visualizar memoria"<<endl<<"	5-Visualizar resultado enterior"<<endl;
	cin>>i;
	return i;
}

int main(){
	calculadora C;
	while(1){
			switch (C.menu()){
			case 1:
				C.cargarOp();
				C.calcular();
				C.visualizarR();
			break;
			case 2:
				C.cargarMemoria();
			break;
			case 3:
				C.borrarMemoria();
			break;
			case 4:
				C.visualizarM();
			break;
			case 5:
				C.visualizarR();
			break;
		}
	}
}
