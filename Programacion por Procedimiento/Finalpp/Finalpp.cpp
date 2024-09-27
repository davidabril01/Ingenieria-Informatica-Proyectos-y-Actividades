//Ej_1: las opciones correctas son la a y la c. Ya que en la "a" estas diciendo que el puntero "b" apunte a "a".Y en la "c" que el puntero "c" apunte a la misma direccion de memoria que apunta "b"(esto es posible ya que ambas fueron declaradas como punteros)
//Ej_2: Luego de las declaraciones 1°: a=100, p y q vacias. 2° a=100, p=direccion de memoria con un entero vacio y q=vacio. 3° a=100, p apunta a entero igual a 10 y q vacio. 4° a=100, p y q apunta a entero igual a 10. 5° a=100, p y q apunta a entero igual a 85. 6° y ulitma a=100, p apunta a "a" igual a 100 y q apunta a entero igual a 85. 
//Ej_3: El encapsulamiento conciste en encapsular los atributos de un objeto. Existen 3 formas que son Public(se puede modificar el atributo directamente) private(solo se puede modificar el atributo mediante un metodo de la clase) protected(se puede modificar mediante una clase heredada y un metodo de la clase)
#include "Finalpp.h"
int main(){
principal a;
a.escribir_archivo();
cout<<a.media_ingresos();
a.Pers_region();
}