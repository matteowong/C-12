#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int f1,f2, status;
  printf("Pre-fork. Parent PID: %d\n",getpid());
  f1=fork();
  if (f1==0) {//first child process
    printf("First child PID: %d\n",getpid());
    int ret=rand()%16 + 5;
    sleep(ret);
    printf("First child finished sleeping\n");
    return ret;
  }
  else {
    f2=fork();
    if (f2==0) {
      printf("Second child PID: %d\n",getpid());
      rand();
      int ret=rand()%16+5;
      sleep(ret);
      printf("Second child finished sleeping\n");
      return ret;
    }
    else {
      printf("Child process finished PID: %d\n",wait(&status));
      printf("Slept for: %d\n",WEXITSTATUS(status));
    }
    


  }


  return 0;
}
