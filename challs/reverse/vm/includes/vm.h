#ifndef VM_H_
# define VM_H_

# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

typedef struct instruction_s { 
  int (*function)(char *, char *);
  uint8_t nb_params;
} instruction_t;

/* FUNCTIONS */
int vmexit(char *, char *);
int vmprint(char *, char *);
int vmcheck(char *, char *);

/* OPERATORS */
int vmadd(char *, char *);
int vmsub(char *, char *);
int vmmul(char *, char *);
int vmdiv(char *, char *);
int vmmod(char *, char *);
int vmshiftl(char *, char *);
int vmshiftr(char *, char *);
int vmxor(char *, char *);
int vmor(char *, char *);
int vmand(char *, char *);
int vmnot(char *, char *);
int vminv(char *, char *);



#endif /* VM_H_ */
