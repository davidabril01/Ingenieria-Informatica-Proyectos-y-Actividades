#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <unordered_map>
using namespace std;

class Huffman {
private:
  struct Node{
    char simbolo;   
    int frecuencia;
    Node *izq, *der;
  };

  struct comp{//comparador para la cola de prioridad
    bool operator()(Node* i, Node* d){
      return i->frecuencia > d->frecuencia;
    }
  };

  Node* getNode(char simbolo, int frecuencia, Node* izq, Node* der){
    Node* nodo = new Node();

    nodo->simbolo = simbolo;
    nodo->frecuencia = frecuencia;
    nodo->izq = izq;
    nodo->der = der;

    return nodo;
  }

  void comprimir(Node* raiz, string str, unordered_map<char, string> &CodigoHuffman){//recorrido del arbol para obtener los codigos de huffman
    if(raiz == nullptr)
      return;
    if (!raiz->izq && !raiz->der){
      CodigoHuffman[raiz->simbolo] = str;//si es una hoja se agrega el codigo al mapa 
    }
    comprimir(raiz->izq, str + "0", CodigoHuffman);//se recorre el arbol de forma recursiva 
    comprimir(raiz->der, str + "1", CodigoHuffman);//se recorre el arbol de forma recursiva
  }

  void descomprimir(Node* raiz, int &index, string str){//recorrido del arbol para decodificar el texto
    if(raiz == nullptr){
      return;
    }
    if(!raiz->izq && !raiz->der){
      cout << raiz->simbolo;
      return;
    }
    index++;
    if(str[index] == '0'){
      descomprimir(raiz->izq, index, str);
    }
    else{
      descomprimir(raiz->der, index, str);
    }
  }

public:
  string leerDesdeArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
      cerr << "No se pudo abrir el archivo " << nombreArchivo << '\n';
      exit(EXIT_FAILURE);
    }
    string linea, contenido;
    while (getline(archivo, linea)) {
      contenido += linea;
    }
    archivo.close();
    return contenido;
  }

  void CrearArbol(string text) {
    unordered_map<char, int> frecuencia;
    for (char simbolo: text){
      frecuencia[simbolo]++;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair: frecuencia){
      pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1){
      Node *izq = pq.top(); pq.pop();
      Node *der = pq.top(); pq.pop();
      int suma = izq->frecuencia + der->frecuencia;
      pq.push(getNode('\0', suma, izq, der));
    }
    Node* raiz = pq.top();
    unordered_map<char, string> CodigoHuffman;
    comprimir(raiz, "", CodigoHuffman);
    cout << "Los codigos de Huffman son:\n" << '\n';
    for (auto pair: CodigoHuffman){
      cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nEl texto original es:\n" << text << '\n';
    string str = "";
    for (char simbolo: text){
      str += CodigoHuffman[simbolo];
    }
    ofstream archivo("salida.bin", ios::binary);
    archivo << str;
    archivo.close();
    cout << "\nEl texto codificado es:\n" << str << '\n';
    int index = -1;

    string codigoCodificado = leerDesdeArchivo("salida.bin");
    cout << "\nEl texto decodificado es:\n";
    while (index < (int)codigoCodificado.size() - 2){
      descomprimir(raiz, index, codigoCodificado);
    }
    cout << "\n\n\n";
  }

  void escribirEnArchivo(const string &nombreArchivo, const string &codigoCodificado) {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
      cerr << "No se pudo abrir el archivo " << nombreArchivo << '\n';
      exit(EXIT_FAILURE);
    }
    archivo << "El texto codificado es:\n" << codigoCodificado << '\n';
    archivo.close();
  }
};

