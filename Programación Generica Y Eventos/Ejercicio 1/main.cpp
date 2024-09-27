#include <iostream>
#include "Inventario.h"

using namespace std;
void CallbackNuevoProducto(Producto NuevoProd)
{
    cout << "Se agregaron " << NuevoProd.getCant() << " " << NuevoProd.getNombre() << "s con el precio de: " << NuevoProd.getPrecio() << "$"<< endl;
}
int main()
{

    Inventario inventario;
    int opcion;

    do
    {
        cout << "===========================" << endl;
        cout << "Gestión de Inventario" << endl;
        cout << "===========================" << endl;
        cout << "1. Crear Producto" << endl;
        cout << "2. Leer Producto" << endl;
        cout << "3. Actualizar Producto" << endl;
        cout << "4. Borrar Producto" << endl;
        cout << "5. Salir" << endl;
        cout << "===========================" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Elgio la opcion crear un producto" << endl;
            inventario.Crear(CallbackNuevoProducto);
            break;
        case 2:
            cout << "Elgio la opcion leer un producto" << endl;
            inventario.Leer();
            break;
        case 3:
            cout << "Eligio la opcion de actualizar un producto" << endl;
            inventario.Actualizar();
            break;
        case 4:
            cout << "Eligio la opcion de borrar un producto" << endl;
            inventario.Borrar();
            break;
        case 5:
            cout << "Saliendo de la gestion de inventario." << endl;
            cout << "Gracias por utilizarlo" << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 5);

    return 0;
}
