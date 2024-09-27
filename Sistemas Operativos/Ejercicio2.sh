#!/bin/bash

# Comprobar si se proporciona un dominio como argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 dominio"
    exit 1
fi

dominio="$1"
ip="127.0.0.1"

# Comprobar si el dominio ya existe en el archivo /etc/hosts
if grep -q "$dominio" /etc/hosts; then
    echo "El dominio $dominio ya existe en /etc/hosts"
    exit 1
fi

# Agregar la línea al archivo /etc/hosts
echo "$ip $dominio" | sudo tee -a /etc/hosts

echo "El dominio $dominio ha sido agregado al archivo /etc/hosts y apunta a $ip."
