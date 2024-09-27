
#!/bin/bash

# Comprobar si se proporcionan cinco palabras y el tipo de orden
if [ $# -ne 6 ]; then
    echo "Uso: $0 <ASC/DES> palabra1 palabra2 palabra3 palabra4 palabra5"
    exit 1
fi

# Capturar el tipo de orden (ASC o DES)
tipo_orden="$1"

# Comprobar si el tipo de orden es válido
if [ "$tipo_orden" != "ASC" ] && [ "$tipo_orden" != "DES" ]; then
    echo "El primer parámetro debe ser 'ASC' o 'DES'."
    exit 1
fi

# Eliminar el primer parámetro (tipo de orden) de la lista de palabras
shift

# Ordenar las palabras en el tipo de orden especificado
if [ "$tipo_orden" == "ASC" ]; then
    palabras_ordenadas=$(echo "$@" | tr ' ' '\n' | sort)
else
    palabras_ordenadas=$(echo "$@" | tr ' ' '\n' | sort -r)
fi

# Mostrar las palabras ordenadas
echo "Palabras ordenadas de forma $tipo_orden:"
echo "$palabras_ordenadas"
