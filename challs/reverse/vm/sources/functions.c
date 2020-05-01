#include "vm.h"

int vmexit(char *a, char *b)
{
  (void *)a;
  (void *)b;
  exit(84);
  return 0;
}

int vmprint(char *a, char *b)
{
  (void *)a;
  write(1, b + 2, b[1]);
  return -1;
}

int vmcheck(char *a, char *b)
{
  (void *)b;
  char *flag = "6fOxZjnhc!jF&lrl7%lv8bnlf\"1KnfyD";

  if (!strcmp(a - 33, flag))
    printf("YOU WIN !!!!!!\n");
  else
    printf("YOU LOOSE !!!!!!\n");

  return 0;
}
