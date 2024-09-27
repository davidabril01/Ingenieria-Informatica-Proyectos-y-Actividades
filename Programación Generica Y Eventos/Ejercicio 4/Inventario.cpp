#include "Inventario.h"

void Inventario::CallbackNuevoProducto(Producto NuevoProd)
{
    cout << "Se agregaron " << NuevoProd.getCant() << " " << NuevoProd.getNombre() << "s con el precio de: " << NuevoProd.getPrecio() << "$" << endl;
}

// Constructor
Inventario::Inventario()
    : Productos() // Inicializa la lista de productos vacía
{
}

// Crear - Adds a new product to the inventory
void Inventario::Crear()
{
    string nombre;
    int precio, cantidad;
    Producto nuevoProducto;

    cout << "Ingrese el nombre del producto: ";
    cin >> nombre;
    nuevoProducto.setNombre(nombre);
    cout << endl;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    nuevoProducto.setPrecio(precio);
    cout << endl;
    cout << "Ingrese la cantidad del producto: ";
    cin >> cantidad;
    nuevoProducto.setCant(cantidad);
    cout << endl;
    Productos.push_back(nuevoProducto);
    CallbackNuevoProducto(nuevoProducto);
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}

void Inventario::RunEventLoop()
{
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
            system("cls");
            cout << "Elgio la opcion crear un producto" << endl;
            Crear();
            break;
        case 2:
            system("cls");
            cout << "Elgio la opcion leer un producto" << endl;
            Leer();
            break;
        case 3:
            system("cls");
            cout << "Eligio la opcion de actualizar un producto" << endl;
            Actualizar();
            break;
        case 4:
            system("cls");
            cout << "Eligio la opcion de borrar un producto" << endl;
            Borrar();
            break;
        case 5:
            system("cls");
            cout << "Saliendo de la gestion de inventario." << endl;
            cout << "Gracias por utilizarlo" << endl;
            break;
        default:
            system("cls");
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 5);

}

// Leer - Reads and prints product details by name
void Inventario::Leer()
{
    string nombre;
    cout << "Ingrese el nombre del producto a leer: ";
    cin >> nombre;

    for (const auto& producto : Productos)
    {
        if (producto.getNombre() == nombre)
        {
            cout << "Nombre: " << producto.getNombre() << ", "
                << "Precio: " << producto.getPrecio() << ", "
                << "Cantidad: " << producto.getCant() << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}

// Actualizar - Updates the details of a specific product
void Inventario::Actualizar()
{
    string nombre;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> nombre;

    for (auto& producto : Productos)
    {
        if (producto.getNombre() == nombre)
        {
            float nuevoPrecio;
            int nuevaCantidad;
            cout << "Ingrese el nuevo precio: ";
            cin >> nuevoPrecio;
            cout << "Ingrese la nueva cantidad: ";
            cin >> nuevaCantidad;

            producto.setPrecio(nuevoPrecio);
            producto.setCant(nuevaCantidad);
            cout << "Producto actualizado." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}

// Borrar - Deletes a product from the inventory by name
void Inventario::Borrar()
{
    string nombre;
    cout << "Ingrese el nombre del producto a borrar: ";
    cin >> nombre;
    for (auto it = Productos.begin(); it != Productos.end(); ++it)
    {
        if (it->getNombre() == nombre)
        {
            Productos.erase(it);
            cout << "Producto se borro." << endl;
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}



// Destructor
Inventario::~Inventario()
{
}
