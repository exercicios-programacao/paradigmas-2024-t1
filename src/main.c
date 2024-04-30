#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int int_cmp(void *lhs, void *rhs);
int double_cmp(void *lhs, void *rhs);
int string_cmp(void *lhs, void *rhs);

int main(int argc, char **argv) {
  printf("Hello World!\n");
  return 0;
}

int int_cmp(void *lhs, void *rhs) {
  int *lhs_ptr = (int *)lhs;
  int *rhs_ptr = (int *)rhs;
  return (*lhs_ptr - *rhs_ptr);
}

int double_cmp(void *lhs, void *rhs) {
  double *lhs_ptr = (double *)lhs;
  double *rhs_ptr = (double *)rhs;
  if ((*lhs_ptr - *rhs_ptr) > 0)
    return 1;
  if ((*lhs_ptr - *rhs_ptr) < 0)
    return -1;
  return 0;
}

int string_cmp(void *lhs, void *rhs) {
  char *lhs_ptr = (char *)lhs;
  char *rhs_ptr = (char *)rhs;
  return strcmp(lhs_ptr, rhs_ptr);
}
