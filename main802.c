#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
 
/*闹钟信号处理函数*/
void sig_handler(int signal) {
 
    printf("hello world: %d\n", signal);
}

int main802(void)
{
	
	int i;
	signal(SIGALRM, sig_handler);
 
	struct itimerval new_timer;
	new_timer.it_interval.tv_sec = 1;
	new_timer.it_interval.tv_usec = 0;
	new_timer.it_value.tv_sec = 2;
	new_timer.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &new_timer, NULL);
 
	for (i = 0; i < 8; i++)
	{
		printf(" sleep % d ... \n", i);
		sleep(1);
	}
 
	return 0;

}

