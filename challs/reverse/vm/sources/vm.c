#include "vm.h"

char code[] = {
  1, 27, 'd', 'u', 'd', 'e', ' ', 'c', 'r', 'a', 'c', 'k', 'm', 'e', ' ', 'a', 'r', 'e', ' ', 't', 'h', 'e', ' ', 'b', 'e', 's', 't', '!', '\n',
  5, 2,
  4, 23,
  3, 20,
  10, 57,
  5, 2,
  8, 1,
  10, 12,
  1, 32, 'I', ' ', 'w', 'i', 's', 'h', ' ', 'I', ' ', 'c', 'o', 'u', 'l', 'd', ' ', 'o', 'n', 'l', 'y', ' ', 'd', 'o', ' ', 'c', 'r', 'a', 'c', 'k', 'm', 'e', '!', '\n',
  4, 23,
  5, 2,
  3, 20,
  10, 30,
  5, 2,
  8, 1,
  10, 9,
  1, 17, 'b', 'e', 'c', 'a', 'u', 's', 'e', ' ', 't', 'h', 'e', 'y', ' ', 'a', 'r', 'e', ' ',
  4, 12,
  5, 2,
  3, 20,
  10, 11,
  5, 2,
  8, 1,
  10, 13,
  1, 19, '"', 'm', 'a', ' ', 'r', 'a', 'i', 's', 'o', 'n', ' ', 'd', '\'', 'e', 't', 'r', 'e', '"', '\n',
  4, 23,
  5, 1,
  3, 20,
  8, 1,
  5, 2,
  10, 28,
  10, 38,
  1, 21, 'I', ' ', 'l', 'o', 'v', 'e', ' ', 't', 'h', 'e', 'm', ' ', 's', 'o', ' ', 'm', 'u', 'c', 'h', '!', '\n',
  2,
  0
};

instruction_t instructions[] = {
  { vmexit, 0 },		/* 0 */
  { vmprint, -1 },		/* 1 */
  { vmcheck, 0 },		/* 2 */

  { vmadd, 1 },			/* 3 */
  { vmsub, 1 },			/* 4 */
  { vmmul, 1 },			/* 5 */
  { vmdiv, 1 },			/* 6 */
  { vmmod, 1 },			/* 7 */
  { vmshiftl, 1 },		/* 8 */
  { vmshiftr, 1 },		/* 9 */
  { vmxor, 1 },			/* 10 */
  { vmor, 1 },			/* 11 */
  { vmand, 1 },			/* 12 */
  { vmnot, 0 },			/* 13 */
  { vminv, 0 }			/* 14 */
};


// the flag is 63fdc57dc852869e716b317af91773eb

int main(int argc, char **argv)
{
  if (argc == 2 && strlen(argv[1]) == 32)
    {
      for (int idx = 0, i = 0;; i++, idx++)
	{
	  instruction_t instruction = instructions[(int)code[idx]];
	  char res = instruction.function(&argv[1][i], &code[idx]);
	  if (res == -1)
	    idx += code[idx + 1] + 1;
	  else
	    idx += instruction.nb_params;
	}
    }
  return 0;
}
