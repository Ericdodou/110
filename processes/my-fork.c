#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
  printf("Before\n");
  pid_t pid = fork();
  assert(pid >= 0);
  bool parent = pid > 0;
  if (parent) wait(pid, NULL, 0);
  else sleep(1);
  printf("After pid %d (parent %d)\n", getpid(), getppid());

}



