#include <iostream>
#include <string>
using namespace std;

class calculadora {
private:
	string cadena;
	string::size_type a=0;
	int contm = 0, ac = 0;
	float NM[10], res = 0;
	char* puntero;
public:
	void visualizarR();
	void cargar();
	void multiplicacion();
};


void calculadora::cargar() {
	cin >> cadena;
	a = cadena.length();
	puntero = &cadena[0];
}


void calculadora::multiplicacion() {
	while (ac < a) {
		if (*puntero == '*') {
			puntero = puntero + 2;
			NM[0] = NM[0] * (*puntero-48);
			ac++;
		}
		puntero++;
		if (*puntero == '*') {
			puntero = puntero - 1;
			NM[0] = (*puntero) - 48;
			puntero++;
		}
	}
	cout << NM[0];
}


void calculadora::visualizarR() {

}


int main() {
	calculadora R;
	R.cargar();
	R.multiplicacion();
}



/*#include <iostream>
#include <string>
using namespace std;

class calculadora {
private:
	string::size_type sz, rz, mz, pz, a;
	string cadena;
	int init = 0, contr = 0, conts = 0, contm = 0, menos = 0, mas = 0, mult=0, priNum=0;
	float NR[10], NS[10], NM[10], mem = 0, res=0;
	char *puntero;
public:
	void visualizarR(float res);
	void visualizarM();
	void cargar();
	void primero();
	void restas();
	void sumas();
	void multiplicacion();
	float calcular();
	void cargarMemoria();
	void borrarMemoria();
};
void calculadora::visualizarR(float res) {
	cout << "	TOTAL: " << res << endl;
}
void calculadora::visualizarM() {
	cout << "El valor en memoria es: " << mem << endl;
}
void calculadora::cargar() {
	cin >> cadena;
	a = sizeof(cadena);
	puntero = &cadena[0];
}
/*float calculadora::calcular() {
	
	while (priNum < a) {
		priNum = cadena.find('+', init);
		if (priNum == (a - 1))return cadena[a - 1];
		if (cadena[priNum] == '+') {
			N = std::stof(cadena.substr(init, mas - init), &sz);
			init = priNum + 1;
			return (N + calcular());
		}
		else if (cadena[priNum] == '-') {
			return (std::stof(cadena.substr(init, menos - init), &rz) - calcular());
		}
		else if (cadena[priNum] == '*') {
			return (std::stof(cadena.substr(init, mult - init), &mz) * calcular());
		}else return 0;
	}
}
int calculadora::calcular() {
	init = 0;
	while (priNum < a) {
		priNum = cadena.find('-' || '+' || '*', init);
		if (cadena[priNum] == '+') {
			
		}
		else if (cadena[priNum] == '-') {

		}
		else if (cadena[priNum] == '*') {

		}
		else return 0;
	}
}
void calculadora::restas() {
	init = 0;
	while (menos < a) {
		menos = cadena.find('-', init);
		NR[contr] = std::stof(cadena.substr(init, menos - init), &rz);
		if (contr != 0)res = res - NR[contr];
		contr++;
		init = menos + 1;
	}
}
void calculadora::sumas() {
	init = 0;
	while (mas < a) {
		mas = cadena.find('+', init);
		NS[conts] = std::stof(cadena.substr(init, mas - init), &sz);
		if (conts != 0)res += NS[conts];
		conts++;
		init = mas + 1;
	}
}

void calculadora::multiplicacion() {
	init = 0;
	while (mult < a) {
		mult = cadena.find('*', init);
		NM[contm] = std::stof(cadena.substr(init, mult - init), &mz);
		if (contm != 0) {
			NM[contm];
		}
		contm++;
		init = mult + 1;
	}
}

int factorial(int x)
{
	if (x == 0) return 1;
	else return x * factorial(x - 1);
}

int main()
{
	calculadora R;
	R.cargar();
	
	R.primero();
	R.multiplicacion();
	R.restas();
	R.sumas();
	
	cout << R.calcular();
}*/