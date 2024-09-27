#include <iostream>
using namespace std;

struct cuenta
{
	string nombre;
	int DNI;
	string email;
	float saldo;
	int sueldo = -1;
	bool puesto;
	int tServ;
	bool estado = false;
};

int menu()
{
	int op;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "  MENU PRINCIPAL\n\n"
		 << "  1. AGREGAR UN CLIENTE\n"
		 << "  2. DAR DE BAJA UN CLIENTE\n"
		 << "  3. AGREGAR CUENTA SUELDO\n"
		 << "  4. CONSULTAR SALDO\n"
		 << "  5. REALIZAR OPERACIONES\n"
		 << "  6. CONSULTAR SITUACION CREDITICIA\n"
		 << "  7. VER DATOS"
		 << "  8. SALIR\n\n"
		 << "  Ingresar opcion: ";
	cin >> op;
	cout << u8"\033[2J\033[1;1H";
	return op;
}

void agregarUsuario(cuenta usuarios[4], int &nro)
{

	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "  AGREGAR NUEVOS REGISTROS\n\n";
	cout << "  Ingrese nombre: ";
	cin >> usuarios[nro].nombre;
	cout << "\n  Ingrese DNI: ";
	cin >> usuarios[nro].DNI;
	cout << "\n  Ingrese email: ";
	cin >> usuarios[nro].email;
	cout << "\n  Ingrese saldo que desea ingresar: ";
	cin >> usuarios[nro].saldo;
	cout << "\n  Ingrese su puesto(1 - profesional o 0 - administrativo): ";
	cin >> usuarios[nro].puesto;
	cout << "\n  Ingrese tiempo de servicio(en anios): ";
	cin >> usuarios[nro].tServ;
	usuarios[nro].estado = true;
	cout << "\n************************************************************\n\n"
		 << "Su numero de cuenta es: " << nro + 1 << "\n\n";
	nro++;
}

void darBaja(cuenta usuarios[4])
{
	int elegir;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "Indique el numero de cliente que quiere dar de baja: ";
	cin >> elegir;
	if (usuarios[elegir - 1].estado)
	{
		usuarios[elegir - 1].estado = false;
		cout << usuarios[elegir - 1].DNI;
		cout << "\nCliente de baja";
	}
	else
		cout << "\n  El cliente ya estaba dado de baja o nunca existio";
}

void generarSueldo(cuenta usuarios[4])
{
	int nro;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "Indique el numero de cliente al que quiere asignarle un sueldo: ";
	cin >> nro;
	if (usuarios[nro - 1].estado)
	{
		cout << "  Ingrese el valor del sueldo mensual que se le asigna: ";
		cin >> usuarios[nro - 1].sueldo;
	}
	else
		cout << "\n  El cliente debe estar activo para asignarle un sueldo";
}

void consultarSaldo(cuenta usuarios[4])
{
	int nro;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "  CONSULTA DE SALDO\n\n";
	cout << "  Ingrese numero de cuenta: ";
	cin >> nro;
	if (usuarios[nro - 1].estado)
	{
		cout << "\n\n  Su saldo es de: " << usuarios[nro - 1].saldo;
	}
	else
		cout << "\n  El cliente debe estar activo para poder saber su saldo";
}

void movimientos(cuenta usuarios[4])
{
	int elegir, nro;
	float monto;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "Ingrese su numero de cuenta: ";
	cin >> nro;
	if (usuarios[nro - 1].estado)
	{
		cout << "  Eliga la opcion que desee realizar\n"
			 << "  1 - Ingresar plata\n"
			 << "  2 - Extraer plata\n";
		cin >> elegir;
		switch (elegir)
		{

		case 1:
			cout << "  Digite el monto a depostiar: ";
			cin >> monto;
			usuarios[nro - 1].saldo += monto;
			break;
		case 2:
			cout << "  Digite el monto a extraer: ";
			cin >> monto;
			if (monto <= usuarios[nro - 1].saldo)
			{
				usuarios[nro - 1].saldo -= monto;
			}
			else{
				cout << "\n  SALDO INSUFICIENTE\n";
			}
			break;
		default:
			break;
		}
	}
	else
		cout << "\n  El cliente debe estar activo para poder realizar operaciones";
}

void tarjeta_de_credito(cuenta usuarios[4])
{
	int num_usuario;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "¿Para que usuario desea consultar sobre una tarjeta de credito? Ingrese el numero de usuario" << endl;
	cin >> num_usuario;
	if (usuarios[num_usuario - 1].estado)
	{
		if (usuarios[num_usuario - 1].sueldo != -1)
		{
			if (usuarios[num_usuario - 1].puesto == 1)
			{
				if (usuarios[num_usuario - 1].sueldo <= 30000)
				{
					cout << "El usuario '" << usuarios[num_usuario - 1].nombre << "' puede poseer una tarjeta BRONCE." << endl;
				}
				if (usuarios[num_usuario - 1].sueldo > 30000 && usuarios[num_usuario - 1].sueldo <= 70000)
				{
					cout << "El usuario  '" << usuarios[num_usuario - 1].nombre << "' puede poseer una tarjeta PLATA." << endl;
				}
				if (usuarios[num_usuario - 1].sueldo > 70000)
				{
					cout << "El usuario  '" << usuarios[num_usuario - 1].nombre << "' puede poseer una tarjeta ORO." << endl;
				}
			}
			else
				cout << "El usuario '" << usuarios[num_usuario - 1].nombre << "' debe ser PROFESIONAL para poder emitir una tarjeta." << endl;
		}
		else
			cout << "El usuario '" << usuarios[num_usuario - 1].nombre << "' debe poseer un sueldo." << endl;
	}
	else
		cout << "\n  El cliente debe estar activo para poder consultar";
}

bool volverAlMenu()
{
	bool a = 1;
	string volver;
	cout << "  Quiere volver al menu? (Si/No): ";
	cin >> volver;
	if (volver == "No")
	{
		a = false;
	}
	else
	{
		cout << u8"\033[2J\033[1;1H";
	}
	return a;
}

void visualizarDatos(cuenta usuarios[4])
{
	int nro;
	cout << "------------------------------------------------------------\n"
		 << "|                 BANCO CORDOBA, ARGENTINA                 |\n"
		 << "------------------------------------------------------------\n\n"
		 << "Ingrese su numero de cuenta: ";
	cin >> nro;
	if (usuarios[nro - 1].estado)
	{
		cout << "\n\n  Nombre: " << usuarios[nro - 1].nombre
			 << "\n\n  DNI: " << usuarios[nro - 1].DNI
			 << "\n\n  Email: " << usuarios[nro - 1].email
			 << "\n\n  Saldo: " << usuarios[nro - 1].saldo
			 << "\n\n  Puesto: " << usuarios[nro - 1].puesto
			 << "\n\n  Tiempo de servicio: " << usuarios[nro - 1].tServ << " anios"
			 << "\n\n  Estado de la cuenta: Activa\n\n";
	}
	else
		cout << "\n  El cliente debe estar activo para poder consultar";
}

int main()
{
	cuenta usuarios[4];
	int nroCuenta = 0;
	bool a = 1;
	while (a)
	{
		switch (menu())
		{
		case 1:
			agregarUsuario(usuarios, nroCuenta);
			a = volverAlMenu();
			break;
		case 2:
			darBaja(usuarios);
			a = volverAlMenu();
			break;
		case 3:
			generarSueldo(usuarios);
			a = volverAlMenu();
			break;
		case 4:
			consultarSaldo(usuarios);
			a = volverAlMenu();
			break;
		case 5:
			movimientos(usuarios);
			a = volverAlMenu();
			break;
		case 6:
			tarjeta_de_credito(usuarios);
			a = volverAlMenu();
			break;
		case 7:
			visualizarDatos(usuarios);
			a = volverAlMenu();
			break;
		case 8:
			a = 0;
			break;
		}
	}
}