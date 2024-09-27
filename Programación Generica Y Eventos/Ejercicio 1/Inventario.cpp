#include "Inventario.h"

// Constructor
Inventario::Inventario()
    : Productos() // Inicializa la lista de productos vacía
{
}

// Crear - Adds a new product to the inventory
void Inventario::Crear(void (*callback)(Producto))
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
    callback(nuevoProducto);
}

// Leer - Reads and prints product details by name
void Inventario::Leer()
{
    string nombre;
    cout << "Ingrese el nombre del producto a leer: ";
    cin >> nombre;

    for (const auto &producto : Productos)
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
}

// Actualizar - Updates the details of a specific product
void Inventario::Actualizar()
{
    string nombre;
    cout << "Ingrese el nombre del producto a actualizar: ";
    cin >> nombre;

    for (auto &producto : Productos)
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
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
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
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}



// Destructor
Inventario::~Inventario()
{
}
