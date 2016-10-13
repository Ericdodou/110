#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>


int main() {
  const char *trail = "abcd";
  for (int i = 0; i < 4; i++) {
    printf("%c\n", trail[i]);
    pid_t pid = fork();
    assert(pid >= 0);
  }
  return 0;
}

