//gcc -fno-stack-protector -z execstack -o babysMakeTheirOwnCoffe babysMakeTheirOwnCoffe.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c0ff3_f4ct0ry[0x100];
    char buffer[123];

    puts("Oh is that so ? Since you decide to be a very bad baby, I hid the coffe in our beloved neighbor's house.");
    puts("No more coffe for you there.");
    puts("*Goes back to the bedroom, leaving the coffe factory with no oversight*");
    printf("*The password to the machines is written on a piece of paper just beside: %p*\n", c0ff3_f4ct0ry);

    gets(buffer);
}