#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char s[10];
    while (1) {
        printf("> ");
        scanf("%s", s);
        system(s);
    }
}
