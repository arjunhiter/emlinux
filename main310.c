#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h> 

#include <string.h>
#include <memory.h> 

void main310(void)
{ 
	long *buffer; 
	size_t size; 
	if( (buffer = (long *)malloc( 1000 * sizeof( long ) )) == NULL ) 
		exit( 1 ); 
	/* size = _msize( buffer ); */ 
	size = sizeof( buffer )/sizeof( long );
	printf( "Size of block after malloc of 1000 longs: %u\n", size ); 
	/* Reallocate and show new size: */ 
	if( (buffer = realloc( buffer, size + (1000 * sizeof( long )) )) == NULL ) 
		exit( 1 ); 
	/* size = _msize( buffer ); */
	size = sizeof( buffer )/sizeof( long );
	printf( "Size of block after realloc of 1000 more longs: %u\n", size ); 
	free( buffer ); 
	exit( 0 ); 

	char src[] = "******************************";
	char dest[] = "abcdefghijlkmnopqrstuvwxyz0123456709";
	char *ptr;
	printf("destination before memcpy: %s\n", dest);
	ptr = memcpy(dest, src, strlen(src));
	if (ptr) 
		printf("destination after memcpy: %s\n", dest);
	else
		printf("memcpy failed\n");

	char buffer2[] = "Hello world\n";
	printf("Buffer before memset: %s\n", buffer2);
	memset(buffer2, '*', strlen(buffer2) - 1);
	printf("Buffer after memset: %s\n", buffer2); 

	
	char first[] = "12345678901234567890"; 
	char second[] = "12345678901234567891"; 
	int result; 
	result = memcmp( first, second, 19 ); 
	if( result < 0 ) 
		printf( "First is less than second.\n" ); 
	else if( result == 0 ) 
		printf( "First is equal to second.\n" ); 
	else if( result > 0 ) 
		printf( "First is greater than second.\n" ); 
	result = memcmp( first, second, 20 ); 
	if( result < 0 ) 
		printf( "First is less than second.\n" ); 
	else if( result == 0 ) 
		printf( "First is equal to second.\n" ); 
	else if( result > 0 ) 
		printf( "First is greater than second.\n" );
} 
