#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int mysystem(char *cmd) {
  pid_t pid = fork();
  if (pid == 0) {
    char *argv[] = {cmd, NULL};
    execvp(argv[0], argv);
    printf("command not found.\n");
    exit(0);
  }
  int status;
  waitpid(pid, &status, 0);
}

int main(int argc, char *argv[]) {
  while (true) {
    printf("> ");
    char command[128];
    fgets(command, 128, stdin);
    if (feof(stdin)) break;
    command =[strlen(command) - 1] = '\0';
    printf("retcode = %d\n", mysystem(command));
  }
  printf("\n");
  return 0;
}




