#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#define N 100000000

int main( void )
{
    struct timeval tv;
    double begin, end;
    
    int i;
    char* a = malloc( N );
    char* b = malloc( N );
    
    gettimeofday( &tv, NULL );
    begin = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    
    for ( i = 0; i < N; i++ )
    		a[i] = i;
    
    gettimeofday( &tv, NULL );
    end = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    printf("Execution time for a loop: %fsec\n", (end - begin) / 1000);
    
    gettimeofday( &tv, NULL );
    begin = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    
    for ( i = 0; i < N; i++ )
    		b[i] = i;
    
    gettimeofday( &tv, NULL );
    end = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    printf("Execution time for b loop: %fsec\n", (end - begin) / 1000);
    
    return 0;
}