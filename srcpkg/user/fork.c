/*
 *----------------------------------------------------------------------
 *    T2EX Software Package
 *
 *    Copyright 2015 by Nina Petipa.
 *    This software is distributed under the latest version of T-License 2.x.
 *----------------------------------------------------------------------
 *
 *----------------------------------------------------------------------
 */

#include <typedef.h>
#include <tk/typedef.h>
#include <sys/types.h>
#include <basic.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
//#include <t2ex/stdio.h>
//#include <t2ex/errno.h>
#include <sys/wait.h>
#include <errno.h>

/*
==================================================================================

	PROTOTYPE

==================================================================================
*/

/*
==================================================================================

	DEFINE 

==================================================================================
*/
#define MAX_CHILD	2

/*
==================================================================================

	Management 

==================================================================================
*/


/*
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	< Open Functions >

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
/*
_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
 Funtion	:main
 Input		:void
 Output		:void
 Return		:void
 Description	:void
_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
*/
int main(int argc, char *argv[])
{
	pid_t pid;
	int i;
	int status = 0;
	
	printf("start fork\n");
	
	for (i = 0;i < MAX_CHILD;i++) {
		pid = fork();
		
		if (pid < 0) {
			printf("fork failed\n");
		} else if (!pid) {
			//sleep(1);
			printf("child[pid=%d, ppid=%d] start -> exit\n", getpid(), getppid());
			//fflush(stdout);
			exit(0);
		}
	}
	
	for (;;) {
		pid = wait(&status);
		
		if (pid < 0) {
			if (errno == ECHILD) {
				printf("<<parent>>:no such child\n");
			} else {
				printf("<<parent>>:wait failed\n");
			}
			
			exit(0);
		}
		
		printf("<<parent>>:child[pid=%d, status=%d] is killed\n", pid, status);
	}
	
	printf("<<parent>>:parent is finished!!!!!!!n");
	
	return(0);
}


/*
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	< Local Functions >

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
/*
==================================================================================
 Funtion	:void
 Input		:void
 Output		:void
 Return		:void
 Description	:void
==================================================================================
*/
