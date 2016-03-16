# include <stdlib.h>
# include <stdio.h>

# include <fftw3.h>

int main ( int argc, char** argv );
void DFT1D ( int sizeDFT );

int main ( int argc, char** argv )
{
    int sizeDFT;
    
    //Recebe o tamanho da transformação que será computada
    sizeDFT = atoi(argv[1]);
    
    //Executa o FFTW em DFTs complexas unidimensionais
    DFT1D ( sizeDFT );
    
    return 0;
}

/*
 DFT1D: Executa o FFTW em DFTs complexas unidimensionais.
 
 Gera sizeDFT valores complexos aleatórios, guardados como
 um vetor do tipo FFTW_COMPLEX chamado "IN".
 
 Assim FFTW3 computa a transformada de Fourier desse dado e guarda o resultado em "OUT".
 
 Em seguida FFTW3 computa a inversa da transformada de Fourier em "OUT" para
 "IN2", que deve ser a entrada original, redimensionada por sizeDFT.
 
 Obs.: Nessa implementação não há impressão dos valores dos vetores obtidos.
 */
void DFT1D ( int sizeDFT )
{
    int i;
    FILE *f = fopen("results.txt", "w");
    fftw_complex *in;
    fftw_complex *in2;
    fftw_complex *out;
    fftw_plan plan_backward;
    fftw_plan plan_forward;
    unsigned int seed = 123456789;
    
    printf ("DFT1D:\n" );
    printf ("  Aplica FFTW3 sobre um único vetor complexo.\n" );
    printf ("\n" );
    printf ("  Transforma a entrada em coeficiente da DFT.\n" );
    printf ("  Reverte os coeficientes da DFT obtida nos dados originais.\n" );
    printf ("  Compara os dados originais com os obtidos.\n" );
    
    //Cria o vetor de entrada
     
    in = fftw_malloc ( sizeof ( fftw_complex ) * sizeDFT );
    
    srand ( seed );
    
    printf("\n");
    printf("  Criando um vetor aleatório de entrada...\n");
    for ( i = 0; i < sizeDFT; i++ )
    {
        in[i][0] = rand ( );
        in[i][1] = rand ( );
    }
    
    //Cria o vetor de saída.
     
    out = fftw_malloc ( sizeof ( fftw_complex ) * sizeDFT );
    
    printf("\n");
    printf("  Criando um vetor de saída com os coeficientes da DFT...\n");
    plan_forward = fftw_plan_dft_1d ( sizeDFT, in, out, FFTW_FORWARD, FFTW_ESTIMATE );
    
    fftw_execute ( plan_forward );
    
    //Recria o vetor de entrada
    
    in2 = fftw_malloc ( sizeof ( fftw_complex ) * sizeDFT );
    
    printf("\n");
    printf("  Recuperando o vetor original a partir dos coeficientes da DFT...\n");
    plan_backward = fftw_plan_dft_1d ( sizeDFT, out, in2, FFTW_BACKWARD, FFTW_ESTIMATE );
    
    fftw_execute ( plan_backward );
    
    printf("\n");
    printf("  Fim da execução do algoritmo.\n");
    
    //Libera a memória alocada
    
    fftw_destroy_plan ( plan_forward );
    fftw_destroy_plan ( plan_backward );
    
    fftw_free ( in );
    fftw_free ( in2 );
    fftw_free ( out );
    
    return;
}