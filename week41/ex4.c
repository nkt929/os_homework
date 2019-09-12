#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char s[10];
    printf("> ");
    scanf("%s[^\n]", s);
    while (1) {
        printf("> ");
        system(s);
        scanf("%s[^\n]", s);
    }
}
