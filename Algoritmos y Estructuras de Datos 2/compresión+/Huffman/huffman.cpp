#include "C:\Users\gonza\Documents\AED 2\Huffman\huffman.h"

int main(){
  string nombreArchivoEntrada = "entrada.txt";
  string nombreArchivoSalida = "salida.bin";

  Huffman huffman;
  string text = huffman.leerDesdeArchivo(nombreArchivoEntrada);

  huffman.CrearArbol(text);
  cout << "\n";
  return 0;
}