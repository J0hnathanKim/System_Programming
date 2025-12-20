 #include <sys/types.h>
 #include <sys/wait.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <signal.h>
void alrm_handler(int sig) {
    printf("[Parent] Child terminated\n");
}

int main(){
int child = fork();
if(child == 0){
 int i = 1;
 while(1){
  printf("[Child] Counter : %d\n",i);
  i +=1;
  sleep(1);
 }
}
else{
alarm(7);
signal(SIGALRM, alrm_handler);
printf("Child starts for 7seconds\n");
pause();
kill(child, SIGTERM);
exit(0);
}
}
