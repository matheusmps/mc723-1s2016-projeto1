#!/bin/bash

# definir valores de teste para DFT1D
for val in 60000000, 100000000
do
	echo ""
	echo "----- Executando para n = $val -----"
	for i in $(seq 1 5)
	do
		echo ""
		echo "-- Execucao $i para n = $val --"
		time ./DFT1D $val
	done
done

# definir valores de teste para DFT1D_IO
for val in 2000000, 5000000
do
	echo ""
	echo "----- Executando para n = $val -----"
	for i in $(seq 1 5)
	do
		echo ""
		echo "-- Execucao $i para n = $val --"
		time ./DFT1D_IO $val
	done
done
