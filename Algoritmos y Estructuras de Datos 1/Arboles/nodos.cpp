class nodo
{
    private:
        int dato;
        nodo *puntero;
    public:
        nodo() { puntero = NULL; }
        void setdato(int d){dato=d;}
        int getdato(){return dato;}
        void setpuntero(nodo *p){puntero=p;}
        nodo *getpuntero(){return puntero;}
};