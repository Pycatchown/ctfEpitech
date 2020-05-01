#include <stdio.h>
#include <string.h>

int main(int argc, char *const argv[])
{
  if (argc != 2)
    return 1;

  if (!strcmp("flag{34sy_r1ght?}", argv[1]))
    printf("Well Done, you can validate the challenge with this flag.\n");
  else
    printf("Better luck next time...\n");
    
  return 0;
}
