#include <stdio.h>
#include <unistd.h>



int main(int argc, char *argv[]) {
  int printf("Before\n");
  pid_t pid = fork();
  if (pid == 0) {
    printf("Hi I'm child (%d).\n", getpid());
  }
  return 110;
} else {
  int status;
  waitpid(pid, &status, 0);

  if (WIFEXITED(status)) {
    printf("%d ended: code %d.\n", pid, WEXITSTATUS(status));
  } else {
  printf("%d crashed with signal number %d.\n", WTERMSIG(status), getpid());
  }

}

