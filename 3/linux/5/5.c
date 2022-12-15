#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    switch(pid = fork()) {
        case -1: perror("fork");
            exit(1);
        case 0: 
        //child
            for (int i = 0; i < 50; i++) {
		        printf("5.1 - PID: %d-#%d\n",getpid(), i);
		        sleep(1);
	        }
        default: 
        //parent
            for (int i = 0; i < 100; i++) {
		        printf("5 - PID: %d-#%d\n", getpid(), i);
		        sleep(1);
	        }
    }
    
	return 0;
}
