#include "../utility.h"
#include <stdlib.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  char *test = manipulate_string((const char *)data, size);
  free(test);
  return 0;
}
