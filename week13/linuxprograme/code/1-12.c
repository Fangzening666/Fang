#include "my.h"
	
int main()
{
	sigset_t base_mask,waitint_mask,oldmask;
	int sig;
	sigemptyset(&base_mask);
	sigaddset (&base_mask,SIGQUIT);
	sigaddset (&base_mask,SIGINT);
	if(sigprocmask(SIG_BLOCK,&base_mask,&oldmask)<0)
		err_exit("SIG_BLOCK error");
	printf("I have blocked SIGQUIT and SIGINT,and\n you can try"
			"to send these two signals and wait for my reply.\n");
	sleep(10);
	printf("Let me see if there is any pending signal.\n");
	sigpending(&waitint_mask);
	for(sig=1;sig<NSIG;sig++)

	if(sigismember(&waitint_mask,sig))
	{
		psignal(sig,"There is a pending signal");

	}
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
	err_exit("SIG_SETMASK error");
	printf("Ther is no suspending signal.BYE!\n");
	exit(EXIT_SUCCESS);
}
