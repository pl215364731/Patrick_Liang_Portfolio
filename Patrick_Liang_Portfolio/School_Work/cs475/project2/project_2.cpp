#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define CSV

int	NowYear;		// 2023 - 2028
int	NowMonth;		// 0 - 11

float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;		// rye grass height in inches
bool    NowWinterstorm;
int	NowNumRabbits;		// number of rabbits in the current population

unsigned int seed = 0;
omp_lock_t	Lock;
volatile int	NumInThreadTeam;
volatile int	NumAtBarrier;
volatile int	NumGone;

const float RYEGRASS_GROWS_PER_MONTH =		20.0;
const float ONE_RABBITS_EATS_PER_MONTH =	 1.0;

const float AVG_PRECIP_PER_MONTH =	       12.0;	// average
const float AMP_PRECIP_PER_MONTH =		4.0;	// plus or minus
const float RANDOM_PRECIP =			2.0;	// plus or minus noise

const float AVG_TEMP =				60.0;	// average
const float AMP_TEMP =				20.0;	// plus or minus
const float RANDOM_TEMP =			10.0;	// plus or minus noise

const float MIDTEMP =				60.0;
const float MIDPRECIP =				14.0;

void InitBarrier( int n )
{
    NumInThreadTeam = n;
    NumAtBarrier = 0;
	omp_init_lock( &Lock );
}

// have the calling thread wait here until all the other threads catch up:
void WaitBarrier( )
{
    omp_set_lock( &Lock );
    {
        NumAtBarrier++;
        if( NumAtBarrier == NumInThreadTeam )
        {
            NumGone = 0;
            NumAtBarrier = 0;
            // let all other threads get back to what they were doing
            // before this one unlocks, knowing that they might immediately
            // call WaitBarrier( ) again:
            while( NumGone != NumInThreadTeam-1 );
            omp_unset_lock( &Lock );
            return;
        }
    }
    omp_unset_lock( &Lock );

    while( NumAtBarrier != 0 );	// this waits for the nth thread to arrive

    #pragma omp atomic
    NumGone++;			// this flags how many threads have returned
}

float Sqr( float x )
{
    return x*x;
}

float Ranf( unsigned int *seedp,  float low, float high )
{
    float r = (float) rand_r( seedp );              // 0 - RAND_MAX

    return(   low  +  r * ( high - low ) / (float)RAND_MAX   );
}

void calculateEnvVar(){
    float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

    float temp = AVG_TEMP - AMP_TEMP * cos( ang );
    if(NowWinterstorm){
        temp = 30;
    }
    NowTemp = temp + Ranf( &seed, -RANDOM_TEMP, RANDOM_TEMP );
    

    float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
    NowPrecip = precip + Ranf( &seed,  -RANDOM_PRECIP, RANDOM_PRECIP );
    if(NowWinterstorm){
        NowPrecip += 2;
    }
    if( NowPrecip < 0. )
        NowPrecip = 0.;
}

void Rabbits(){
    while( NowYear < 2029 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        int nextNumRabbits = NowNumRabbits;
        int carryingCapacity = (int)( NowHeight );
        if( nextNumRabbits < carryingCapacity )
            nextNumRabbits++;
        else
            if( nextNumRabbits > carryingCapacity )
                nextNumRabbits--;

        if( nextNumRabbits < 0 )
            nextNumRabbits = 0;

        // DoneComputing barrier:
        WaitBarrier( );
        NowNumRabbits = nextNumRabbits;

        // DoneAssigning barrier:
        WaitBarrier( );

        // DonePrinting barrier:
        WaitBarrier( );
    }
}

void RyeGrass(){
    while( NowYear < 2029 )
    {
        // compute a temporary next-value for this quantity
        // based on the current state of the simulation:
        float tempFactor = exp(   -Sqr(  ( NowTemp - MIDTEMP ) / 10.  )   );

        float precipFactor = exp(   -Sqr(  ( NowPrecip - MIDPRECIP ) / 10.  )   );

        float nextHeight = NowHeight;
        nextHeight += tempFactor * precipFactor * RYEGRASS_GROWS_PER_MONTH;
        nextHeight -= (float)NowNumRabbits * ONE_RABBITS_EATS_PER_MONTH;
        if( nextHeight < 0. ) nextHeight = 0.;

        // DoneComputing barrier:
        WaitBarrier( );
        NowHeight = nextHeight;

        // DoneAssigning barrier:
        WaitBarrier( );

        // DonePrinting barrier:
        WaitBarrier( );
    }
}

void Winterstorm(){
    while( NowYear < 2029 )
    {
        // Winterstorms only come between october to march
        // Winterstorms will not come 2 months in a row
        // When winterstorm comes, temperature 
        bool nextWinterStorm = false;

        if(NowMonth >= 9 || NowMonth <= 2){
            float temp = Ranf( &seed, 0, 10 );
            if(temp <= 1){
                nextWinterStorm = true;
            }
            if(NowWinterstorm){
                nextWinterStorm = false;
            }
        }
        
        // DoneComputing barrier:
        WaitBarrier( );
        NowWinterstorm = nextWinterStorm;

        // DoneAssigning barrier:
        WaitBarrier( );

        // DonePrinting barrier:
        WaitBarrier( );
    }
}

void Watcher(){
    while( NowYear < 2029 )
    {
        // DoneComputing barrier:
        WaitBarrier( );

        // DoneAssigning barrier:
        WaitBarrier( );
        calculateEnvVar();
        NowMonth++;
        if(NowMonth == 12){
            NowMonth = 0;
            NowYear++;
        }

        #ifdef CSV
            fprintf(stderr, "%d, %d, %.3f, %.3f, %.3f, %d, %d\n",
                    NowYear, NowMonth, NowPrecip, NowTemp, NowHeight, NowNumRabbits, (NowWinterstorm ? 20 : 0));
        #else
            fprintf(stderr, "Year: %d; Month: %d; Precip: %.3f; Temp: %.3f; Height: %.3f; Rabbits: %d \n",
                    NowYear, NowMonth, NowPrecip, NowTemp, NowHeight, NowNumRabbits);
        #endif
        

        // DonePrinting barrier:
        WaitBarrier( );
    }
}

main( int argc, char *argv[ ] )
{
#ifdef _OPENMP
	//fprintf( stderr, "OpenMP is supported -- version = %d\n", _OPENMP );
#else
    fprintf( stderr, "No OpenMP support!\n" );
    return 1;
#endif

    // starting date and time:
    NowMonth =    0;
    NowYear  = 2023;

    // starting state (feel free to change this if you want):
    NowNumRabbits = 1;
    NowHeight =  5.;
    NowWinterstorm = false;

    calculateEnvVar();

    omp_set_num_threads( 4 );	// same as # of sections
    InitBarrier(4);
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            Rabbits( );
        }

        #pragma omp section
        {
            RyeGrass( );
        }

        #pragma omp section
        {
            Watcher( );
        }

        #pragma omp section
        {
            Winterstorm( );	// your own
        }
    }       // implied barrier -- all functions must return in order
            // to allow any of them to get past here


}