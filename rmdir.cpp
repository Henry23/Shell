#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv []) {
	if (rmdir(argv[0]) == 0)
	return 0;
}