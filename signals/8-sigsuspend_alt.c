#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// signal, kill and pause are quite rudimentary and don't really allow
// fine-tuned control of signal handling. Also the forced asynchronosity
// of signal handler causes a lot of problems (race conditions). Many times
// before a critical section we may have to disable(SIG_IGN) a bunch of signals
// so we aren't disturbed in the critical section. And if we disable(SIG_IGN) we
// lose all the signals that reached us during the critical section. There
// should be some facility to block a set of signals before a critical section
// and then go through them all at the end. This and much more (like
// synchronosly waiting for specific signals) are implemented in a new group of
// system functions.

sigset_t set, old_set;
int ret;
int loop=0;
void SIGQUIT_handler() { printf("SIGQUIT was called.\n"); }

void SIGUSR1_handler(int n) { printf("SIGUSR1 was called.\n"); loop=1; }

void SIGUSR2_handler(int n) { printf("SIGUSR2 was called.\n");loop=1; }

int main() {

    signal(SIGUSR2, SIGUSR2_handler);
    signal(SIGUSR1, SIGUSR1_handler);
    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGUSR1);

    ret = sigprocmask(SIG_BLOCK, &set, &old_set);
    if(ret != 0) {
        perror("sigprocmask");
    }

    pid_t pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(0);
    } else if(pid == 0) {
        // CHILD PROCESS

        for(int i = 0; i < 4; i++) {
            printf("%d\n", i);
            sleep(1);
        }
        while(!loop)
        {
            printf("in loop\n");
        }
        int signum;
        sigsuspend(&set);
        printf("child here");
        sigprocmask(SIG_UNBLOCK, &set, NULL);

    } else {
        sleep(5);
        kill(pid,SIGUSR1);
        sleep(2);
        kill(pid,SIGUSR2);
        pause();
    }
    
} 
 
