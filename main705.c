#include <stdio.h>
#include <unistd.h>
int main705(void)
{
        printf("Using _exit...\n");
        printf("This is the content in buffer");
        _exit(0);
}

