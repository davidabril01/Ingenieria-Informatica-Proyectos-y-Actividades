#!/bin/bash

# Ruta al directorio /etc
directorio_etc="/etc"

# Nombre del archivo de salida
archivo_salida="listado_http.txt"

# Comando para buscar las líneas que contienen referencias a HTTP en /etc
grep -r "http://" "$directorio_etc" > "$archivo_salida"

echo "Listado de referencias HTTP en $directorio_etc guardado en $archivo_salida"
