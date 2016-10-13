#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
  printf("Before\n");
  pid_t pid = fork();
  assert(pid >= 0);
  bool parent = pid > 0;
  if ((random() % 2 == 0) == parent)
    sleep(1);
  if (parent) waitpid(pid, NULL, 0);
}



