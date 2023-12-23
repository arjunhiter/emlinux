#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };
int cmpfunc (const void * a, const void * b)
{
    return (*((int*)a)-*((int*)b));
}

int main313()
{
	int n;
	printf("排序之前的列表：\n");
	for( n = 0 ; n < 5; n++ ) {
		printf("%d ", values[n]);
	}
	qsort(values, 5, sizeof(int), cmpfunc);
	printf("\n排序之后的列表：\n");
	for( n = 0 ; n < 5; n++ ) {
		printf("%d ", values[n]);
	}
	printf("\n");
	return(0);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main313_stub_18()
{
    printf("main313 go.\n");
}

#define main313 main313_(__LINE__)
#define main313_(line) main313__(line)
#define main313__(line) main313_stub_## line

int main()
{
	main313();
   
   return 0;
}
*/

