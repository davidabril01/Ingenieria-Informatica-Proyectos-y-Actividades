
#!/bin/bash

# Comprobar si se proporciona una palabra como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 palabra"
    exit 1
fi

palabra="$1"
longitud=${#palabra}

# Verificar si la palabra es válida (no está vacía)
if [ $longitud -eq 0 ]; then
    echo "La palabra no puede estar vacía."
    exit 1
fi

# Crear el archivo "palabras-repetidas.txt" y mostrar la longitud de la palabra
echo "La longitud de la palabra es $longitud caracteres." > palabras-repetidas.txt

# Repetir la palabra la cantidad de veces que tenga caracteres
for ((i=0; i<$longitud; i++)); do
    echo "$palabra" >> palabras-repetidas.txt
done

echo "El resultado se ha guardado en el archivo palabras-repetidas.txt"
