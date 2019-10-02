#include <stdlib.h>
#include <memory.h>
#include <malloc/malloc.h>

void *newrealloc(void *ptr, size_t s)
{
    void * newp;
    if (s == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        newp = malloc(s);
    } else {
        if (malloc_size(ptr) < s) {
            newp = malloc(s);
            memcpy(newp, ptr, malloc_size(ptr));
            free(ptr);
        } else {
            newp = ptr;
        }
    }
    return newp;
}

int main() {
    int n = 10;
    int *ar = (int *) malloc(sizeof(int));
    for (int i = 0; i < n; i++) {
        ar = (int *) newrealloc(ar, sizeof(int) * (i + 1));
        ar[i] = i;
        for (int j = 0; j <= i; j++) {
            printf("%d ", ar[j]);
        }
        printf ("\n");
    }
    free(ar);
    return 0;
}
