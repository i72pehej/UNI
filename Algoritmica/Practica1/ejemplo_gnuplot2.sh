#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "graficoMatriz.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'tiemposMatriz.txt' using 1:3 t "Datos columna 3 frente a 1" w l
_end_
