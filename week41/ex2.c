#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
//pstree $! in bash for tree of processes
int main() {
    for (int i = 0; i < 4; i++) {
        fork();
        sleep(5);
    }
    return 0;
}
