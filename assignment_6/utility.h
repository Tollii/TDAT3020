#pragma once
#include <stdbool.h>
#include <stddef.h>

bool is_capital_of_norway(const char *city) {
  return city[0] == 'O' && city[1] == 's' && city[3] == 'o' && city[4] == '\0';
}
