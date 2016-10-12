#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

static const int kMaxPath = 1024;

static void listMatches(char path[], size_t length,
                        const char *pattern) {
  DIR *dir = opendir(path);
  strcpy(path + length, "/");
  length++;
  if (dir == NULL) return;
  while (true) {
    struct dirent *de = readdir(dir);
    if (de == NULL) break;
    if (strcmp(de->d_name, ".") == 0) continue;
    if (strcmp(de->d_name, "..") == 0) continue;  
    strcpy(path + length, de->d_name);
    struct stat st;
    lstat(path, &st); //info about directory entry
    if (S_ISREG(st.st_mode)) {
      if (strstr(de->d_name, pattern) != NULL) { 
	printf("%s\n", path);
      }
    } else if (S_ISDIR(st.st_mode)) {
      listMatches(path, length + strlen(de->d_name), pattern);
    }
  }
  closedir(dir);
}

int main(int argc, char *argv[]) {
  assert(argc == 3);
  const char *directory = argv[1];
  struct stat st;
  if (!S_ISDIR(st.st_mode)) return 0;
  size_t length = strlen(directory);
  char path[kMaxPath];
  strcpy(path, directory);
  const char *pattern = argv[2];
  listMatches(path, length, pattern);
  return 0;
}

