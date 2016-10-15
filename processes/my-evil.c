#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  
  for (int i = 0; i < 8; i++) {
    if (fork() == 0) {
      exit(110 + i);
    }
  }

  int status;
  while (1) {
    pid_t pid = waitpid(-1 , &status, 0);
    if (WIFEXITED(status)) {
      printf("Child return %d.\n", WEXITSTATUS(status));
    } else {
      printf("Uh oh~\n");
    }
  }
  return 0;
}



