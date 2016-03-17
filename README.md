# FFTW - Grupo 8

## O que faz? Para que serve?
O FFTW é na verdade uma biblioteca de subrotinas em C para computar a transformada discreta de Fourier (DFT) em uma ou mais dimensões, de tamanho de entrada variável e com dados reais e complexos. O programa que criamos com essa biblioteca calcula a transformada discreta de Fourier complexa unidimensional. A entrada do programa é um sinal de n pontos, composto de partes reais e complexas, e a saída são as amplitudes das ondas senoidais da transformada. O programa também faz a operação inversa. Ele recebe as amplitues das ondas senoidais e calcula os sinais de entrada passados anteriormente.

No final, foram criados dois programas, o DFT1D e o DFT1D_IO. O primeiro, calcula as transformações explicadas acima, mas não imprime os resultados obtidos. Dessa forma, o tempo de execução restringe-se as operações matemáticas calculadas pelo processador.  Já o segundo, além de calcular as transformações, imprime no arquivo results.txt os resultados obtidos, o que aumenta o tempo de execução do programa.

## Por que é bom para medir desempenho?
O programa mede o tempo de execução de operações matemáticas pelo processador. A maior atividade do processador quando executado está na Unidade Lógica e Aritmética (ULA). Como uma das versões escreve na memória e a outra não, podemos comparar os resultados e chegar a conclusões mais precisas do tempo que leva as operações de escrita na memória e de processamento.
O programa aqui não faz uso de multithreads, utilizando apenas um core do processador.

## O que baixar?
A biblioteca FFTW pode ser obtida no [site oficial do FFTW](http://www.fftw.org). A última versão disponibilizada é a 3.3.4. 

## Como compilar/instalar
Para instalá-la na máquina (com sistemas Unix) basta acessar o diretório obtido por download e executar as seguintes linhas de comando:

```
./configure
make
make install
```
Isso irá montar as bibliotecas de transformações complexas e reais junto com os programas de teste.

Após a instalação, é possível escrever programas em C utilizando a biblioteca FFTW. Para compilar programas em C que utilizam essa biblioteca no gcc, basta utilizar a linha de comando:

```
gcc -o programa programa.c -lfftw3 -lm
```

As flags _-lfftw3_ e _-lm_ irão linkar a biblioteca fttw3 ao código.

Para facilitar nós já criamos um arquivo Makefile que produz os executáveis dos dois programas DFT1D e DFT1D_IO. Para isso basta utilizar o comando _make_ na raiz do repositório.

## Como executar
Ambos os programas, após compilados, podem ser executados com apenas um parâmetro sizeDFT. Esse parâmetro representa o tamanho do vetor de entrada, ou seja, quantos pontos estão definidos no sinal de entrada. Esse parâmetro é passado na própria linha de comando. Assim, o comando para execução dos programas é:

```
./DFT1D 70000000
./DFT1D_IO 2000000
```

## Como medir o desempenho
O desempenho deve ser medido através de tempo. O que foi feito para essa medição foi utilizar o comando _time_ e obter uma média dos resultados obtidos para a mesma entrada:

```
time ./DFT1D 70000000
```

A medida deve ser feita entre 5 e 10 vezes para cada tipo de entrada a fim de diminuir a margem de erro.

## Como apresentar o desempenho
O desempenho deve ser apresentado em segundos através do comando time. Considere uma margem de erro de 3% segundo os cálculos. 

## Medições base (uma máquina)
Primeiro foi calculado o desempenho de execução do DFT1D, com parâmetro sizeDFT de 70.000.000, em uma máquina com processador Intel Core i7-450HQ:

> DFT1D:
>  Aplica FFTW3 sobre um único vetor complexo.
>
>  Transforma a entrada em coeficiente da DFT.
>  Reverte os coeficientes da DFT obtida nos dados originais.
>  Compara os dados originais com os obtidos.
>
>  Criando um vetor aleatório de entrada...
>
>  Criando um vetor de saída com os coeficientes da DFT...
>
>  Recuperando o vetor original a partir dos coeficientes da DFT...
>
>  Fim da execução do algoritmo.
>
>real	0m15.374s
>user	0m13.580s
>sys	0m1.609s

Fazendo uma média de 5 medidas, o tempo final foi de **real 14.700s**.

Depois foi calculado o desempenho de execução do DFT1D_IO, com parâmetro sizeDFT de 3.000.000, para a mesma máquina com o comando *time*. O resultado obtido foi:

>DFT1D:
>  Aplica FFTW3 sobre um único vetor complexo.
>
>  Transforma a entrada em coeficiente da DFT.
>  Reverte os coeficientes da DFT obtida nos dados originais.
>  Compara os dados originais com os obtidos.
>
>  Criando um vetor aleatório de entrada...
>
>  Criando um vetor de saída com os coeficientes da DFT...
>
>  Recuperando o vetor original a partir dos coeficientes da DFT...
>
>  Fim da execução do algoritmo.
>
>real	0m15.739s
>user	0m14.918s
>sys	0m0.701s

Fazendo uma média de 5 medidas, o tempo final foi de **real 16.010s**.

Percebemos que o tempo de execução de DFT1D_IO é maior, mesmo que o valor do parâmetro sizeDFT passado seja aproximadamente 23 vezes menor que o de DFT1D. Ou seja, a impressão dos valores em um arquivo.txt é muito mais demorada do que as operações lógicas executadas, devido às operações de acesso a memória.
