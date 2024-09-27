
class nodo
{
    private:
        prueba dato;
        nodo *puntero;
    public:
        nodo() { puntero = NULL; }
        void setdato(prueba d){dato=d;}
        prueba getdato(){return dato;}
        void setpuntero(nodo *p){puntero=p;}
        nodo *getpuntero(){return puntero;}
};