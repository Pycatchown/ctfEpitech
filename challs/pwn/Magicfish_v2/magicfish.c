#include <stdio.h>
#include <stdlib.h>

void main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
    char buf[64];
    while(1) {
        fgets(buf, 63, stdin);
        printf(buf);
    }
}