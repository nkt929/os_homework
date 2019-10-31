#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(){
    char *filename = "ex1.txt";
    char *text = "This is a nice day";
    int fd = open(filename, O_RDWR);
    struct stat file_stat;
    int size;
    char *addr;
    
    fstat(fd, &file_stat);
    size = file_stat.st_size;
    addr = mmap(NULL, strlen(text), PROT_WRITE|PROT_READ, MAP_SHARED, fd, 0);
    
    for (int i=0; i < strlen(text); i++) {
        fd[i] = text[i];
    }
    
    fstat(fd, &file_stat);
    size = file_stat.st_size;
    mmap(addr, size);
    close(fd);
    
    return 0;
}