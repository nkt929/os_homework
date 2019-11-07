#include <stdio.h>

int main(int argc, char **argv) {
    int c;
    int flag = 0;

    argc--;
    argv++;

    if (argc > 0 &&
        argv[0][0] == '-' &&
        argv[0][1] == 'a' &&
        argv[0][2] == '\0') {

        argc--;
        argv++;
        flag = 1;
    }

    FILE *f[argc];

    for (int i = 0; i < argc; i++)
        f[i] = fopen(argv[i], flag ? "a" : "w");

    while ((c = fgetc(stdin)) != EOF) {
        fputc(c, stdout);
        for (int i = 0; i < argc; i++)
            fputc(c, f[i]);
    }

    for (int i = 0; i < argc; i++)
        fclose(f[i]);

    return 0;
}