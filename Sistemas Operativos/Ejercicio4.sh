
#!/bin/bash

# Comprobar si se proporciona un directorio como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 directorio"
    exit 1
fi

directorio="$1"

# Verificar si el directorio existe
if [ ! -d "$directorio" ]; then
    echo "El directorio no existe."
    exit 1
fi

# Generar listados de archivos y directorios
find "$directorio" -type f -executable > ejecutables.txt
find "$directorio" -type f ! -executable > normales.txt
find "$directorio" -type d > directorios.txt

echo "Listados generados:"
echo " - Archivos ejecutables: ejecutables.txt"
echo " - Archivos normales: normales.txt"
echo " - Directorios: directorios.txt"
