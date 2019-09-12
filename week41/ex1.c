#include <stdio.h>
#include <zconf.h>

int main() {
    int n = 10;
    int pid;
    pid = getpid();
    fork();
    if (pid < getpid()) {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
    else {
        printf("Hello from parent [%d - %d]\n", pid, n);
    }
    return 0;
}

/* output
Hello from parent [12495 - 10]
Hello from child [12496 - 10]
Hello from parent [12497 - 10]
Hello from child [12498 - 10]
Hello from parent [12499 - 10]
Hello from child [12500 - 10]
Hello from parent [12501 - 10]
Hello from child [12502 - 10]
Hello from parent [12503 - 10]
Hello from child [12504 - 10]
Hello from parent [12505 - 10]
Hello from child [12506 - 10]
Hello from parent [12507 - 10]
Hello from child [12508 - 10]
Hello from parent [12509 - 10]
Hello from child [12510 - 10]
Hello from parent [12511 - 10]
Hello from child [12513 - 10]
Hello from parent [12514 - 10]
Hello from child [12515 - 10] 

it is a tree, what can I say more?*/

