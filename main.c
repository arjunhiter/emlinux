
#include <stdio.h>
#include <stdlib.h>

void main310(void);
void main311(void);
/*int main601(void);
int main602(void);
int main603(void);
int main701(void);
int main702(void);
int main703(void);
int main704(void);
int main705(void);
int main706(void);
int main707(void);
int main801(void);
int main1001(void);
int main1010(void);*/

int main(int argc,char *argv[])
{
	int i = 1000;

	while (i)
	{
		printf("%s", "Input the command:");
		scanf("%d", &i);

		switch (i)
		{
		  case 1:
	
			break;
		  case 2:	  	
		    	break;
		  case 310:
		  	main310();
		    	break;
		  case 311:
		  	main311();
		    	break;
/*		  case 601:
		  	main601();
		    	break;
		  case 602:
		  	main602();
		    	break;
		  case 603:
		  	main603();
		    	break;	
		  case 701:
		  	main701();
		    	break;	
		  case 702:
		  	main702();
		    	break;
		  case 703:
		  	main703();
		    	break;
		  case 704:
		  	main704();
		    	break;
		  case 705:
		  	main705();
		    	break;
		  case 706:
		  	main706();
		    	break;
		  case 707:
		  	main707();
		    	break;
		  case 801:
		  	main801();
		    	break;		
		  case 1001:
		  	main1001();
		    	break;
		  case 1010:
		  	main1010();
		    	break;*/
		  default:
		    break;

		}
	}

	exit(0);
}