class registroPrecipitaciones
{
struct region{
	int nro;
	int totalR = 0;
	int promR = 0;
	int prec[35];
	int *p = prec;
	int c = 0;
};
struct Nodo{
	region *dato;
	Nodo *puntero;
};
private:
	region R[4];
	region *orden[4];
	void gDat(int Reg, int &a){
		*R[Reg].p = a;
		R[Reg].p++;
		R[Reg].c++;
	};
 
public:
	void leerDatos();
	void sumPromPrec();
	void guardarDatosOrd();
	void guardarinvert();
};