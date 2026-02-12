#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>

 

int main() {

   pid_t pid;

 

   pid = fork();   // create child process

 

   if (pid < 0) {

       printf("Fork failed\n");

   }

   else if (pid == 0) {

       // Child process

       printf("Child Process\n");

       printf("Child PID = %d\n", getpid());

       printf("Parent PID = %d\n", getppid());

   }

   else {

       // Parent process

       wait(NULL);   // wait for child to finish

       printf("Parent Process\n");

       printf("Parent PID = %d\n", getpid());

       printf("Child PID = %d\n", pid);

   }

 

   return 0;

}
