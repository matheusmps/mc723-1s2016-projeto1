#!/bin/bash

# definir valores de teste
for val in 1000000, 10000000
do
	echo ""
	echo "----- Executando para n = $val -----"
	for i in $(seq 1 10)
	do
		echo ""
		echo "-- Execucao $i para n = $val --"
		time ./DFT1D $val
	done
done
