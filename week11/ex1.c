#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
	char* s = "This is a nice day";
	struct stat st;
	int file = open("ex1.txt", O_RDWR, 0600);
	lseek(file, strlen(s), SEEK_SET);
	fstat(file, &st);
	write(file, "", 1);
	char* dest = mmap(NULL, strlen(s), PROT_READ|PROT_WRITE, MAP_SHARED, file, 0);
	memcpy(dest, s, strlen(s));

	return 0;
}
