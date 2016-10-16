#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>


int parseCommandLine(char command[], char *arguments[], int n) {
  return 1;
}

int main(int argc, char *argv[]) {
  
  while (true) {
    printf("simplesh> ");
    char command[1024];
    getCommandLine(command, 1024);
    char *arguments[128];
    int count = parseCommandLine(command, arguments, 1024);
    if (count == 0) continue;
    if (strcmp(arguments[0], "quit") == 0) break;
    bool background = strcmp(arguments[count - 1], "&") == 0;
    if (background) arguments[--count] = NULL;
    pid_t pid = fork();
    if (pid == 0) {
      execvp(arguments[0], arguments);
      printf("command not found: %s", arguments);
    }
  }
  printf("\n");
  return 0;
}















