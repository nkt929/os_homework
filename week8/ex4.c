#include <stdlib.h>


int main() {
  struct rusage use;
  for (int i = 0; i < 10; i++) {
    int * p = (int*)malloc(1024*1024*10);
    memset(p, 0, 1024*1024*10);
    getrusage(RUSAGE_SELF,&use);
    printf("usage = %ld\n",use.ru_maxrss);
    sleep(1);
  }

  return 0;
}
