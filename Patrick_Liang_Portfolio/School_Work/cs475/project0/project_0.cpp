#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef SIZE
#define SIZE       	100000	// array size -- you get to decide
#endif

#define NUMTRIES        20	// how many times to run the timing to get reliable timing data

float A[SIZE];
float B[SIZE];
float C[SIZE];

int
main( )
{
#ifdef   _OPENMP
	fprintf( stderr, "OpenMP version %d is supported here\n", _OPENMP );
#else
	fprintf( stderr, "OpenMP is not supported here - sorry!\n" );
	exit( 0 );
#endif

	// initialize the arrays:
	for( int i = 0; i < SIZE; i++ )
	{
		A[i] = 1.;
		B[i] = 2.;
	}

        //1 thread
        omp_set_num_threads(1);

        double maxMegaMults_1 = 0.;

        for( int t = 0; t < NUMTRIES; t++ )
        {
                double time0 = omp_get_wtime( );

                #pragma omp parallel for
                for( int i = 0; i < SIZE; i++ )
                {
                        C[i] = A[i] * B[i];
                }

                double time1 = omp_get_wtime( );
                double megaMults = (double)SIZE/(time1-time0)/1000000.;
                if( megaMults > maxMegaMults_1 )
                        maxMegaMults_1 = megaMults;
        }

        fprintf( stderr, "For %d threads, Peak Performance = %8.2lf MegaMults/Sec\n", 1, maxMegaMults_1 );

        // 4 threads
        omp_set_num_threads(4);

        double maxMegaMults_4 = 0.;

        for( int t = 0; t < NUMTRIES; t++ )
        {
                double time0 = omp_get_wtime( );

                #pragma omp parallel for
                for( int i = 0; i < SIZE; i++ )
                {
                        C[i] = A[i] * B[i];
                }

                double time1 = omp_get_wtime( );
                double megaMults = (double)SIZE/(time1-time0)/1000000.;
                if( megaMults > maxMegaMults_4 )
                        maxMegaMults_4 = megaMults;
        }

        fprintf( stderr, "For %d threads, Peak Performance = %8.2lf MegaMults/Sec\n", 4, maxMegaMults_4 );

	double s =  maxMegaMults_4 / maxMegaMults_1;
        fprintf( stderr, "Speedup S = %8.2lf\n", s);

        float Fp = (4./3.)*( 1. - (1./s) );
        fprintf( stderr, "Parallel fraction Fp = %8.5lf\n", Fp);
        return 0;
}
