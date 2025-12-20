 #include <sys/types.h>
 #include <sys/wait.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
 

void signal_handler(int signo){
printf("Signal received!        signal number : %d\n",signo);
}
int main(int argc, char *argv[])
{  
   int child;
   child = fork();
   
   if(child == 0){
   signal(SIGUSR1, signal_handler);
   printf("Child ID: %d, waiting for parents signal...\n", getpid());
   while(1) pause(); 
   }
   else{
   printf("Parent ID: %d, Child ID: %d\n", getpid(), child);
   sleep(2);
   printf("Parent sending SIGUSR1 to child..\n");
   kill(child, SIGUSR1);
   sleep(1);
   printf("Terminating child process...(SIGTERM)\n");
   kill(child, SIGTERM);
   }
   return 0;
}
