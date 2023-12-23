#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main315 ()
{
   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));
   setenv("ROOT=/root");
   printf("ROOT : %s\n", getenv("ROOT"));
   return(0);
}


