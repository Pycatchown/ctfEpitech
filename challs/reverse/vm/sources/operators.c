#include "vm.h"

int vmadd(char *a, char *b)
{
  *a += b[1];
  return 0;
}

int vmsub(char *a, char *b)
{
  *a -= b[1];
  return 0;
}

int vmmul(char *a, char *b)
{
  *a *= b[1];
  return 0;
}

int vmdiv(char *a, char *b)
{
  *a /= b[1];
  return 0;
}

int vmmod(char *a, char *b)
{
  *a %= b[1];
  return 0;
}

int vmshiftl(char *a, char *b)
{
  *a <<= b[1];
  return 0;
}

int vmshiftr(char *a, char *b)
{
  *a >>= b[1];
  return 0;
}

int vmxor(char *a, char *b)
{
  *a ^= b[1];
  return 0;
}

int vmor(char *a, char *b)
{
  *a |= b[1];
  return 0;
}

int vmand(char *a, char *b)
{
  *a &= b[1];
  return 0;
}

int vmnot(char *a, char *b)
{
  (void *)b;
  *a = !*a;
  return 0;
}

int vminv(char *a, char *b)
{
  (void *)b;
  *a = ~*a;
  return 0;
}
