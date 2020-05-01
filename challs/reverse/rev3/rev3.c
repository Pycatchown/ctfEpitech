#include <stdio.h>
#include <string.h>


int main(int argc, char *const argv[])
{
  if (argc != 2)
    return 1;

  char *inpt = strdup(argv[1]);
  for (int i = 0; i < strlen(inpt); ++i)
    inpt[i] -= 6;

  if (!strcmp("`f[auh*Yfnl.]-Ynb+mYn+g-w", inpt))
    printf("Well Done, you can validate the challenge with this flag.\n");
  else
    printf("Better luck next time...\n");
    
  return 0;
}
