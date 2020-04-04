// gcc -m32 babysDontDrinkCoffe.c -o babysDontDrinkCoffe

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void I_l1k3_my_c0ffe(void)
{
    system("/bin/sh");
}

int main(void)
{
    int c0ff3 = 0;
    short pl4t3 = 2;
    char f0rk = 5;
    char t4bl3[30] = "This an awesome table!";
    int br00m = 0xdeadbeef;
    char buffer[124];

    gets(buffer);

    if (strcmp(t4bl3, "This an awesome table!")) {
        puts("You made a mess again!");
        return (0);
    }
    if (pl4t3 == 2 && f0rk == 5 && br00m == 0xdeadbeef && c0ff3 == 0xc0ffe)
        I_l1k3_my_c0ffe();
    else
        puts("You made a mess again!");

    return (0);
}