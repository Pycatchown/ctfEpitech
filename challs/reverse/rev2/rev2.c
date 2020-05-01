#include <stdio.h>
#include <string.h>


int main(int argc, char *const argv[])
{
  if (argc != 2)
    return 1;

  char *flag = strdup("cidb~1Zi4qqi6Zg4qZfi5v6w+++x");
  for (int i = 0; i < strlen(flag); ++i)
    flag[i] ^= 5;

  if (!strcmp(flag, argv[1]))
    printf("Well Done, you can validate the challenge with this flag.\n");
  else
    printf("Better luck next time...\n");
    
  return 0;
}
