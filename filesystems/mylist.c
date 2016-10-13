#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>


static void updatePermissionBit(bool test, char perms[], int column, char ch) {
  if (test) perms[column] = ch;
}

static const char kPermissionChars[] = {'r', 'w', 'x'};
static const mode_t kPermissionFlags[] = {
	S_IRUSR, S_IWUSR, S_IXUSR,
	S_IRGRP, S_IWGRP, S_IXGRP,
	S_IROTH, S_IWOTH, S_IXOTH
};


static void listPermissions(mode_t mode) {
  // -> -rwxr--rw-
  char permissions[11]; // 10 + 1
  memset(permissions, '-', 11);
  permissions[10] = '\0'; // -> "----------"
  updatePermissionBit(S_ISLNK(mode), permissions, 0, '1');
  updatePermissionBit(S_ISDIR(mode), permissions, 0, 'd');
  
  for (size_t i = 0; i < 9; i++) {
    updatePermissionBit(mode & kPermissionFlags[i],
		        permissions,
			i + 1,
			kPermissionChars[i % 3]);
  }


  printf("%s", permissions);
}

int main(int argc, char *argv[]) {
  return 0;
}











