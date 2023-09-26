#!/usr/bin/env bash

FOLDER=$1

make all

./bin/Prueba.out > salida.txt
if [ $? == 0 ]; then
    SALIDA=$(cat salida.txt)
    SALIDA_ESPERADA=$(cat salida_esperada.txt)
    
    if [[ "$SALIDA" == "$SALIDA_ESPERADA" ]]; then
        mkdir -p "$FOLDER"
        cp Main.cpp casos.txt salida.txt "$FOLDER"
        echo "Test pasado"
    else
        echo "Test no superado"
    fi
else
    echo "No compila"
fi
