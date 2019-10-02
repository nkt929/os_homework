#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> 
#include <pthread.h>

int main(){
  int fds[2], pid; // 0 - pass TO, 1 - pass FROM

  if(pipe(fds) < 0){ // creating a pipe with the pase on fib array
    exit(0);
  }

  if(pid=fork()){
    //child process
    char text[16];
    printf("Ener the text to pipe\n");
    scanf("%s", text);
    write(fds[1], text, 16); // system write: (from, value, size)
    close(fds[1]);
  }else{
    // parent process
    char buffer[16];
    int result;
    while((result=read(fds[0], buffer, 16)) == 0 ){  // system read: (to, to_exact, size)
      ; //busy waiting
    }
    printf("The text is: %s", buffer);
    close(fds[0]);

  }
  return 0;
}