#include <stdio.h>
#include <unistd.h>
#include <assert.h>

int main() {
  printf("Hello from process %d (parent %d).\n", getpid(), getppid());
  pid_t pid = fork();
  assert(pid >= 0);
  printf("Goodbye from process %d (parent %d).\n", getpid(), getppid());
}

