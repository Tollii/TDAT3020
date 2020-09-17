#include "utility.h"
#include <stdio.h>
#include <string.h>

char *manipulate_string(const char *line, size_t len);

int main() {

  //Read in line from user
  char *line = NULL;
  size_t len = 0;

  char *output = manipulate_string(line, len);
  printf("%s", output);

  char *example = "1 < 2 && 2 > 1";
  char *output2 = manipulate_string(example, strlen(example));

  printf("%s", output2);

  free(output2);
  free(output);
  return 0;
}
