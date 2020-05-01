#include <stdio.h>
#include <string.h>

char *encrypt_flag(char *inpt)
{
  for (int i = 0; inpt[i]; i++)
    {
      inpt[i] = ((inpt[i] * i) % (127 - ' ')) + ' ';
      inpt[i] ^= inpt[i + 1];
    }
  return inpt;
}

int main(int argc, char *const argv[])
{
  if (argc != 2)
    return 1;

  char flag_encrypted[] = {
    76, 76, 67, 67, 102, 100, 106, 20, 54, 95, 28, 71, 18, 9, 93, 15, 86, 6, 14, 83, 7, 72, 119, 66, 89, 24, 99, 9, 123, 89, 77
  };
 
  if (!strcmp(flag_encrypted, encrypt_flag(strdup(argv[1]))))
    printf("Well Done, you can validate the challenge with this flag.\n");
  else
    printf("Better luck next time...\n");
    
  return 0;
}
