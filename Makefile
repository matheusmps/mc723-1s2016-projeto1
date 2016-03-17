all: DFT1D.c DFT1D_IO.c
	gcc -o DFT1D DFT1D.c -lfftw3 -lm
	gcc -o DFT1D_IO DFT1D_IO.c -lfftw3 -lm
